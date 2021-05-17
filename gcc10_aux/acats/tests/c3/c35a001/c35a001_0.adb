
with Report;
package body C35A001_0 is

   procedure Assert (Truth : Boolean; Message: String) is
   begin
      if not Truth then
         Report.Failed (Message);
      end if;
   end Assert;


   function Ident (FX : CHECK_TYPE) RETURN CHECK_TYPE IS
   begin
      if Report.Equal (3, 3) then
         return FX;
      else
         return 0.0;
      end if;
   end Ident;


   procedure TC_Check_Values is
      CNeg1 : Check_Type := -3.5;
      CNeg2 : Check_Type := Check_Type (-1.0/3.0);
      CPos1 : Check_Type := Check_Type (4.0/6.0);
      CPos2 : Check_Type :=  3.5;
   begin

      Assert (Tenths'Small = 1.0 / Two ** Five,
              "Tenths Small not specified value");

      Assert (Check_Type'Small = Specified_Small,
              "Check_Type Small not specified value");

      Assert (Derived_Type'Small = Tenths'Small,
              "Derived_Type Small not inherited");

      -- Check various operations of Check_Type:

      if Ident (CNeg1) + CPos1 not in -2.875 .. -2.8125 or else
         CPos2  - Ident (CPos1) not in 2.8125 .. 2.875 then
         Report.Failed ("Incorrect results for binary adding operators");
      end if;

      if +Ident (CNeg2) not in -0.375 .. -0.3125 or else
         Ident (-CPos1) not in -0.6875 .. -0.625 then
         Report.Failed ("Incorrect results for unary adding operators");
      end if;

      if Check_Type (CNeg1 * Ident (CPos1)) not in -2.4375 .. -2.1875 or else
         Check_Type (Ident (CNeg2) / CPos2) not in -0.125 .. -0.0625 then
          Report.Failed ("Incorrect results for multiplying operators");
      end if;

      if abs Ident (CNeg2) not in 0.3125 .. 0.375 or else
         Ident (ABS CPos1) not in 0.625 .. 0.6875 then
          Report.Failed ("Incorrect results for absolute value " &
                  "operators");
      end if;

      if Ident (CPos1) not in 0.625 .. 0.6875 or else
            CNeg2 in -0.25 .. 0.0 or else
            Ident (CNeg2) in -1.0 .. -0.4375 then
         Report.Failed ("Incorrect results for membership operations");
      end if;

   end TC_Check_Values;

end C35A001_0;
