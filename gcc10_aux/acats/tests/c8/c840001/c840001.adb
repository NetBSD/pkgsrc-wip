
     --==================================================================--


with C840001_0;
with C840001_1;
with C840001_2;

with Report;

procedure C840001 is

begin
   Report.Test ("C840001", "Check that, for the type determined by the "   &
                "subtype mark of a use type clause, the declaration of "   &
                "each primitive operator is use-visible within the scope " &
                "of the clause, even if explicit operators with the same " &
                "names as the type's operators are declared for the subtype");


   Use_Type_Precision_Pos_Float:
   declare
      TC_Operand          : C840001_0.Precision_Float
                          := C840001_0.Precision_Float(-2.0);
      TC_Positive_Operand : C840001_1.Precision_Pos_Float :=  6.0;

      TC_Actual_Type      : C840001_0.Precision_Float;
      TC_Actual_Subtype   : C840001_1.Precision_Pos_Float;

      use type C840001_1.Precision_Pos_Float;
      -- Both calls to "**" should return 68.0 (that is, Precision_Float's
      -- operation should be called).

   begin

      TC_Actual_Type := TC_Operand**2;

      if C840001_0."/="(TC_Actual_Type, C840001_0.TC_Expected) then
         Report.Failed ("1st block: type's operation not called for " &
                        "operand of 1st subtype");
      end if;

      TC_Actual_Subtype := TC_Positive_Operand**2;

      if not (C840001_0."="
             (TC_Actual_Subtype, C840001_0.TC_Expected)) then
         Report.Failed ("1st block: type's operation not called for " &
                        "operand of explicit subtype");
      end if;

   end Use_Type_Precision_Pos_Float;

   Use_Type_Precision_Float:
   declare
      TC_Operand          : C840001_0.Precision_Float
                          := C840001_0.Precision_Float(4.0);
      TC_Positive_Operand : C840001_1.Precision_Pos_Float :=  7.0;

      TC_Actual_Type      : C840001_0.Precision_Float;
      TC_Actual_Subtype   : C840001_1.Precision_Pos_Float;

      use type C840001_0.Precision_Float;
      -- Again, both calls to "**" should return 68.0.

  begin

      TC_Actual_Type := TC_Operand**2;

      if C840001_0."/="(TC_Actual_Type, C840001_0.TC_Expected) then
         Report.Failed ("2nd block: type's operation not called for " &
                        "operand of 1st subtype");
      end if;

      TC_Actual_Subtype := TC_Positive_Operand**2;

      if not C840001_0."=" (TC_Actual_Subtype, C840001_0.TC_Expected) then
         Report.Failed ("2nd block: type's operation not called for " &
                        "operand of explicit subtype");
      end if;

   end Use_Type_Precision_Float;

   C840001_2; -- 3rd test.

   Report.Result;

end C840001;
