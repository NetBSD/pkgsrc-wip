
package body CC60001_2 is -- Switch operations.

   procedure Force_On (It : in out Switch'Class) is
   begin
      if Is_On (It) then
         null; -- Already on, nothing to do.
      else
         Flip (It);
      end if;
   end Force_On;

   procedure Force_Off (It : in out Switch'Class) is
   begin
      if Is_On (It) then
         Flip (It);
      else
         null; -- Already off, nothing to do.
      end if;
   end Force_Off;

end CC60001_2;
