
package body C732002_Places is

   pragma Assertion_Policy (Check);

   function Init return Disc_Pt_Type is
   begin

      return (0.5, 0.5);

   end Init;

   -- Will move a point at the Init position to inside the inner circle.
   procedure Move_In (Disc_Pt : in out Disc_Pt_Type) is
   begin

      Disc_Pt.X := 0.1 * Disc_Pt.X;
      Disc_Pt.Y := 0.1 * Disc_Pt.Y;

   end Move_In;

   -- Will move a point at the Init position to outside the outer circle (but
   -- still within the enclosing square).
   procedure Move_Out (Disc_Pt : in out Disc_Pt_Type) is
   begin

      Disc_Pt.X := 1.9 * Disc_Pt.X;
      Disc_Pt.Y := 1.9 * Disc_Pt.Y;

   end Move_Out;

   procedure Negate   (Disc_Pt : in out Disc_Pt_Type) is
   begin

      Disc_Pt.X := - Disc_Pt.X;
      Disc_Pt.Y := - Disc_Pt.Y;

   end Negate;

end C732002_Places;
