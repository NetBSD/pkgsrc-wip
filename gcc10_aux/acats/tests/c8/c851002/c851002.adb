


with Report;
with C851002_A; use C851002_A;
procedure C851002 is

   procedure Use_It_1 (Obj : access Integer) is
      -- Use Obj so that the compiler cannot remove the actual from
      -- the program as a dead object.
   begin
      if Obj = null then
         null;
      elsif not Report.Equal (Obj.all, Obj.all) then
         Report.Comment ("Don't optimize Obj");
      end if;
   end Use_It_1;

   procedure Use_It_2 (Obj : access function (X : Float) return Float) is
      -- Use Obj so that the compiler cannot remove the actual from
      -- the program as a dead object.
   begin
      if Obj = null then
         null;
      elsif Report.Equal (Integer(Obj(2.0)), 0) then
         Report.Comment ("Don't optimize Obj");
      end if;
   end Use_It_2;

begin
   Report.Test ("C851002", "For an object renaming with an anonymous " &
                           "access type, check that the name is resolved " &
                           "if there is only one interpretation with a " &
                           "correct anonymous access type, even if other " &
                           "interpretations exist");

   declare
      Ren1 : access Integer renames Element1(1).Comp1;
   begin
      if Ren1.all /= C851002_A.Aux then
         Report.Failed ("Wrong value (1)");
      end if;
      Use_It_1 (Ren1);
   end;

   declare
      Ren2 : access function (X : Float) return Float renames Element1(2).Comp2;
   begin
      if Ren2.all(2.0) /= 4.0 then
         Report.Failed ("Wrong value (2)");
      end if;
      Use_It_2 (Ren2);
   end;

   declare
      Ren3 : access Integer renames Element2(3).Comp1;
   begin
      if Ren3.all /= C851002_A.Aux then
         Report.Failed ("Wrong value (3)");
      end if;
      Use_It_1 (Ren3);
   end;

   declare
      Ren4 : access function (X : Float) return Float renames Element2(4).Comp2;
   begin
      if Ren4.all(2.0) /= 4.0 then
         Report.Failed ("Wrong value (4)");
      end if;
      Use_It_2 (Ren4);
   end;

   declare
      Ren5 : access Integer renames Element3(5).Comp1;
   begin
      if Ren5.all /= C851002_A.Aux then
         Report.Failed ("Wrong value (5)");
      end if;
      Use_It_1 (Ren5);
   end;

   declare
      Ren6 : access function (X : Float) return Float renames Element3(6).Comp2;
   begin
      if Ren6.all(2.0) /= 4.0 then
         Report.Failed ("Wrong value (6)");
      end if;
      Use_It_2 (Ren6);
   end;

   Report.Result;

end C851002;
