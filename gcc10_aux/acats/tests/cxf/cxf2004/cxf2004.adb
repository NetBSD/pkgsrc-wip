

     --==================================================================--


with CXF2004_0;
with CXF2004_1;

with Report;
procedure CXF2004 is

   Loop_Count : constant := 180;
   type Loop_Range is range 1 .. Loop_Count;

   type Rounding_Scheme is ( Rounds, Truncates );
   Machine : Rounding_Scheme;

begin

   Report.Test ("CXF2004", "Check decimal multiplication and division, and " &
                           "'Round, where one operand type is ordinary fixed");


               ---=---=---=---=---=---=---=---=---=---=---

   if CXF2004_1.Interest_Rate'Machine_Rounds then  -- Determine machine's
      Machine := Rounds;                           -- rounding scheme.
   else
      Machine := Truncates;
   end if;

               ---=---=---=---=---=---=---=---=---=---=---


   RADIX_2_SUBTESTS:
   declare
      package Radix_2 is new CXF2004_0 (CXF2004_1.Money_Radix2,
                                        CXF2004_1.Interest_Rate);
      use type CXF2004_1.Money_Radix2;
      use type CXF2004_1.Interest_Rate;
   begin

      RADIX_2_MULTIPLICATION:
      declare
         Rate           : constant CXF2004_1.Interest_Rate := 0.154;
         Period         : constant Integer                 := 12;
         Factor         :          CXF2004_1.Interest_Rate := Rate / Period;

         -- The exact value of Factor is:
         --
         --    0.154/12 = 0.01283333...
         --
         -- The adjacent multiples of small are 0.012 and 0.013. Since
         -- Factor is of an ordinary fixed point type, it may contain either
         -- of these values. However, since "Rate / Period" is a static
         -- expression, the value Factor contains is determined by the
         -- value of CXF2004_1.Interest_Rate'Machine_Rounds:
         --
         --    If Machine_Rounds = FALSE : Factor = 0.012
         --    If Machine_Rounds = TRUE  : Factor = 0.013

         Initial                : constant CXF2004_1.Money_Radix2 :=  1_000.00;

         Trunc_Expected_MachTrnc: constant CXF2004_1.Money_Radix2 :=  8_557.07;
         Round_Expected_MachTrnc: constant CXF2004_1.Money_Radix2 :=  8_560.47;

         Trunc_Expected_MachRnds: constant CXF2004_1.Money_Radix2 := 10_222.65;
         Round_Expected_MachRnds: constant CXF2004_1.Money_Radix2 := 10_225.81;

         Balance                : CXF2004_1.Money_Radix2;
      begin
                       ---=---=---=---=---=---=---

         Balance := Initial;

         for I in Loop_Range loop
            Radix_2.Multiply_And_Truncate (Balance, Factor);
         end loop;

         case (Machine) is
            when Rounds    => 
               if Balance /= Trunc_Expected_MachRnds then
                  Report.Failed ("Error (R): Radix 2 multiply and truncate");
               end if;
            when Truncates =>
               if Balance /= Trunc_Expected_MachTrnc then
                  Report.Failed ("Error (T): Radix 2 multiply and truncate");
               end if;
         end case;

                       ---=---=---=---=---=---=---

         Balance := Initial;

         for I in Loop_Range loop
            Radix_2.Multiply_And_Round (Balance, Factor);
         end loop;

         case (Machine) is
            when Rounds    => 
               if Balance /= Round_Expected_MachRnds then
                  Report.Failed ("Error (R): Radix 2 multiply and round");
               end if;
            when Truncates =>
               if Balance /= Round_Expected_MachTrnc then
                  Report.Failed ("Error (T): Radix 2 multiply and round");
               end if;
         end case;

                       ---=---=---=---=---=---=---
      end RADIX_2_MULTIPLICATION;


      RADIX_2_DIVISION:
      declare
         Rate           : constant CXF2004_1.Interest_Rate := 0.210;
         Period         : constant Integer                 := 12;
         Factor         : constant CXF2004_1.Interest_Rate := Rate / Period;
         Divisor        :          CXF2004_1.Interest_Rate := 1.0 / Factor;

         -- The exact value of Factor is:
         --
         --    0.210/12 = 0.0175
         --
         -- The adjacent multiples of small are 0.017 and 0.018. Since
         -- Factor is of an ordinary fixed point type, it may contain either
         -- of these values. However, since "Rate / Period" is a static
         -- expression, the value Factor contains is determined by the
         -- value of CXF2004_1.Interest_Rate'Machine_Rounds:
         --
         --    If Machine_Rounds = FALSE : Factor = 0.017
         --    If Machine_Rounds = TRUE  : Factor = 0.018
         --
         -- The exact value of Divisor is one of the following values:
         --
         --    1.0/0.017 = 58.82352... (Adjacent smalls 58.823 and 58.824)
         --    1.0/0.018 = 55.55555... (Adjacent smalls 55.555 and 55.556)
         --
         -- Again, since "1.0 / Factor" is static, the value Divisor contains
         -- is determined by the value of CXF2004_1.Interest_Rate'Rounds:
         --
         --    If Machine_Rounds = FALSE : Divisor = 58.823
         --    If Machine_Rounds = TRUE  : Divisor = 55.556

         Initial                : constant CXF2004_1.Money_Radix2 :=    260.13;

         Trunc_Expected_MachTrnc: constant CXF2004_1.Money_Radix2 :=  5_401.46;
         Round_Expected_MachTrnc: constant CXF2004_1.Money_Radix2 :=  5_406.95;

         Trunc_Expected_MachRnds: constant CXF2004_1.Money_Radix2 :=  6_446.56;
         Round_Expected_MachRnds: constant CXF2004_1.Money_Radix2 :=  6_453.78;

         Balance                : CXF2004_1.Money_Radix2;
      begin
                       ---=---=---=---=---=---=---

         Balance := Initial;

         for I in Loop_Range loop
            Radix_2.Divide_And_Truncate (Balance, Divisor);
         end loop;

         case (Machine) is
            when Rounds    => 
               if Balance /= Trunc_Expected_MachRnds then
                  Report.Failed ("Error (R): Radix 2 divide and truncate");
               end if;
            when Truncates =>
               if Balance /= Trunc_Expected_MachTrnc then
                  Report.Failed ("Error (T): Radix 2 divide and truncate");
               end if;
         end case;

                       ---=---=---=---=---=---=---

         Balance := Initial;

         for I in Loop_Range loop
            Radix_2.Divide_And_Round (Balance, Divisor);
         end loop;

         case (Machine) is
            when Rounds    => 
               if Balance /= Round_Expected_MachRnds then
                  Report.Failed ("Error (R): Radix 2 divide and round");
               end if;
            when Truncates =>
               if Balance /= Round_Expected_MachTrnc then
                  Report.Failed ("Error (T): Radix 2 divide and round");
               end if;
         end case;

                       ---=---=---=---=---=---=---
      end RADIX_2_DIVISION;

   end RADIX_2_SUBTESTS;


               ---=---=---=---=---=---=---=---=---=---=---


   RADIX_10_SUBTESTS:
   declare
      package Radix_10 is new CXF2004_0 (CXF2004_1.Money_Radix10,
                                         CXF2004_1.Interest_Rate);
      use type CXF2004_1.Money_Radix10;
      use type CXF2004_1.Interest_Rate;
   begin

      RADIX_10_MULTIPLICATION:
      declare
         Rate           : constant CXF2004_1.Interest_Rate := 0.095;
         Period         : constant Integer                 := 12;
         Factor         :          CXF2004_1.Interest_Rate := Rate / Period;

         -- The exact value of Factor is:
         --
         --    0.095/12 = 0.00791666...
         --
         -- The adjacent multiples of small are 0.007 and 0.008. Since
         -- Factor is of an ordinary fixed point type, it may contain either
         -- of these values. However, since "Rate / Period" is a static
         -- expression, the value Factor contains can be determined based
         -- on the value of CXF2004_1.Interest_Rate'Machine_Rounds:
         --
         --    If Machine_Rounds = FALSE : Factor = 0.007
         --    If Machine_Rounds = TRUE  : Factor = 0.008

         Initial                : constant CXF2004_1.Money_Radix10 := 2_125.00;

         Trunc_Expected_MachTrnc: constant CXF2004_1.Money_Radix10 := 7_456.90;
         Round_Expected_MachTrnc: constant CXF2004_1.Money_Radix10 := 7_458.77;

         Trunc_Expected_MachRnds: constant CXF2004_1.Money_Radix10 := 8_915.74;
         Round_Expected_MachRnds: constant CXF2004_1.Money_Radix10 := 8_917.84;

         Balance                : CXF2004_1.Money_Radix10;
      begin
                       ---=---=---=---=---=---=---

         Balance := Initial;

         for I in Loop_Range loop
            Radix_10.Multiply_And_Truncate (Balance, Factor);
         end loop;

         case (Machine) is
            when Rounds    => 
               if Balance /= Trunc_Expected_MachRnds then
                  Report.Failed ("Error (R): Radix 10 multiply and truncate");
               end if;
            when Truncates =>
               if Balance /= Trunc_Expected_MachTrnc then
                  Report.Failed ("Error (T): Radix 10 multiply and truncate");
               end if;
         end case;

                       ---=---=---=---=---=---=---

         Balance := Initial;

         for I in Loop_Range loop
            Radix_10.Multiply_And_Round (Balance, Factor);
         end loop;

         case (Machine) is
            when Rounds    => 
               if Balance /= Round_Expected_MachRnds then
                  Report.Failed ("Error (R): Radix 10 multiply and round");
               end if;
            when Truncates =>
               if Balance /= Round_Expected_MachTrnc then
                  Report.Failed ("Error (T): Radix 10 multiply and round");
               end if;
         end case;

                       ---=---=---=---=---=---=---
      end RADIX_10_MULTIPLICATION;


      RADIX_10_DIVISION:
      declare
         Rate           : constant CXF2004_1.Interest_Rate := 0.295;
         Period         : constant Integer                 := 12;
         Factor         : constant CXF2004_1.Interest_Rate := Rate / Period;
         Divisor        :          CXF2004_1.Interest_Rate := 1.0 / Factor;

         -- The exact value of Factor is:
         --
         --    0.295/12 = 0.02458333...
         --
         -- The adjacent multiples of small are 0.024 and 0.025. Thus, the
         -- exact value of Divisor is one of the following:
         --
         --    1.0/0.024 = 41.66666... (Adjacent smalls 41.666 and 41.667)
         --    1.0/0.025 = 40.0
         --
         -- The value of CXF2004_1.Interest_Rate'Machine_Rounds determines
         -- what Divisor contains:
         --
         --    If Machine_Rounds = FALSE : Divisor = 41.666
         --    If Machine_Rounds = TRUE  : Divisor = 40.000

         Initial                : constant CXF2004_1.Money_Radix10 :=    72.19;

         Trunc_Expected_MachTrnc: constant CXF2004_1.Money_Radix10 := 5_144.60;
         Round_Expected_MachTrnc: constant CXF2004_1.Money_Radix10 := 5_157.80;

         Trunc_Expected_MachRnds: constant CXF2004_1.Money_Radix10 := 6_133.28;
         Round_Expected_MachRnds: constant CXF2004_1.Money_Radix10 := 6_149.06;

         Balance                : CXF2004_1.Money_Radix10;
      begin
                       ---=---=---=---=---=---=---

         Balance := Initial;

         for I in Loop_Range loop
            Radix_10.Divide_And_Truncate (Balance, Divisor);
         end loop;

         case (Machine) is
            when Rounds    => 
               if Balance /= Trunc_Expected_MachRnds then
                  Report.Failed ("Error (R): Radix 10 divide and truncate");
               end if;
            when Truncates =>
               if Balance /= Trunc_Expected_MachTrnc then
                  Report.Failed ("Error (T): Radix 10 divide and truncate");
               end if;
         end case;

                       ---=---=---=---=---=---=---

         Balance := Initial;

         for I in Loop_Range loop
            Radix_10.Divide_And_Round (Balance, Divisor);
         end loop;

         case (Machine) is
            when Rounds    => 
               if Balance /= Round_Expected_MachRnds then
                  Report.Failed ("Error (R): Radix 10 divide and round");
               end if;
            when Truncates =>
               if Balance /= Round_Expected_MachTrnc then
                  Report.Failed ("Error (T): Radix 10 divide and round");
               end if;
         end case;

                       ---=---=---=---=---=---=---
      end RADIX_10_DIVISION;

   end RADIX_10_SUBTESTS;


               ---=---=---=---=---=---=---=---=---=---=---


   Report.Result;

end CXF2004;
