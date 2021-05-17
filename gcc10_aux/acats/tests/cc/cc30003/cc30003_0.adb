
with TCTouch;
package body CC30003_0 is

   procedure Clear (Obj : in out Counted_Type) is
      -- Clear the count of Obj.
   begin
      TCTouch.Touch ('C'); ----------------------------------------- C
      Obj.Count := 0;
   end Clear;

   procedure Bump (Obj : in out Counted_Type) is
      -- Increment the count of Obj.
   begin
      TCTouch.Touch ('B'); ----------------------------------------- B
      Obj.Count := Obj.Count + 1;
   end Bump;

   function Count (Obj : Counted_Type) return Natural is
      -- Return the count of Obj.
   begin
      TCTouch.Touch ('c'); ----------------------------------------- c
      return Obj.Count;
   end Count;

   procedure Double_Bump (Obj : in out Counted_Type'Class) is
      -- Increment the count of Obj twice.
   begin
      TCTouch.Touch ('D'); ----------------------------------------- D
      Bump (Obj);
      Bump (Obj);
   end Double_Bump;

end CC30003_0;
