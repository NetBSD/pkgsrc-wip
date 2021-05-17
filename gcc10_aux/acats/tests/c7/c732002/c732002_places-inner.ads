
package C732002_Places.Inner is

   pragma Assertion_Policy (Check);

   type Ring_Pt_Type is new Disc_Pt_Type with private
      with Type_Invariant => Check_Outside (Ring_Pt_Type);

   function Check_Outside (Ring_Pt : Ring_Pt_Type) return Boolean;

   overriding
   procedure Move_In  (Ring_Pt : in out Ring_Pt_Type);

   overriding
   procedure Move_Out (Ring_Pt : in out Ring_Pt_Type);

private

   type Ring_Pt_Type is new Disc_Pt_Type with null record;

   function Check_Outside (Ring_Pt : Ring_Pt_Type) return Boolean is
      (Ring_Pt.X ** 2 + Ring_Pt.Y >= 0.25); -- Note no allowance for inaccuracy

end C732002_Places.Inner;
