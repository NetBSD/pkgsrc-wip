

     --==================================================================--


with CC51009_1;
with CC51009_2;

with Report;
procedure CC51009 is

   package Integer_Sets is new CC51009_2.Set_Abstraction (Integer);

   use Integer_Sets;

   package Integer_Set_Processing
     is new CC51009_1.Set_Processing (Integer, Set, The_Set_Signature);

   Elt_Value : constant Integer := 17;

   S1 : Integer_Sets.Set;
   S2 : Integer_Sets.Set;
   S3 : Integer_Sets.Set;

   Result_Set : Integer_Sets.Set;

begin
   Report.Test ("CC51009", "Check that a generic unit with incomplete " &
                "formal types can be instantiated with a private "  &
                "type prior to the full declaration of that " &
                "type, and that such instantiations can be passed as " &
                "actuals to formal packages");

   --  Initialize S1 to { 1 .. 10 }

   for I in Integer range 1 .. 10 loop
      Add (I, S1);
   end loop;

   --  Initialize S1 to { 5 .. 15 }

   for I in Integer range 5 .. 15 loop
      Add (I, S2);
   end loop;

   --  Initialize S1 to { 20 .. 25 }

   for I in Integer range 20 .. 25 loop
      Add (I, S3);
   end loop;

   --  Initialize Result_Set to { 5 .. 10, 17, 20 .. 25 }

   for I in Integer range 5 .. 10 loop
      Add (I, Result_Set);
   end loop;

   for I in Integer range 20 .. 25 loop
      Add (I, Result_Set);
   end loop;

   Add (Elt_Value, Result_Set);

   --  Compute "Union (Intersection (S1, S2), S3) + E"

   Integer_Set_Processing.Test (S1, S2, S3, Elt_Value);

   if S1 /= Result_Set then
      Report.Failed ("Wrong result set from Integer set operations");
   end if;

   Report.Result;
end CC51009;
