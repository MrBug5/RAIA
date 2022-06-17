#include "../include/util.hpp"

char* readFiles(char* path) {
    // create file object
    FILE* file = fopen(path, "r");
    if (!file) {
        printf("Could not open file: %s\n", path);
        return NULL;
    }

    // get the file size;
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // open the file
    char* buf = (char*) malloc(sizeof(char) * (size + 1));
    if (!buf) {
        printf("Could not allocate memory for the file\n");
        return NULL;
    }
    fread(buf, 1, size, file);
    buf[size] = '\0';
    fclose(file);

    // return the buffer
    return buf;
}

std::ostream& operator << (std::ostream& os, const __xxTPT06__& obj) {
    os << static_cast<std::underlying_type<__xxTPT06__>::type>(obj);
    return os;
}

std::vector<__xxTPT06__> Iden(char* lineBuf) {
    std::vector<__xxTPT06__> types;
    std::string _StrLiBuf(lineBuf);
    std::vector<std::regex> rgxs;
    std::regex rgx1("\\w+[ ]*=[ ]*[a-z|A-Z|0-9|\"|']+");
    rgxs.push_back(rgx1);
    for (int i=0;i<rgxs.size();i++) {
        std::smatch m;
        while (std::regex_search(_StrLiBuf, m, rgxs[i])) {
            if (i == 0) {
                types.push_back(__xxTPT06__::IDENTIFIER);
                types.push_back(__xxTPT06__::OPERATOR);
                types.push_back(__xxTPT06__::LITERAL);
            }
            _StrLiBuf = m.suffix().str();
        }

    }

    return types;
}

char* intToChar(int a) {
    std::stringstream ss;
    ss << a;
    std::string temp_str = ss.str();
    const char* ret = temp_str.c_str();
    return (char*)ret;
}
