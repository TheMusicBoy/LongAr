#include "include/big_int.hpp"
#include <iostream>
#include <cassert>
#include <sstream>

int main() {

   {
      bi::BigInt a;
      bi::BigInt b(a);
      assert(a == b);

      a = bi::BigInt(1);
      b = a;
      assert(a == b);
   }

   {
      assert(-bi::BigInt(-1) == bi::BigInt(1));
      assert(-bi::BigInt(1) == bi::BigInt(-1));

      assert(+bi::BigInt(-1) == bi::BigInt(-1));
      assert(+bi::BigInt(1) == bi::BigInt(1));
   }

   {
      assert((bi::BigInt(1) == bi::BigInt(1)) == true);
      assert((bi::BigInt(1) == bi::BigInt(0)) == false);


      assert((bi::BigInt(1) != bi::BigInt(1)) == false);
      assert((bi::BigInt(1) != bi::BigInt(0)) == true);

      
      assert((bi::BigInt(0) < bi::BigInt(1)) == true);
      assert((bi::BigInt(1) < bi::BigInt(1)) == false);
      assert((bi::BigInt(2) < bi::BigInt(1)) == false);


      assert((bi::BigInt(0) > bi::BigInt(1)) == false);
      assert((bi::BigInt(1) > bi::BigInt(1)) == false);
      assert((bi::BigInt(2) > bi::BigInt(1)) == true);


      assert((bi::BigInt(0) <= bi::BigInt(1)) == true);
      assert((bi::BigInt(1) <= bi::BigInt(1)) == true);
      assert((bi::BigInt(2) <= bi::BigInt(1)) == false);


      assert((bi::BigInt(0) >= bi::BigInt(1)) == false);
      assert((bi::BigInt(1) >= bi::BigInt(1)) == true);
      assert((bi::BigInt(2) >= bi::BigInt(1)) == true);

   }

   {
      bi::BigInt a(0);
      assert(a++ == bi::BigInt(0));
      assert(a == bi::BigInt(1));

      assert(a-- == bi::BigInt(1));
      assert(a == bi::BigInt(0));

      assert(a-- == bi::BigInt(0));
      assert(a == bi::BigInt(-1));


      assert(a++ == bi::BigInt(-1));
      assert(a == bi::BigInt(0));
   }

   {
      bi::BigInt a(0);
      assert(++a == bi::BigInt(1));
      assert(a == bi::BigInt(1));

      assert(--a == bi::BigInt(0));
      assert(a == bi::BigInt(0));

      assert(--a == bi::BigInt(-1));
      assert(a == bi::BigInt(-1));


      assert(++a == bi::BigInt(0));
      assert(a == bi::BigInt(0));
   }

   {
      assert(bi::BigInt(9999999999) + bi::BigInt(1) == bi::BigInt(10000000000));
      assert(bi::BigInt(9999999999) - bi::BigInt(-1) == bi::BigInt(10000000000));
      
      assert(bi::BigInt(10000000000) - bi::BigInt(1) == bi::BigInt(9999999999));
      assert(bi::BigInt(10000000000) + bi::BigInt(-1) == bi::BigInt(9999999999));


      assert(bi::BigInt(-1) - bi::BigInt(9999999999) == bi::BigInt(-10000000000));
      assert(bi::BigInt(-1) + bi::BigInt(-9999999999) == bi::BigInt(-10000000000));
      
      assert(bi::BigInt(-10000000000) - bi::BigInt(-1) == bi::BigInt(-9999999999));
      assert(bi::BigInt(-10000000000) + bi::BigInt(1) == bi::BigInt(-9999999999));
   }

   {
      assert(bi::BigInt(1024) * bi::BigInt(1024) == bi::BigInt(1024 * 1024));
      assert(bi::BigInt(1024) * bi::BigInt(-1024) == bi::BigInt(-1024 * 1024));

      assert(bi::BigInt(1024 * 1024) / bi::BigInt(1024) == bi::BigInt(1024));
      assert(bi::BigInt(1024 * 1024) / bi::BigInt(-1024) == bi::BigInt(-1024));
   }

   {
      assert(bi::BigInt(1023 * 1023) % bi::BigInt(1024) == bi::BigInt((1023 * 1023) % 1024));
      assert(bi::BigInt(1023 * 1023) % bi::BigInt(-1024) == bi::BigInt((1023 * 1023) % -1024));
      assert(bi::BigInt(-1023 * 1023) % bi::BigInt(-1024) == bi::BigInt((-1023 * 1023) % 1024));
      assert(bi::BigInt(-1023 * 1023) % bi::BigInt(1024) == bi::BigInt((-1023 * 1023) % 1024));
   }

   {
      bi::BigInt a(10), b(3);

      assert(bi::BigInt(a += b) == bi::BigInt(10 + 3));
      assert(a == bi::BigInt(10 + 3));

      assert(bi::BigInt(a -= b) == bi::BigInt(10));
      assert(a == bi::BigInt(10));


      assert(bi::BigInt(a *= b) == bi::BigInt(10 * 3));
      assert(a == bi::BigInt(10 * 3));


      assert(bi::BigInt(a /= b) == bi::BigInt(10));
      assert(a == bi::BigInt(10));

      assert(bi::BigInt(a %= b) == bi::BigInt(10 % 3));
      assert(a == bi::BigInt(10 % 3));
   }

   {
      std::stringstream ss;
      bi::BigInt a(1202459872345), b;
      ss << a;
      ss >> b;
      assert(a == b);
   }

   {
      std::stringstream ss;
      bi::BigInt a(-1202459872345), b;
      ss << a;
      ss >> b;
      assert(a == b);
   }

   {
      std::stringstream ss;
      bi::BigInt a(0), b;
      ss << a;
      ss >> b;
      assert(a == b);
   }

}