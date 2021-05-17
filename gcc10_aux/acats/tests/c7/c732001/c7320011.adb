
with Report;

package body C7320011 is

   pragma Assertion_Policy (Check);

   function Increasing (My_T : in T) return Boolean is
   begin

      return My_T.B > Val(My_T);

   end Increasing;

   function Init return T is
   begin

      return (C7320010.Init with B => 2);

   end Init;

   procedure Set_B (My_T : in out T; Val : in Integer) is
   begin

     My_T.B := Val;

   end Set_B;

   procedure Output (My_T : in T; Label : in String) is
   begin

      Report.Comment ("At " & Label &
                      ", T.A is " & Integer'Image(Val(My_T)) &
                      "; T.B is " & Integer'Image(My_T.B));

   end Output;

end C7320011;

