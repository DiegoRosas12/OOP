#include "image.h"


Image::Image() {
    m_width = 0;
    m_height = 0;
    m_data = nullptr;
}

Image::Image( int width, int height ) : Image() {
    set(width, height);
}

Image::Image( const std::string filename ) : Image() {
    load(filename);
}

Image::Image( const Image& cp ) : Image() {
    copy(cp);
}

Image::~Image() {
    clear();
}
void Image::copy(const Image& cp){
    clear();

    m_height = cp.m_height;
    m_width = cp.m_height;
    
    if ( m_data != nullptr ) {
        for ( int i=0; i<m_width*m_height; i++ ) {
            m_data[i] = cp.m_data[i];
        }
    }

}

Image Image::copy() const {
    Image I;
    I.copy(*this);
    return I;
}

bool Image::clear() {
    if ( m_data != nullptr ) {
        delete [] m_data;

        m_width = 0;
        m_height = 0;
        m_data = nullptr;
        return true;
    }

    return false;
}

bool Image::set( int width, int height ) {

    if ( width < 1 || height < 1 ) return false;

    clear();

    m_width = width;
    m_height = height;
    m_data = new Color[width*height];

    // Que valor tienen los píxeles?

    return true;
}

bool Image::load( const std::string filename ) {
    bool good;

    // trata de abrir un PPM
    good = load_ppm(filename);
    if ( good ) return true;

    // trata de abrir un PNG
    good = load_png(filename);
    if ( good ) return true;

    return false;
}


bool Image::save( const std::string filename, Format imgformat ) const {

    switch ( imgformat ) {
        case Format::PPM:
            return save_ppm(filename);
        case Format::PNG:
            return save_png(filename);
    }

    return false;
}

Color Image::getpixel( int x, int y ) const {
    // exception
    if ( x < 0 || y < 0 || x >= m_width || y >= m_height ) {
        return Color(0,0,0,0);
    }

    return m_data[index(x,y)];
}

bool Image::setpixel( int x, int y, const Color color ) {
    //exception
    if ( x < 0 || y < 0 || x >= m_width || y >= m_height ) {
        return false;
    }

    m_data[index(x,y)] = color;
    return true;
}

bool Image::setpixel( int x, int y, const Color& color ) {
    //exception
    if ( x < 0 || y < 0 || x >= m_width || y >= m_height ) {
        return false;
    }

    m_data[index(x,y)] = color;
    return true;
}

int Image::width() const {
    return m_width;
}

int Image::height() const {
    return m_height;
}
Image& Image::operator=(const Image& im){
    copy(im);
    return *this;
}
Color& Image::operator()(int x, int y){
    return m_data[index(x,y)];

}
Color& Image::at(int x, int y){
    return m_data[index(x,y)];
}
bool Image::operator==(const Image& im){
    //const double delta = 0.000001;

    if ( m_height != im.m_height ) return false;
    if ( m_width != im.m_width ) return false;

        // la siguiente comparación no funciona bien con flotantes, ya que
        // algunos números no se pueden representar y las operaciones con
        // flotantes producen resultados con cierta inexactitud.
    for(int i; i<(m_height*m_width);i++)
        if ( m_data[i] != im.m_data[i] ) return false;


    return true;
}
bool Image::operator!=(const Image& im){
    return !operator==(im);
}

int Image::index( int x, int y ) const {
    return (m_width*y + x);
}

bool Image::load_ppm( const std::string filename ) {
    std::ifstream fs;
    std::string ppmid;
    int width;
    int height;
    int level;
    bool bad = false;

    fs.open(filename);

    if ( !fs.is_open() ) return false;

    fs >> ppmid;
    fs >> width;
    fs >> height;
    fs >> level;

    // comprobaciones
    if ( fs.eof() ) bad = true;
    if ( ppmid != "P3" ) bad = true;
    if ( width < 1 ) bad = true;
    if ( height < 1 ) bad = true;
    if ( level < 1 || level > 255 ) bad = true;

    if ( bad ) {
        fs.close();
        return false;
    }

    set(width, height);

    int red;
    int green;
    int blue;
    for ( int i=0; i<width*height; i++ ) {
        fs >> red;
        fs >> green;
        fs >> blue;

        if ( fs.eof() ) {
            bad = true;
            break;
        }

        m_data[i] = Color(red, green, blue);
    }

    fs.close();

    if ( bad ) return false;
    return true;
}

bool Image::save_ppm( const std::string filename ) const {
    std::ofstream fs;

    fs.open(filename);

    if ( !fs.is_open() ) return false;

    // se escribe el identificador
    fs << "P3" << std::endl;

    // se escribe el ancho de la imagen en píxeles
    fs << m_width << std::endl;

    // se escribe el alto de la imagen en píxeles
    fs << m_height << std::endl;

    // se escribe el nivel de intensidad máximo
    fs << 255 << std::endl;

    // se escriben los datos RGB
    for ( int i=0; i<m_width*m_height; i++ ) {
        // se requiere un casting int() porque queremos imprimir el número que
        // representa cada canal, y no un caracter ASCII.
        fs << int(m_data[i].r) << " ";
        fs << int(m_data[i].g) << " ";
        fs << int(m_data[i].b) << std::endl;
    }

    fs.close();

    return true;
}

bool Image::load_png( const std::string filename ) {
    unsigned int width, height, error;
    std::vector<unsigned char> raw;

    error = lodepng::decode(raw, width, height, filename.c_str());
    if ( error ) return false;

    set(width, height);

    int red, green, blue, alpha;
    for ( int i=0; i<int(width*height); i++ ) {
        red   = raw[4*i+0];
        green = raw[4*i+1];
        blue  = raw[4*i+2];
        alpha = raw[4*i+3];

        m_data[i] = Color(red, green, blue, alpha);
    }

    return true;
}

bool Image::save_png( const std::string filename ) const {
    std::vector<unsigned char> raw;
    unsigned int error;

    raw.resize(4*m_width*m_height);

    for ( int i=0; i<m_width*m_height; i++ ) {
        raw[4*i+0] = m_data[i].r;
        raw[4*i+1] = m_data[i].g;
        raw[4*i+2] = m_data[i].b;
        raw[4*i+3] = m_data[i].a;
    }

    error = lodepng::encode(filename.c_str(), raw, m_width, m_height);

    if ( error ) return false;
    return true;
}

