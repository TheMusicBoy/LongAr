#include "include/big_int.hpp"
#include <iostream>
#include <cassert>
#include <sstream>

int main() {

   {
      auto test = [](long long val) {
         auto subtest = [](long long val) {
            bi::BigInt a(val);
            assert(static_cast<long long>(a) == static_cast<long long>(val));
            bi::BigInt b(a);
            long long buff(val);
            assert(static_cast<long long>(a) == static_cast<long long>(val));
            assert(static_cast<long long>(b) == static_cast<long long>(buff));
         };

         subtest(val);
         subtest(-val);

         std::cout << "Tested copy constructors with " << val << " - OK" << std::endl;
      };

      test(0);
      test(1);
      test(12345678912);

      std::cout << "------------------------------------------------" << std::endl;
      
   }

   {
      auto test = [](long long val) {
         auto subtest = [](long long val) {
            bi::BigInt a(val);
            assert(static_cast<long long>(a) == static_cast<long long>(val));
            bi::BigInt b = a;
            long long buff = val;
            assert(static_cast<long long>(a) == static_cast<long long>(val));
            assert(static_cast<long long>(b) == static_cast<long long>(buff));
         };

         subtest(val);
         subtest(-val);

         std::cout << "Tested operator = with " << val << " - OK" << std::endl;
      };

      test(0);
      test(1);
      test(12345678912);

      std::cout << "------------------------------------------------" << std::endl;

   }

   {
      auto test = [](long long val) {
         auto subtest = [](long long val) {
            bi::BigInt a(val);
            assert(static_cast<long long>(a) == static_cast<long long>(val));
            bi::BigInt b(std::move(a));
            long long buff(std::move(val));
            assert(static_cast<long long>(a) == static_cast<long long>(0));
            assert(static_cast<long long>(b) == static_cast<long long>(buff));
         };

         subtest(val);
         subtest(-val);

         std::cout << "Tested move constructors with " << val << " - OK" << std::endl;
      };

      test(0);
      test(1);
      test(12345678912);

      std::cout << "------------------------------------------------" << std::endl;

   }

   {
      auto test = [](long long val) {
         auto subtest = [](long long val) {
            bi::BigInt a(val);
            assert(static_cast<long long>(a) == static_cast<long long>(val));
            bi::BigInt b = std::move(a);
            long long buff = std::move(val);
            assert(static_cast<long long>(a) == static_cast<long long>(0));
            assert(static_cast<long long>(b) == static_cast<long long>(buff));
         };

         subtest(val);
         subtest(-val);

         std::cout << "Tested move operator = with " << val << " - OK" << std::endl;
      };

      test(0);
      test(1);
      test(12345678912);

      std::cout << "------------------------------------------------" << std::endl;

   }

   {
      auto test = [](long long val) {
         auto subtest = [](long long val) {
            assert(-bi::BigInt(val) == bi::BigInt(-val));
         };

         subtest(val);
         subtest(-val);

         std::cout << "Tested unary operation - with " << val << " - OK" << std::endl;
      };

      test(0);
      test(1);
      test(12345678912);

      std::cout << "------------------------------------------------" << std::endl;

   }

   {
      auto test = [](long long val) {
         auto subtest = [](long long val) {
            assert(+bi::BigInt(val) == bi::BigInt(+val));
         };

         subtest(val);
         subtest(-val);

         std::cout << "Tested unary operation + with " << val << " - OK" << std::endl;
      };

      test(0);
      test(1);
      test(12345678912);

      std::cout << "------------------------------------------------" << std::endl;

   }

   {
      auto test = [](long long val_a, long long val_b) {
         auto subtest = [](long long val_a, long long val_b) {
            assert((bi::BigInt(val_a) == bi::BigInt(val_b)) == (val_a == val_b));
         };

         subtest(val_a, val_b);
         subtest(val_a, -val_b);
         subtest(-val_a, val_b);
         subtest(-val_a, -val_b);
      };

      auto fulltest = [test](long long val_a, long long val_b) {
         test(val_a, val_b);
         test(val_b, val_a);

         std::cout << "Tested operation == with " << val_a << ' ' << val_b << " - OK" << std::endl;
      };

      fulltest(0, 0);
      fulltest(0, 1);
      fulltest(1, 1);
      fulltest(12345678912, 1234567891);
      fulltest(12345678912, 12345678912);

      std::cout << "------------------------------------------------" << std::endl;


   }

   {
      auto test = [](long long val_a, long long val_b) {
         auto subtest = [](long long val_a, long long val_b) {
            assert((bi::BigInt(val_a) != bi::BigInt(val_b)) == (val_a != val_b));
         };

         subtest(val_a, val_b);
         subtest(val_a, -val_b);
         subtest(-val_a, val_b);
         subtest(-val_a, -val_b);
      };

      auto fulltest = [test](long long val_a, long long val_b) {
         test(val_a, val_b);
         test(val_b, val_a);

         std::cout << "Tested operation != with " << val_a << ' ' << val_b << " - OK" << std::endl;
      };

      fulltest(0, 0);
      fulltest(0, 1);
      fulltest(1, 1);
      fulltest(12345678912, 1234567891);
      fulltest(12345678912, 12345678912);

      std::cout << "------------------------------------------------" << std::endl;

      
   }

   {
      auto test = [](long long val_a, long long val_b) {
         auto subtest = [](long long val_a, long long val_b) {
            assert((bi::BigInt(val_a) < bi::BigInt(val_b)) == (val_a < val_b));
         };

         subtest(val_a, val_b);
         subtest(val_a, -val_b);
         subtest(-val_a, val_b);
         subtest(-val_a, -val_b);
      };

      auto fulltest = [test](long long val_a, long long val_b) {
         test(val_a, val_b);
         test(val_b, val_a);

         std::cout << "Tested operation < with " << val_a << ' ' << val_b << " - OK" << std::endl;
      };

      fulltest(0, 0);
      fulltest(0, 1);
      fulltest(1, 1);
      fulltest(12345678912, 1234567891);
      fulltest(12345678912, 12345678912);

      std::cout << "------------------------------------------------" << std::endl;

      
   }

   {
      auto test = [](long long val_a, long long val_b) {
         auto subtest = [](long long val_a, long long val_b) {
            assert((bi::BigInt(val_a) > bi::BigInt(val_b)) == (val_a > val_b));
         };

         subtest(val_a, val_b);
         subtest(val_a, -val_b);
         subtest(-val_a, val_b);
         subtest(-val_a, -val_b);
      };

      auto fulltest = [test](long long val_a, long long val_b) {
         test(val_a, val_b);
         test(val_b, val_a);

         std::cout << "Tested operation > with " << val_a << ' ' << val_b << " - OK" << std::endl;
      };

      fulltest(0, 0);
      fulltest(0, 1);
      fulltest(1, 1);
      fulltest(12345678912, 1234567891);
      fulltest(12345678912, 12345678912);

      std::cout << "------------------------------------------------" << std::endl;

      
   }

   {
      auto test = [](long long val_a, long long val_b) {
         auto subtest = [](long long val_a, long long val_b) {
            assert((bi::BigInt(val_a) <= bi::BigInt(val_b)) == (val_a <= val_b));
         };

         subtest(val_a, val_b);
         subtest(val_a, -val_b);
         subtest(-val_a, val_b);
         subtest(-val_a, -val_b);
      };

      auto fulltest = [test](long long val_a, long long val_b) {
         test(val_a, val_b);
         test(val_b, val_a);

         std::cout << "Tested operation <= with " << val_a << ' ' << val_b << " - OK" << std::endl;
      };

      fulltest(0, 0);
      fulltest(0, 1);
      fulltest(1, 1);
      fulltest(12345678912, 1234567891);
      fulltest(12345678912, 12345678912);

      std::cout << "------------------------------------------------" << std::endl;

      
   }

   {
      auto test = [](long long val_a, long long val_b) {
         auto subtest = [](long long val_a, long long val_b) {
            assert((bi::BigInt(val_a) >= bi::BigInt(val_b)) == (val_a >= val_b));
         };

         subtest(val_a, val_b);
         subtest(val_a, -val_b);
         subtest(-val_a, val_b);
         subtest(-val_a, -val_b);
      };

      auto fulltest = [test](long long val_a, long long val_b) {
         test(val_a, val_b);
         test(val_b, val_a);

         std::cout << "Tested operation >= with " << val_a << ' ' << val_b << " - OK" << std::endl;
      };

      fulltest(0, 0);
      fulltest(0, 1);
      fulltest(1, 1);
      fulltest(12345678912, 1234567891);
      fulltest(12345678912, 12345678912);

      std::cout << "------------------------------------------------" << std::endl;

      
   }

#if _cplusplus >= 202000L

{
      auto test = [](long long val_a, long long val_b) {
         auto subtest = [](long long val_a, long long val_b) {
            assert((bi::BigInt(val_a) <=> bi::BigInt(val_b)) == (val_a <=> val_b));
         };

         subtest(val_a, val_b);
         subtest(val_a, -val_b);
         subtest(-val_a, val_b);
         subtest(-val_a, -val_b);
      };

      auto fulltest = [test](long long val_a, long long val_b) {
         test(val_a, val_b);
         test(val_b, val_a);

         std::cout << "Tested operation <=> with " << val_a << ' ' << val_b << " - OK" << std::endl;
      };

      fulltest(0, 0);
      fulltest(0, 1);
      fulltest(1, 1);
      fulltest(12345678912, 1234567891);
      fulltest(12345678912, 12345678912);
      
   }

#endif


   {
      auto test = [](long long val) {
         auto subtest = [] (long long val) {
            bi::BigInt buff(val);
            assert(++buff == bi::BigInt(++val));
            assert(buff == bi::BigInt(val));
         };

         subtest(val);
         subtest(-val);

         std::cout << "Tested prefix increment with " << val << " - OK" << std::endl;
         
      };

      test(0);
      test(99999999);
      test(12345678912);

      std::cout << "------------------------------------------------" << std::endl;

   }

   {
      auto test = [](long long val) {
         auto subtest = [] (long long val) {
            bi::BigInt buff(val);
            assert(--buff == bi::BigInt(--val));
            assert(buff == bi::BigInt(val));
         };

         subtest(val);
         subtest(-val);

         std::cout << "Tested prefix decrement with " << val << " - OK" << std::endl;
         
      };

      test(0);
      test(1000000000);
      test(12345678912);

      std::cout << "------------------------------------------------" << std::endl;

   }

   {
      auto test = [](long long val) {
         auto subtest = [] (long long val) {
            bi::BigInt buff(val);
            assert(buff++ == bi::BigInt(val++));
            assert(buff == bi::BigInt(val));
         };

         subtest(val);
         subtest(-val);

         std::cout << "Tested postfix increment with " << val << " - OK" << std::endl;
         
      };

      test(0);
      test(99999999);
      test(12345678912);

      std::cout << "------------------------------------------------" << std::endl;

   }

   {
      auto test = [](long long val) {
         auto subtest = [] (long long val) {
            bi::BigInt buff(val);
            assert(buff-- == bi::BigInt(val--));
            assert(buff == bi::BigInt(val));
         };

         subtest(val);
         subtest(-val);

         std::cout << "Tested postfix decrement with " << val << " - OK" << std::endl;
         
      };

      test(0);
      test(1000000000);
      test(12345678912);

      std::cout << "------------------------------------------------" << std::endl;

   }

   {
      auto test = [] (long long val_a, long long val_b) {
         auto subtest = [] (long long val_a, long long val_b) {
            assert(bi::BigInt(val_a) + bi::BigInt(val_b) == bi::BigInt(val_a + val_b));
         };

         subtest(val_a, val_b);
         subtest(val_a, -val_b);
         subtest(-val_a, val_b);
         subtest(-val_a, -val_b);
      };

      auto fulltest = [test](long long val_a, long long val_b) {
         test(val_a, val_b);
         test(val_b, val_a);

         std::cout << "Tested binary operation + with " << val_a << ' ' << val_b << " - OK" << std::endl;
      };

      fulltest(10, 5);
      fulltest(12345678912, 123456789);
      fulltest(1234567891, 1234567891);

      std::cout << "------------------------------------------------" << std::endl;

   }

   {
      auto test = [] (long long val_a, long long val_b) {
         auto subtest = [] (long long val_a, long long val_b) {
            assert(bi::BigInt(val_a) - bi::BigInt(val_b) == bi::BigInt(val_a - val_b));
         };

         subtest(val_a, val_b);
         subtest(val_a, -val_b);
         subtest(-val_a, val_b);
         subtest(-val_a, -val_b);
      };

      auto fulltest = [test](long long val_a, long long val_b) {
         test(val_a, val_b);
         test(val_b, val_a);

         std::cout << "Tested binary operation - with " << val_a << ' ' << val_b << " - OK" << std::endl;
      };

      fulltest(10, 5);
      fulltest(12345678912, 123456789);
      fulltest(1234567891, 1234567891);

      std::cout << "------------------------------------------------" << std::endl;

   }

   {
      auto test = [] (long long val_a, long long val_b) {
         auto subtest = [] (long long val_a, long long val_b) {
            assert(bi::BigInt(val_a) * bi::BigInt(val_b) == bi::BigInt(val_a * val_b));
         };

         subtest(val_a, val_b);
         subtest(val_a, -val_b);
         subtest(-val_a, val_b);
         subtest(-val_a, -val_b);
      };

      auto fulltest = [test](long long val_a, long long val_b) {
         test(val_a, val_b);
         test(val_b, val_a);

         std::cout << "Tested binary operation * with " << val_a << ' ' << val_b << " - OK" << std::endl;
      };

      fulltest(10, 5);
      fulltest(12345678912, 123456789);
      fulltest(1234567891, 1234567891);

      std::cout << "------------------------------------------------" << std::endl;

   }

   {
      auto test = [] (long long val_a, long long val_b) {
         auto subtest = [] (long long val_a, long long val_b) {
            assert(bi::BigInt(val_a) / bi::BigInt(val_b) == bi::BigInt(val_a / val_b));
         };

         subtest(val_a, val_b);
         subtest(val_a, -val_b);
         subtest(-val_a, val_b);
         subtest(-val_a, -val_b);
      };

      auto fulltest = [test](long long val_a, long long val_b) {
         test(val_a, val_b);
         test(val_b, val_a);

         std::cout << "Tested binary operation / with " << val_a << ' ' << val_b << " - OK" << std::endl;
      };

      fulltest(10, 5);
      fulltest(12345678912, 123456789);
      fulltest(1234567891, 1234567891);

      std::cout << "------------------------------------------------" << std::endl;

   }

   {
      auto test = [] (long long val_a, long long val_b) {
         auto subtest = [] (long long val_a, long long val_b) {
            assert(bi::BigInt(val_a) % bi::BigInt(val_b) == bi::BigInt(val_a % val_b));
         };

         subtest(val_a, val_b);
         subtest(val_a, -val_b);
         subtest(-val_a, val_b);
         subtest(-val_a, -val_b);

      };

      auto fulltest = [test](long long val_a, long long val_b) {
         test(val_a, val_b);
         test(val_b, val_a);

         std::cout << "Tested binary operation % with " << val_a << ' ' << val_b << " - OK" << std::endl;
      };

      fulltest(10, 3);
      fulltest(12345678912, 123);
      fulltest(12345678912, 1234567891);

      std::cout << "------------------------------------------------" << std::endl;

   }

   {
      auto test = [](long long val_a, long long val_b) {
         bi::BigInt a(val_a), b(val_b);

         assert(bi::BigInt(a += b) == bi::BigInt(val_a + val_b));
         assert(a == bi::BigInt(val_a + val_b));

         assert(bi::BigInt(a -= b) == bi::BigInt((val_a + val_b) - val_b));
         assert(a == bi::BigInt((val_a + val_b) - val_b));

         a = val_a; b = val_b;

         assert(bi::BigInt(a *= b) == bi::BigInt(val_a * val_b));
         assert(a == bi::BigInt(val_a * val_b));


         assert(bi::BigInt(a /= b) == bi::BigInt((val_a * val_b) / val_b));
         assert(a == bi::BigInt((val_a * val_b) / val_b));

         a = val_a; b = val_b;

         assert(bi::BigInt(a %= b) == bi::BigInt(val_a % val_b));
         assert(a == bi::BigInt(val_a % val_b));

      };

      auto fulltest = [test](long long val_a, long long val_b) {
         test(val_a, val_b);
         test(val_a, -val_b);
         test(-val_a, val_b);
         test(-val_a, -val_b);

         std::cout << "Tested binary operations (=) with " << val_a << ' ' << val_b << " - OK" << std::endl;
      };

      fulltest(10, 3);

      fulltest(1234567891, 1234567892);
      
      std::cout << "------------------------------------------------" << std::endl;

   }

   {
      auto test = [](long long val){
         assert(static_cast<bool>(bi::BigInt(val)) == static_cast<bool>(val));

         assert(static_cast<signed char>(bi::BigInt(val)) == static_cast<signed char>(val));
         assert(static_cast<unsigned char>(bi::BigInt(val)) == static_cast<unsigned char>(val));

         assert(static_cast<signed short>(bi::BigInt(val)) == static_cast<signed short>(val));
         assert(static_cast<unsigned short>(bi::BigInt(val)) == static_cast<unsigned short>(val));

         assert(static_cast<signed int>(bi::BigInt(val)) == static_cast<signed int>(val));
         assert(static_cast<unsigned int>(bi::BigInt(val)) == static_cast<unsigned int>(val));

         assert(static_cast<signed long>(bi::BigInt(val)) == static_cast<signed long>(val));
         assert(static_cast<unsigned long>(bi::BigInt(val)) == static_cast<unsigned long>(val));

         assert(static_cast<signed long long>(bi::BigInt(val)) == static_cast<signed long long>(val));
         assert(static_cast<unsigned long long>(bi::BigInt(val)) == static_cast<unsigned long long>(val));
      };

      auto fulltest = [test](long long val) {
         test(val);
         test(-val);

         std::cout << "Tested casts with " << val << " - OK" << std::endl;
      };

      fulltest(1234);
      fulltest(1234567912345);

      std::cout << "------------------------------------------------" << std::endl;

   }

   {
      auto test = [](long long val) {
         auto subtest = [](long long val) {
            std::stringstream ss1, ss2;
            bi::BigInt a(val);
            ss1 << val;
            ss2 << a;
            assert(ss1.str() == ss2.str());
         };

         subtest(val);
         subtest(-val);

         std::cout << "Tested stream output with " << val << " - OK" << std::endl;
      };

      test(0);
      test(1);
      test(12345678912);

      std::cout << "------------------------------------------------" << std::endl;
   }

   {
      auto test = [](long long val) {
         auto subtest = [](long long val) {
            std::stringstream ss1, ss2;
            bi::BigInt a;
            long long b;
            ss1 << val;
            ss2 << val;

            ss1 >> a;
            ss2 >> b;
            assert(a == bi::BigInt(b));
         };

         subtest(val);
         subtest(-val);

         std::cout << "Tested stream input with " << val << " - OK" << std::endl;
      };

      test(0);
      test(1);
      test(12345678912);

      std::cout << "------------------------------------------------" << std::endl;
   }

}