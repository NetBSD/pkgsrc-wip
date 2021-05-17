
-- No bodies required for BA11010_0.

     --=================================================================--

with BA11010_0;
package BA11010_1 is

   type Parent_Type is range 101 .. 200;

   package BA11010_2 is
      type Inner_Type is range 201 .. 300;
   end BA11010_2;
  
   -- No bodies required for BA11010_2.

   --------------------------------------------------

   package BA11010_3 is new BA11010_0;

   --------------------------------------------------

   package BA11010_4 is
      procedure BA11010_5;
   end BA11010_4;

end BA11010_1;
