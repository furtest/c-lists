#ifndef BASE_CONTAINER_HEADER
#define BASE_CONTAINER_HEADER

// An enum to provide macros like for the types
enum types {INT, FLOAT, DOUBLE, CHAR, LONG};

/// @brief base container 
typedef struct __base_container{
    enum types type;
    union base_container_union{
        int _int;
        float _float;
        double _double;
        char _char;
        long int _long;
    } content; 
} base_container;

#endif