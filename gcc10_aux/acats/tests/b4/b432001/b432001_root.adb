

package body B432001_Root is
   function New_One return Base is
   begin
      return (A => 1, C => 'A');
   end New_One;

   function Factory return Base'Class is
   begin
      return New_One;
   end Factory;

   package body Nested is
      function Wild return Base is
      begin
         return (A => 23, C => 'C');
      end Wild;

      function Wild return Natural is
      begin
         return 2;
      end Wild;

      function Loaded return Base is
      begin
         return New_One;
      end Loaded;

      function Loaded return Unrelated is
      begin
         return (A => 4, B => False, C => '2');
      end Loaded;

      function Val return Integer is
      begin
         return 5;
      end Val;
   end Nested;

end B432001_Root;
