

package body B432001_B is
   function New_One return Der2 is
   begin
      return (A => 1, C => 'A', B => True);
   end New_One;
end B432001_B;
