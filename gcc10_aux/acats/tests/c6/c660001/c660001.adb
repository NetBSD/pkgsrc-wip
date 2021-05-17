

with Report;
with C660001_0; use C660001_0;
procedure C660001 is

begin
   Report.Test ("C660001",
                "Check that an explicit declaration of ""="" with a result of "&
                "Boolean also declares an ""/="" with a complementary result");

   declare
      A1, A2 : Unbounded_String := +"123";
   begin
      if not (A1 = A2) then
         Report.Failed ("Wrong behavior from ""="" (1)");
      end if;
      if A1 /= A2 then
         Report.Failed ("Wrong behavior from ""/="" (1)");
      end if;
   end;

   declare
      A3 : Unbounded_String := +"ABCD";
   begin
      if not (A3 = "ABCD") then
         Report.Failed ("Wrong behavior from ""="" (2)");
      end if;
      if "1234" = A3 then
         Report.Failed ("Wrong behavior from ""="" (3)");
      end if;
      if A3 /= "ABCD" then
         Report.Failed ("Wrong behavior from ""/="" (2)");
      end if;
      if not (A3 /= "1234") then
         Report.Failed ("Wrong behavior from ""/="" (3)");
      end if;
      if not (A3 /= "ABC") then
         Report.Failed ("Wrong behavior from ""/="" (4)");
      end if;
      if "ABCD" /= A3 then
         Report.Failed ("Wrong behavior from ""/="" (5)");
      end if;
      if not ("BCD" /= A3) then
         Report.Failed ("Wrong behavior from ""/="" (6)");
      end if;
   end;

   declare
      package Inner is
         type String_with_Count is new Unbounded_String with record
            Count : Natural := 0;
         end record;
         -- Inherited "=" and "/=" with String parameters do not use the
         -- extension component; the "=" and "/=" with both parameters
         -- String_with_Count do use the extension component as they
         -- incorporate the Unbounded_String "=" and are not inherited.

	 function "+" (Source : String) return String_with_Count;

      end Inner;

      package body Inner is
	 function "+" (Source : String) return String_with_Count is
         begin
            return String_with_Count'(Unbounded_String'(+Source) with Count => 0);
         end "+";
      end Inner;

      use Inner;

      Val5 : String_with_Count :=
         String_with_Count'(Unbounded_String'(+"XYZ") with Count => 5);
      Val10 : String_with_Count :=
         String_with_Count'(Unbounded_String'(+"XYZ") with Count => 10);

   begin
      if Val5 = Val10 then
         Report.Failed ("Wrong behavior from ""="" (11)");
      end if;
      if Val5 = +"XYZ" then
         Report.Failed ("Wrong behavior from ""="" (12)");
      end if;
      if not (Val5 /= Val10) then
         Report.Failed ("Wrong behavior from ""/="" (11)");
      end if;
      if not (Val5 /= +"XYZ") then
         Report.Failed ("Wrong behavior from ""/="" (11)");
      end if;
      if Val5 = "WXYZ" then
         Report.Failed ("Wrong behavior from ""="" (13)");
      end if;
      if not (Val5 /= "WXYZ") then
         Report.Failed ("Wrong behavior from ""/="" (13)");
      end if;
      if Val5 /= "XYZ" then
         Report.Failed ("Wrong behavior from ""/="" (14)");
      end if;
      if "XYZ" /= Val10 then
         Report.Failed ("Wrong behavior from ""/="" (14)");
      end if;
   end;

   Report.Result;

end C660001;
