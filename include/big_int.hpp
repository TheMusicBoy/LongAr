#ifndef _BIG_INT_
#define _BIG_INT_

#include"values.hpp"

#include<stdexcept>
#include<type_traits>

#include<list>
#include<string>

#include<istream>
#include<ostream>

namespace bi {
   
   
   class BIG_INT_API BigInt {
   private:
      static const int _base = 1000000000;
      static const int _digit = 9;

      std::list<int> _resource;
      bool _negative;

      void _remove_zeros();
      void _shift(size_t count);


   public:
      BigInt();
      BigInt(const std::string& _Val);
      template<typename _Ty> BigInt(const _Ty& _Val);

      BigInt(const BigInt&) = default;
      BigInt(BigInt&&) = default;
      
      ~BigInt() = default;

      // Some methods
      BigInt abs() const;

      BigInt& operator=(const BigInt&) = default;
      BigInt& operator=(BigInt&&) = default;

      // Comparision operators
      friend bool operator==(const BigInt&, const BigInt&);
      friend bool operator!=(const BigInt&, const BigInt&);
      friend bool operator<(const BigInt&, const BigInt&);
      friend bool operator<=(const BigInt&, const BigInt&);
      friend bool operator>(const BigInt&, const BigInt&);
      friend bool operator>=(const BigInt&, const BigInt&);

   #if __cplusplus >= 202000L
      friend int operator<=>(const BigInt& _First, const BigInt& _Second);
   #endif


      // Arithmetic operators

      //Unary operators
      friend BigInt operator+(const BigInt&);
      friend BigInt operator++(BigInt&, int);
      friend BigInt& operator++(BigInt&);

      friend BigInt operator-(const BigInt& );
      friend BigInt operator--(BigInt&, int);
      friend BigInt& operator--(BigInt&);

      //Binary operators
      friend BigInt operator+(const BigInt&, const BigInt&);
      friend BigInt operator-(const BigInt&, const BigInt&);
      friend BigInt operator*(const BigInt&, const BigInt&);
      friend BigInt operator/(const BigInt&, const BigInt&);
      friend BigInt operator%(const BigInt&, const BigInt&);

      friend BigInt& operator+=(BigInt&, const BigInt&);
      friend BigInt& operator-=(BigInt&, const BigInt&);
      friend BigInt& operator*=(BigInt&, const BigInt&);
      friend BigInt& operator/=(BigInt&, const BigInt&);
      friend BigInt& operator%=(BigInt&, const BigInt&);

      
      // Cast operators
      template<typename _Ty> LA_NODISCARD explicit operator _Ty() const;

      operator std::string() const;


      // Stream operators
      friend std::istream& operator>>(std::istream& in, BigInt& _Val);
      friend std::ostream& operator<<(std::ostream& out, const BigInt& _Val);

   }; // class num

   // Template constructor
   BIG_INT_API template<typename _Ty> BigInt::BigInt(const _Ty& _Val) : BigInt() {
      static_assert(std::is_convertible<_Ty, long long>::value, "This type is't convertable to BigInt");

      _Ty val = _Val;

      if(val < 0) {
         _negative = true;
         val = -val;
      }

      while(val > 0) {
         _resource.push_back(val % _base);
         val /= _base;
      }
   }

   // Template cast operator
   BIG_INT_API template<typename _Ty> LA_NODISCARD BigInt::operator _Ty() const {
      _Ty result     = static_cast<_Ty>(0);
      _Ty _some_base = static_cast<_Ty>(1);

      for(auto el : _resource) {
         result += static_cast<_Ty>(el) * _some_base;
         _some_base = _some_base * static_cast<_Ty>(_base);
      }

      if(_negative) result = -result;

      return result;
   }
   
} // namespace la

#endif