#ifndef _VMATH_H_
#define _VMATH_H_

#include <ostream>

const float PI = 3.1415927;

// -- Helper functions -- //
bool  equal_floats(float lhs, float rhs);
float radian_to_degree(float rad);
float degree_to_radian(float deg);

class vec2
{
    public:
                         //  2x1
        float x = 0.0f;  // [ x ]
        float y = 0.0f;  // [ y ]
                         //   v

        // Constructors
        vec2(float _x = 0.0f, float _y = 0.0f);
        vec2(const vec2& _vec);

        // Assignment operators
        vec2& operator  = (const vec2& rhs);
        vec2& operator += (const vec2& rhs);
        vec2& operator -= (const vec2& rhs);
        vec2& operator *= (float rhs);

        // Arithmetic operators
        vec2 operator + (const vec2& rhs) const;
        vec2 operator - (const vec2& rhs) const;

 friend vec2 operator * (const vec2& lhs, float rhs);
 friend vec2 operator * (float lhs, const vec2& rhs);

        // Dot product
        float operator * (const vec2& rhs) const;

        // Member functions
        vec2& normalize ();
        float length    () const;

        bool  parallel  (const vec2& rhs) const;
        bool  orthogonal(const vec2& rhs) const;
        float angle_to  (const vec2& rhs) const;
        vec2  projection(const vec2& rhs) const;

        // --  Std ostream  --  //
 friend std::ostream& operator << (std::ostream& os, vec2 rhs) 
        {
            return os << "[" << rhs.x << " " << rhs.y << "]";
        }
};

class vec3
{
    public:
                         //  3x1
        float x = 0.0f;  // [ x ]
        float y = 0.0f;  // [ y ]
        float z = 0.0f;  // [ z ]
                         //   v

        // Constructors
        vec3(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f);
        vec3(const vec3& _vec);

        // Assignment operators
        vec3& operator  = (const vec3& rhs);
        vec3& operator += (const vec3& rhs);
        vec3& operator -= (const vec3& rhs);
        vec3& operator *= (float rhs);

        // Arithmetic operators
        vec3 operator + (const vec3& rhs) const;
        vec3 operator - (const vec3& rhs) const;

 friend vec3 operator * (const vec3& lhs, float rhs);
 friend vec3 operator * (float lhs, const vec3& rhs);

        // Dot product
        float operator * (const vec3& rhs) const;

        // Member functions
        vec3& normalize ();
        float length    () const;

        bool  parallel  (const vec3& rhs) const;
        bool  orthogonal(const vec3& rhs) const;
        float angle_to  (const vec3& rhs) const;
        vec3  projection(const vec3& rhs) const;
        vec3  cross_product(const vec3& rhs) const;

        // --  Std ostream  --  //
 friend std::ostream& operator << (std::ostream& os, vec3 rhs) 
        {
            return os << "[" << rhs.x << " " << rhs.y << " " << rhs.z << "]";
        }
};

class mat2x2
{
    public:

        float a = 1.0f;  //   2x2 
        float b = 0.0f;  // [ a b ] 
        float c = 0.0f;  // [ c d ] 
        float d = 1.0f;  //   v u

        // Constructors
        mat2x2( float _a = 1.0f, 
                float _b = 0.0f, 
                float _c = 0.0f, 
                float _d = 1.0f );
        mat2x2(const vec2& v, const vec2& u);
        mat2x2(const mat2x2& _matrix);

        // Assignment operators
        mat2x2& operator  = (const mat2x2& rhs);
        mat2x2& operator += (const mat2x2& rhs);
        mat2x2& operator -= (const mat2x2& rhs);

        mat2x2& operator *= (const mat2x2& rhs);
        mat2x2& operator *= (float rhs);

        // Arithmetic operators
        mat2x2 operator + (const mat2x2& rhs) const;
        mat2x2 operator - (const mat2x2& rhs) const;
        mat2x2 operator * (const mat2x2& rhs) const;

        vec2 operator * (const vec2& rhs) const;

 friend mat2x2 operator * (const mat2x2& lsh, float rhs);
 friend mat2x2 operator * (float lhs, const mat2x2& rhs);

        // Member functions
        float  determinant() const;
        mat2x2 inverse()     const;
        mat2x2 transpose()   const;

 friend std::ostream& operator << (std::ostream& os, const mat2x2 rhs)
        {
            return os << "[ " << rhs.a << " " << rhs.b << " "
                      << "| " << rhs.c << " " << rhs.d << " ]";
        }
};


#endif // _VMATH_H_