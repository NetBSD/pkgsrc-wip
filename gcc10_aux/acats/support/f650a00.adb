
--=======================================================================--

package body F650A00 is

   procedure Set_Alert_Time (A : in out Alert; Time : in Duration) is
   begin
      A.Time := Time;
   end Set_Alert_Time;


   function Alert_Time (A : in Alert) return Duration is
   begin
      return A.Time;
   end Alert_Time;

end F650A00;
