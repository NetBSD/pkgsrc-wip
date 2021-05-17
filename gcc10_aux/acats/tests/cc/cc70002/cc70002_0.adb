

     --==================================================================--


package body CC70002_0 is

   -- The implementation of Power is purely artificial; the validity of its
   -- implementation in the context of the abstraction is irrelevant to the
   -- feature being tested.

   function Power (Left : Group_Type; Right : Integer) return Group_Type is
      Result : Group_Type := Identity;
   begin
      Result := Operation (Result, Left);  -- All this really does is add
      return Result;                       -- one to each matrix element.
   end Power;

end CC70002_0;
