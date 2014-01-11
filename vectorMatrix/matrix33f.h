#ifndef MATRIX33F_H
#define MATRIX33F_H

#include <iostream>
#include "vec3f.h"
#include "vec2f.h"

class Matrix33f
{
protected:
        float m_data[3][3];

public:
        /**
         * @brief Matrix33f
         */
        Matrix33f();

        /**
         * @brief Matrix33f
         * @param mat
         */
        Matrix33f(const Matrix33f & mat);

        /**
         * @brief Matrix33f (vecs en ligne)
         * @param u0,u1,u2
         */
        Matrix33f(const Vec3f & u0,const Vec3f & u1,const Vec3f & u2);

        /**
         * @brief Matrix33f
         * @param m1,m2,m3,m4,m5,m6,m7,m8,m9
         */
        Matrix33f(float m1,float m2,float m3,float m4,float m5,float m6,float m7,float m8, float m9);

        /**
         * @brief operator()
         * @param i,j
         */
        float & operator()(int i, int j);

        /**
         * @brief operator()
         * @param i,j
         */
        const float & operator()(int i, int j) const;

        /**
         * @brief operator[]
         * @param i,j
         */
        float * operator[](int i);

        /**
         * @brief setTranslation
         * @param x,y
         */
        void setTranslation(float x, float y);

        /**
         * @brief setRotation
         * @param angle
         */
        void setRotation(float angle);

        /**
         * @brief setScaling
         * @param sx,sy
         */
        void setScaling(float sx, float sy);

        /**
         * @brief setIdentity
         * @param sx,sy
         */
        void setIdentity();

        /**
         * @brief translate
         * @param x,y
         */
        void translate(float x, float y);

        /**
		 * @brief rotate around center of primitive
         * @param angle
         */
        void rotate(float angle);

		/**
		 * @brief rotate around center
		 * @param angle
		 * @param cx  x center
		 * @param cy  y center
		 */
		void rotate(float angle, const Vec2f& center);

        /**
         * @brief scale
         * @param sx,sy
         */
        void scale(float sx, float sy);

		/**
		 * @brief scale around center
		 * @param sx,sy
		 * @param cx  x center
		 * @param cy  y center
		 */
		void scale(float sx, float sy, const Vec2f& center);

        /**
         * declare flow operators as friend
         */
        friend std::ostream& operator<<(std::ostream& out, const Matrix33f& mat) ;
        friend std::istream& operator>>(std::istream& in, Matrix33f& mat) ;

        /**
         * @brief operator * (mat*mat)
         * @param mat
         */
		Matrix33f operator*(const Matrix33f & mat) const;

        /**
         * @brief operator *= (mat*mat)
         * @param mat
         */
		Matrix33f& operator*=(const Matrix33f & mat);

        /**
         * @brief inverse
         */
		Matrix33f inverse() const;

        /**
         * @brief operator * (mat*vec)
         * @param u
         */
		Vec3f operator*(const Vec3f & u) const;

		/**
		 * @brief apply Transformation to a 2D vector
		 * @param u vector
		 * @return
		 */
		Vec2f applyTransformation(const Vec2f & u) const;
};

#endif // MATRIX33F_H
