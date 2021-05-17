

     --==================================================================--


with CXF2002_0;
with CXF2002_1;

with Report;
procedure CXF2002 is

   Loop_Count : constant := 300;
   type Loop_Range is range 1 .. Loop_Count;

begin

   Report.Test ("CXF2002", "Check decimal multiplication and division, and " &
                           "'Round, where the operand and result types are " &
                           "the same");


               ---=---=---=---=---=---=---=---=---=---=---


   RADIX_2_SUBTESTS:
   declare
      package Radix_2 is new CXF2002_0 (CXF2002_1.Money_Radix2);
      use type CXF2002_1.Money_Radix2;
   begin

      RADIX_2_MULTIPLICATION:
      declare
         Rate           : constant CXF2002_1.Money_Radix2 := 0.12;
         Period         : constant Integer                := 12;
         Factor         :          CXF2002_1.Money_Radix2 := Rate / Period;

         Initial        : constant CXF2002_1.Money_Radix2 :=   100_000.00;
         Trunc_Expected : constant CXF2002_1.Money_Radix2 := 1_978_837.50;
         Round_Expected : constant CXF2002_1.Money_Radix2 := 1_978_846.75;

         Balance        : CXF2002_1.Money_Radix2;
      begin
                       ---=---=---=---=---=---=---

         Balance := Initial;

         for I in Loop_Range loop
            Radix_2.Multiply_And_Truncate (Balance, Factor);
         end loop;

         if Balance /= Trunc_Expected then
            Report.Failed ("Wrong result: Radix 2 multiply and truncate");
         end if;

                       ---=---=---=---=---=---=---

         Balance := Initial;

         for I in Loop_Range loop
            Radix_2.Multiply_And_Round (Balance, Factor);
         end loop;

         if Balance /= Round_Expected then
            Report.Failed ("Wrong result: Radix 2 multiply and round");
         end if;

                       ---=---=---=---=---=---=---
      end RADIX_2_MULTIPLICATION;


      RADIX_2_DIVISION:
      declare
         Rate           : constant CXF2002_1.Money_Radix2 := 0.25;
         Period         : constant Integer                := 12;
         Factor         :          CXF2002_1.Money_Radix2 := Rate / Period;
         Divisor        : constant CXF2002_1.Money_Radix2 := 1.0 / Factor;

         Initial        : constant CXF2002_1.Money_Radix2 :=     5_500.36;
         Trunc_Expected : constant CXF2002_1.Money_Radix2 := 2_091_332.87;
         Round_Expected : constant CXF2002_1.Money_Radix2 := 2_091_436.88;

         Balance        : CXF2002_1.Money_Radix2;
      begin
                       ---=---=---=---=---=---=---

         Balance := Initial;

         for I in Loop_Range loop
            Radix_2.Divide_And_Truncate (Balance, Divisor);
         end loop;

         if Balance /= Trunc_Expected then
            Report.Failed ("Wrong result: Radix 2 divide and truncate");
         end if;

                       ---=---=---=---=---=---=---

         Balance := Initial;

         for I in Loop_Range loop
            Radix_2.Divide_And_Round (Balance, Divisor);
         end loop;

         if Balance /= Round_Expected then
            Report.Failed ("Wrong result: Radix 2 divide and round");
         end if;

                       ---=---=---=---=---=---=---
      end RADIX_2_DIVISION;

   end RADIX_2_SUBTESTS;


               ---=---=---=---=---=---=---=---=---=---=---


   RADIX_10_SUBTESTS:
   declare
      package Radix_10 is new CXF2002_0 (CXF2002_1.Money_Radix10);
      use type CXF2002_1.Money_Radix10;
   begin

      RADIX_10_MULTIPLICATION:
      declare
         Rate           : constant CXF2002_1.Money_Radix10 := 0.37;
         Period         : constant Integer                 := 12;
         Factor         :          CXF2002_1.Money_Radix10 := Rate / Period;

         Initial        : constant CXF2002_1.Money_Radix10 :=       459.33;
         Trunc_Expected : constant CXF2002_1.Money_Radix10 := 3_259_305.54;
         Round_Expected : constant CXF2002_1.Money_Radix10 := 3_260_544.11;

         Balance        : CXF2002_1.Money_Radix10;
      begin
                       ---=---=---=---=---=---=---

         Balance := Initial;

         for I in Loop_Range loop
            Radix_10.Multiply_And_Truncate (Balance, Factor);
         end loop;

         if Balance /= Trunc_Expected then
            Report.Failed ("Wrong result: Radix 10 multiply and truncate");
         end if;

                       ---=---=---=---=---=---=---

         Balance := Initial;

         for I in Loop_Range loop
            Radix_10.Multiply_And_Round (Balance, Factor);
         end loop;

         if Balance /= Round_Expected then
            Report.Failed ("Wrong result: Radix 10 multiply and round");
         end if;

                       ---=---=---=---=---=---=---
      end RADIX_10_MULTIPLICATION;


      RADIX_10_DIVISION:
      declare
         Rate           : constant CXF2002_1.Money_Radix10 := 0.15;
         Period         : constant Integer                 := 12;
         Factor         :          CXF2002_1.Money_Radix10 := Rate / Period;
         Divisor        : constant CXF2002_1.Money_Radix10 := 1.0 / Factor;

         Initial        : constant CXF2002_1.Money_Radix10 :=    29_842.08;
         Trunc_Expected : constant CXF2002_1.Money_Radix10 :=   590_519.47;
         Round_Expected : constant CXF2002_1.Money_Radix10 :=   590_528.98;

         Balance        : CXF2002_1.Money_Radix10;
      begin
                       ---=---=---=---=---=---=---

         Balance := Initial;

         for I in Loop_Range loop
            Radix_10.Divide_And_Truncate (Balance, Divisor);
         end loop;

         if Balance /= Trunc_Expected then
            Report.Failed ("Wrong result: Radix 10 divide and truncate");
         end if;

                       ---=---=---=---=---=---=---

         Balance := Initial;

         for I in Loop_Range loop
            Radix_10.Divide_And_Round (Balance, Divisor);
         end loop;

         if Balance /= Round_Expected then
            Report.Failed ("Wrong result: Radix 10 divide and round");
         end if;

                       ---=---=---=---=---=---=---
      end RADIX_10_DIVISION;

   end RADIX_10_SUBTESTS;


               ---=---=---=---=---=---=---=---=---=---=---


   Report.Result;

end CXF2002;
