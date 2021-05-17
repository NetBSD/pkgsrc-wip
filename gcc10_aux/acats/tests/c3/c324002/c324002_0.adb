

with Ada.Unchecked_Deallocation;
package body C324002_0 is

   function Length (Source : Unbounded_String) return Natural is
   begin
      return Source.Str.all'Length;
   end Length;


   function "+" (Source : String) return Unbounded_String is
      Result : Unbounded_String := (Ada.Finalization.Controlled with
               Str => new String(1 .. Source'Length));
   begin
      Result.Str.all := Source;
      return Result;
   end "+";


   function "+" (Source : Unbounded_String) return String is
   begin
      return Source.Str.all;
   end "+";


   procedure Set_Unbounded_String
      (Target : out Unbounded_String; Source : in String) is
   begin
      Free (Target.Str);
      Target := (Ada.Finalization.Controlled with
                Str => new String(1 .. Source'Length));
      Target.Str.all := Source;
   end Set_Unbounded_String;


   procedure Append
      (Source : in out Unbounded_String; New_Item : in String) is
      S_Length : Natural;
      Length : Natural;
      Temp : String_Access := Source.Str;
   begin
      S_Length := Source.Str.All'Length;
      Length := S_Length + New_Item'Length;
      Source.Str :=  new String(1 .. Length); -- new size
      if Temp /= null then
         Source.Str.all (1 .. S_Length) := Temp.all;
      end if;
      Source.Str.all (S_Length + 1 .. Length) := New_Item;
      Free (Temp);
   end Append;


   function "&" (Left : Unbounded_String; Right : String)
      return Unbounded_String is
   begin
      declare
         Result : Unbounded_String := (Ada.Finalization.Controlled with
                  Str => new String(1 .. Left.Str.All'Length + Right'Length));
      begin
         Result.Str.all := Left.Str.all & Right;
         return Result;
      end;
   end "&";


   function "&" (Left, Right : Unbounded_String)
      return Unbounded_String is
   begin
      return Left & Right.Str.all;
   end "&";


   function Element (Source : in Unbounded_String; Index : in Positive)
      return Character is
   begin
      return Source.Str.all (Index); -- Raises Constraint_Error if Index
          -- is greater than Length (Source);
   end Element;


   procedure Free (X : in out String_Access) is
      procedure Deallocate is new Ada.Unchecked_Deallocation
                                            (String, String_Access);
   begin
      Deallocate (X);
   end Free;


   procedure Finalize (Object : in out Unbounded_String) is
   begin
      Free (Object.Str);
   end Finalize;


   procedure Adjust   (Object : in out Unbounded_String) is
   begin
      Object.Str := new String'(Object.Str.all);
   end Adjust;

end C324002_0;
