#include "../include/big_int.hpp"

#include<sstream>
#include<cmath>
#include<algorithm>
#include<iomanip>

namespace la {
   
   BigInt::BigInt() { _negative = false; }

   BigInt::BigInt(const std::string& _val) : BigInt() {
      if(_val.empty()) return;

      if(_val[0] == '-')
         _negative = true;

      for (int i = _val.size(); i > 0; i -= _digit)
         _resource.push_back(std::abs(atoi(_val.substr(std::max(0, i - _digit), std::min(i, 9)).c_str())));

      _remove_zeros();
   }

   BigInt::~BigInt() {}

   // Private Methods

   void BigInt::_remove_zeros() {
      while(!_resource.empty() && _resource.back() == 0) _resource.pop_back();

      if(_resource.empty()) _negative = false;
   }

   void BigInt::_shift(size_t count) {
      for(int i = 0; i < count; i++)
         _resource.push_front(0);
   }

   // Public methods

   BigInt BigInt::abs() const {
      BigInt result = *this;
      result._negative = false;
      return result;
   }

   // Comparision operators

   bool operator==(const BigInt& _First, const BigInt& _Second) {
      if(_First._negative != _Second._negative)
         return false;

      return _First._resource == _Second._resource;
   }

   bool operator!=(const BigInt& _First, const BigInt& _Second) {
      return !(_First == _Second);
   }

   bool operator<(const BigInt& _First, const BigInt& _Second) {
      if(_First._negative != _Second._negative)    // We can compare numbers with not equal sign
         return _First._negative;

      if(_First._resource.size() != _Second._resource.size()) {          // We can compare numbers with not equal size
         bool _abs_size_bigger = _First._resource.size() > _Second._resource.size();
         return _First._negative ? _abs_size_bigger : !_abs_size_bigger;
      }

      bool _abs_bigger = false;
      bool _is_eq = true;

      // Comparing absolute of numbers
      for(std::list<int>::const_reverse_iterator _f = _First._resource.rbegin(), _s = _Second._resource.rbegin(); _f != _First._resource.rend(); _f++, _s++)             
         if(*_f != *_s) {
            _abs_bigger = *_f > *_s;
            _is_eq = false;
            break;
         }

      if(_is_eq) return false;   

      return _First._negative ? _abs_bigger : !_abs_bigger;
   }

   bool operator>(const BigInt& _First, const BigInt& _Second) {
      return _Second < _First;
   }

   bool operator<=(const BigInt& _First, const BigInt& _Second) {
      if(_First._negative != _Second._negative)    // We can compare numbers with not equal sign
         return _First._negative;

      if(_First._resource.size() != _Second._resource.size()) {          // We can compare numbers with not equal size
         bool _abs_size_bigger = _First._resource.size() > _Second._resource.size();
         return _First._negative ? _abs_size_bigger : !_abs_size_bigger;
      }

      bool _abs_bigger = false;
      bool _is_eq = true;

      // Comparing absolute of numbers
      for(std::list<int>::const_reverse_iterator _f = _First._resource.rbegin(), _s = _Second._resource.rbegin(); _f != _First._resource.rend(); _f++, _s++)             
         if(*_f != *_s) {
            _abs_bigger = *_f > *_s;
            _is_eq = false;
            break;
         }

      if(_is_eq) return true;   

      return _First._negative ? _abs_bigger : !_abs_bigger;
   }

   inline bool operator>=(const BigInt& _First, const BigInt& _Second) {
      return _Second <= _First;
   }

#if __cplusplus >= 202000L
   int operator<=>(const BigInt& _First, const BigInt& _Second) {
      if(_First._negative != _Second._negative)    // We can compare numbers with not equal sign
         return _First._negative ? -1 : 1;

      if(_First._resource.size() != _Second._resource.size()) {          // We can compare numbers with not equal size
         int _abs_size_bigger = _First._resource.size() > _Second._resource.size() ? 1 : -1;
         return _First._negative ? -_abs_size_bigger : _abs_size_bigger;
      }

      bool _abs_bigger = false;
      bool _is_eq = true;

      // Comparing absolute of numbers
      for(std::list<int>::reverse_iterator _f = _First._resource.rbegin(), _s = _Second._resource.rbegin(); _f != _First._resource.rend(); _f++, _s++)             
         if(*_f != *_s) {
            _abs_bigger = *_f > *_s;
            _is_eq = false;
            break;
         }

      if(_is_eq) return 0;   

      return _First._negative ? -_abs_bigger : _abs_bigger;
   }
#endif

   // Arithmetic operators

   // Unary operators

   BigInt operator+(const BigInt& _Val) {
      return static_cast<BigInt>(_Val);
   }

   BigInt operator-(const BigInt& _Val) {
      BigInt result(_Val);
      result._negative = !result._negative;
      return result;
   }

   BigInt operator++(BigInt& _Val, int) {
      BigInt _result(_Val);
      _Val += 1;
      return _result;
   }

   BigInt operator--(BigInt& _Val, int) {
      BigInt _result(_Val);
      _Val -= 1;
      return _result;
   }

   BigInt& operator++(BigInt& _Val) {
      return _Val += 1;
   }

   BigInt& operator--(BigInt& _Val) {
      return _Val -= 1;
   }

   // Binary operators

