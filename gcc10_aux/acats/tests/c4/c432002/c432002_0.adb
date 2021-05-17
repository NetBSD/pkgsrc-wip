
with Report;
package body C432002_0 is

   S : String (1..20) := "12345678901234567890";

   procedure Do_Something (Rec : in out Discriminant) is
   begin
      Rec.S1 := Report.Ident_Str (S (1..Rec.L));
   end Do_Something;

   procedure Do_Something (Rec : in out Multiple_Discriminants) is
   begin
      Rec.S1 := Report.Ident_Str (S (1..Rec.A));
   end Do_Something;

end C432002_0;
