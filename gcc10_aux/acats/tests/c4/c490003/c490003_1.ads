

     --==================================================================--


with Ada.Numerics;
package C490003_1 is

   Zero       : constant := 0.0;
   Pi         : constant := Ada.Numerics.Pi;

   Two_Pi     : constant := 2.0 * Pi;
   Half_Pi    : constant := Pi/2.0;

   Quarter    : constant := 90.0;
   Half       : constant := 180.0;
   Full       : constant := 360.0;

   Deg_To_Rad : constant := Half_Pi/90;
   Rad_To_Deg : constant := 1.0/Deg_To_Rad;
   
end C490003_1;
