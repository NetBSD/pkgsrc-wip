
package body C732002_Places.Inner is

   pragma Assertion_Policy (Check);

   -- Will move a point at the Init position to inside the inner circle.
   -- Class-wide invariant should be inherited.
   procedure Move_In (Ring_Pt : in out Ring_Pt_Type) is
   begin

      Ring_Pt.X := 0.2 * Ring_Pt.X;
      Ring_Pt.Y := 0.2 * Ring_Pt.Y;

   end Move_In;

   -- Will move a point at the Init position to outside the outer circle (but
   -- still within the enclosing square).
   -- Specific invariant should not be inherited.
   procedure Move_Out (Ring_Pt : in out Ring_Pt_Type) is
   begin

      Ring_Pt.X := 1.8 * Ring_Pt.X;
      Ring_Pt.Y := 1.8 * Ring_Pt.Y;

   end Move_Out;

end C732002_Places.Inner;
