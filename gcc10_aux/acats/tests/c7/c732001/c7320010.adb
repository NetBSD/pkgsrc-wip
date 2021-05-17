
package body C7320010 is

   pragma Assertion_Policy (Check);

   function Init return T_Ancestor is
   begin

      return (A => 1);

   end Init;

   procedure Set (Obj : out T_Ancestor; Val : in Integer) is
   begin

      Obj.A := Val;

   end Set;

   procedure Inc (Obj : in out T_Ancestor) is
   begin

      Obj.A := Obj.A + 1;

   end Inc;

end C7320010;

