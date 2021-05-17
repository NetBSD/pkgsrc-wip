

     --==================================================================--


with CXF2005_0;
with CXF2005_1;

with Report;
procedure CXF2005 is

   Loop_Count : constant := 25_000;
   type Loop_Range is range 1 .. Loop_Count;

begin

   Report.Test ("CXF2005", "Check decimal multiplication and division, " &
                           "where one operand type is Integer");


               ---=---=---=---=---=---=---=---=---=---=---


   RADIX_2_SUBTESTS:
   declare
      package Radix_2 is new CXF2005_0 (CXF2005_1.Money_Radix2);
      use type CXF2005_1.Money_Radix2;
   begin

      RADIX_2_MULTIPLICATION:
      declare
         Rate           : constant CXF2005_1.Interest_Rate := 0.127;
         Period         : constant Integer                 := 12;

         Expected       : constant CXF2005_1.Money_Radix2  := 2_624.88;
         Balance        :          CXF2005_1.Money_Radix2  := 1_000.00;

         Operand        :          CXF2005_1.Money_Radix2;
         Increment      :          CXF2005_1.Money_Radix2;
         Interval       :          Integer;
      begin

         for I in Loop_Range loop
            Interval  := (Integer(I) mod Period) + 1;  -- Range from 1 to 12.
            Operand   := CXF2005_1.Factor (Rate, Period);
            Increment := Radix_2.Multiply (Operand, Interval);
            Balance   := Balance + Increment;
         end loop;

         if Balance /= Expected then
            Report.Failed ("Error: Radix 2 multiply");
         end if;

      end RADIX_2_MULTIPLICATION;



      RADIX_2_DIVISION:
      declare
         Rate           : constant CXF2005_1.Interest_Rate := 0.377;
         Period         : constant Integer                 := 12;

         Expected       : constant CXF2005_1.Money_Radix2  :=  36_215.58;
         Balance        :          CXF2005_1.Money_Radix2  := 456_985.01;

         Operand        :          CXF2005_1.Money_Radix2;
         Increment      :          CXF2005_1.Money_Radix2;
         Interval       :          Integer;
      begin

         for I in Loop_Range loop
            Interval  := (Integer(I+1000) mod (200*Period)) + 1; -- 1 .. 2400.
            Operand   := CXF2005_1.Factor (Rate, Period);
            Increment := Radix_2.Divide (Balance, Interval);
            Balance   := Balance - (Operand * Increment);
         end loop;

         if Balance /= Expected then
            Report.Failed ("Error: Radix 2 divide");
         end if;

      end RADIX_2_DIVISION;

   end RADIX_2_SUBTESTS;


               ---=---=---=---=---=---=---=---=---=---=---


   RADIX_10_SUBTESTS:
   declare
      package Radix_10 is new CXF2005_0 (CXF2005_1.Money_Radix10);
      use type CXF2005_1.Money_Radix10;
   begin

      RADIX_10_MULTIPLICATION:
      declare
         Rate           : constant CXF2005_1.Interest_Rate := 0.721;
         Period         : constant Integer                 := 12;

         Expected       : constant CXF2005_1.Money_Radix10 := 9_875.62;
         Balance        :          CXF2005_1.Money_Radix10 :=   126.34;

         Operand        :          CXF2005_1.Money_Radix10;
         Increment      :          CXF2005_1.Money_Radix10;
         Interval       :          Integer;
      begin

         for I in Loop_Range loop
            Interval  := (Integer(I) mod Period) + 1;  -- Range from 1 to 12.
            Operand   := CXF2005_1.Factor (Rate, Period);
            Increment := Radix_10.Multiply (Operand, Interval);
            Balance   := Balance + Increment;
         end loop;

         if Balance /= Expected then
            Report.Failed ("Error: Radix 10 multiply");
         end if;

      end RADIX_10_MULTIPLICATION;


      RADIX_10_DIVISION:
      declare
         Rate           : constant CXF2005_1.Interest_Rate := 0.547;
         Period         : constant Integer                 := 12;

         Expected       : constant CXF2005_1.Money_Radix10 :=  26_116.37;
         Balance        :          CXF2005_1.Money_Radix10 := 770_082.46;

         Operand        :          CXF2005_1.Money_Radix10;
         Increment      :          CXF2005_1.Money_Radix10;
         Interval       :          Integer;
      begin

         for I in Loop_Range loop
            Interval  := (Integer(I+1000) mod (200*Period)) + 1; -- 1 .. 2400.
            Operand   := CXF2005_1.Factor (Rate, Period);
            Increment := Radix_10.Divide (Balance, Interval);
            Balance   := Balance - (Operand * Increment);
         end loop;

         if Balance /= Expected then
            Report.Failed ("Error: Radix 10 divide");
         end if;

      end RADIX_10_DIVISION;

   end RADIX_10_SUBTESTS;


               ---=---=---=---=---=---=---=---=---=---=---


   Report.Result;

end CXF2005;
