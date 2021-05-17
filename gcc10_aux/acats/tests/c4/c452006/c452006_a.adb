
package body C452006_A is

   function "=" (Left, Right : Lim_Handle) return Boolean is
   begin
      -- Note: Using a membership here on Lim_Handle is illegal by AI12-0328-1,
      -- so we have to introduce an extra type to get at predefined "=" here.
      if Raw_Access(Left) = Raw_Access(Right) then -- Predefined "=".
         return True;
      elsif Raw_Access(Left) = null or else Raw_Access(Right) = null then
         return False;
      else
         return Left.all = Right.all;
      end if;
   end "=";

   function Create (Val : in Natural) return Lim_Handle is
   begin
      return new Data_Type'(Value => Val);
   end Create;

   function "=" (Left, Right : Nonlim_Handle) return Boolean is
   begin
      -- Note: The only way to get at the predefined equality here
      -- without declaring an extra type is to use a membership. This means
      -- that the test is likely to raise Storage_Error rather than a clean
      -- failure if memberships call the wrong "=".
      if Left in Right then -- Really predefined "=".
         return True;
      elsif Left in null or else Right in null then
         return False;
      else
         return Left.all = Right.all;
      end if;
   end "=";

   function Create (Val : in Natural) return Nonlim_Handle is
   begin
      return new Data_Type'(Value => Val);
   end Create;

end C452006_A;
