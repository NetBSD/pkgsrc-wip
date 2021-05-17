
package body C340001_1 is

   -- Note: This is not a complete abstraction of a list. Exceptions
   -- are not defined and boundary checks are not made.

   procedure Add_To (L : in out List; New_Value : in Integer) is
   begin
      L.Length := L.Length + 1;
      L.Contents (L.Length) := New_Value;
   end Add_To;

   procedure Remove_From (L : in out List) is
   -- The list length is decremented. "Old" values are left in the
   -- array. They are overwritten when a new value is added.
   begin
      L.Length := L.Length - 1;
   end Remove_From;

   function "=" (L, R : in List) return Boolean is
   -- Two lists are equal if they are the same length and
   -- the component values within that length are the same.
   -- Values stored past the end of the list are ignored.
   begin
      return L.Length = R.Length
	 and then L.Contents (1..L.Length) = R.Contents (1..R.Length);
   end "=";

   procedure Revise (L : in out Revisable_List) is
   begin
      L.Revision := Character'Succ (L.Revision);
   end Revise;
   
end C340001_1;