   BigInt operator+(const BigInt& _First, const BigInt& _Second) {
      if(_First._negative != _Second._negative) 
         return _First - (-_Second);

      BigInt result;

      result._resource.push_back(0);
      for(std::list<int>::const_iterator _f = _First._resource.begin(), _s = _Second._resource.begin();
            _f != _First._resource.end() || _s != _Second._resource.end();) {

         long long buff;
         if(_f == _First._resource.end()) {
            buff = static_cast<long long>(result._resource.back()) + *_s;
            ++_s;
         }
         else if(_s == _Second._resource.end()) {
            buff = static_cast<long long>(result._resource.back()) + *_f;
            ++_f;
         }
         else {
            buff = static_cast<long long>(result._resource.back()) + *_f + *_s;
            ++_f;
            ++_s;
         }

         result._resource.back() =  static_cast<int>(buff % BigInt::_base);
         result._resource.push_back(static_cast<int>(buff / BigInt::_base));

      }

      result._remove_zeros();

      return result;
   }

   BigInt& operator+=(BigInt& _First, const BigInt& _Second) {
      _First = _First + _Second;
      return _First;
   }

   BigInt operator-(const BigInt& _First, const BigInt& _Second) {
      if(_First._negative != _Second._negative) // If operands has same signs
         return _First + (-_Second);

      if(_First.abs() < _Second.abs()) // If absolute of first operand < absolute of second operand
         return -(_Second - _First);
      
      BigInt result = _First;
      
      std::list<int>::iterator _r = result._resource.begin();
      for(std::list<int>::const_iterator _s = _Second._resource.begin(); _s != _Second._resource.end(); ++_r, ++_s) {
         *_r -= *_s;

         for(std::list<int>::iterator _br(_r); _br != result._resource.end(); ++_br) {
            if(*_br >= 0) break;

            *_br += BigInt::_base;
            ++_br;
            (*_br)--;
            --_br;

         }
      }

      result._remove_zeros();
      return result;
   }

   BigInt& operator-=(BigInt& _First, const BigInt& _Second) {
      _First = _First - _Second;
      return _First;
   }

   BigInt operator*(const BigInt& _First, const BigInt& _Second) {
      BigInt result = 0;

      int i = 1;
      for(auto _s_el : _Second._resource) {
         BigInt buff;
         buff._resource.resize(i, 0);
         
         for(auto _f_el : _First._resource) {
            long long number = static_cast<long long>(buff._resource.back()) + static_cast<long long>(_f_el) * _s_el;

            buff._resource.back() = static_cast<int>(number % BigInt::_base);
            buff._resource.push_back(static_cast<int>(number / BigInt::_base));
         }

         result += buff;
         i++;
      }

      result._negative = _First._negative != _Second._negative;
      return result;
   }

   BigInt& operator*=(BigInt& _First, const BigInt& _Second) {
      _First = _First * _Second;
      return _First;
   }

   int findRes(const BigInt& _First, const BigInt& _Second, int _base) {
      size_t l = 0, r = _base - 1;

      while(l != r) {
         size_t m = (l + r) >> 1;

         if(_Second * m >= _First) r = m;
         else l = m + 1;
      }

      if(_Second * l > _First) l--;

      return l;
   }

   BigInt operator/(const BigInt& _First, const BigInt& _Second) {
      if(_Second._resource.empty()) 
         throw std::invalid_argument("cannot be divided by zero");

      if(_First < _Second) return 0;

      BigInt result, current(_First);

      for(long long i = static_cast<long long>(_First._resource.size()) - 1; i >= 0; i--) {
         BigInt buffer(_Second);
         buffer._shift(i);

         int r = findRes(current, buffer, BigInt::_base);
         current -= buffer * r;
         result._shift(1);
         result += r;
      }

      result._negative = _First._negative != _Second._negative;

      return result;
   }

   BigInt& operator/=(BigInt& _First, const BigInt& _Second) {
      _First = _First / _Second;
      return _First;
   }

   BigInt operator%(const BigInt& _First, const BigInt& _Second) {
      if(_Second._resource.empty()) 
         throw std::invalid_argument("cannot be divided by zero");

      BigInt current(_First);

      for(long long i = static_cast<long long>(_First._resource.size()) - 1; i >= 0; i--) {
         BigInt buffer(_Second);
         buffer._shift(i);

         int r = findRes(current, buffer, _First._base);
         current -= buffer * r;
      }

      return current;
   }

   BigInt& operator%=(BigInt& _First, const BigInt& _Second) {
      _First = _First % _Second;
      return _First;
   }

   // Cast operators

   BigInt::operator std::string() const {
      std::stringstream sstream;
      sstream << *this;
      return sstream.str();
   }

   // Stream operations

   // Input stream
   std::istream& operator>>(std::istream& in, BigInt& _Val) {
      std::string buff;
      in >> buff;
      _Val = BigInt(buff);
      return in;
   }

   // Output stream
   std::ostream& operator<<(std::ostream& out, const BigInt& _Val) {
      if(_Val._resource.empty()) {  // If number is empty
         out << '0';
         return out;
      }


      if(_Val._negative) out << '-';

      out << _Val._resource.back();
      char filling = out.fill('0');

      std::list<int>::const_reverse_iterator _iter = _Val._resource.rbegin();
      for (++_iter; _iter != _Val._resource.rend(); ++_iter) 
         out << std::setw(BigInt::_digit) << *_iter;
      
      out.fill(filling);   // returning filling to default

      return out;
   }

} // namespace la
