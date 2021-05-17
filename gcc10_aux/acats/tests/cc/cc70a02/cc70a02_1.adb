

     --==================================================================--


package body CC70A02_1 is  -- Mathematical group operations.



   function Power (Left : Group.Group_Type; Right : Integer)
     return Group.Group_Type is
      Result : Group.Group_Type := Group.Identity;
   begin
      for I in 1 .. abs(Right) loop                 -- Repeat group operations
         Result := Group.Operation (Result, Left);  -- the specified number of
      end loop;                                     -- times.

      if Right < 0 then                             -- If specified power is
         return Group.Inverse (Result);             -- negative, return the
      else                                          -- inverse of the result.
         return Result;                             -- If it is zero, return
      end if;                                       -- the identity.
   end Power;


end CC70A02_1;
