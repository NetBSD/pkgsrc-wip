

     --==================================================================--


with FC51A00;     -- Fraction type abstraction.
with CC51A01_0;   -- Fraction I/O support.
with CC51A01_1;   -- Positive fraction type abstraction.

with Report;
procedure CC51A01 is

   type Distance is new CC51A01_1.Pos_Fraction;    -- Derived indirectly from
                                                   -- root type of class.
   -- Inherits "/" indirectly from root type.
   -- Inherits "-" indirectly from root type.
   -- Inherits Numerator directly from parent type.
   -- Inherits Denominator indirectly from root type.

   use FC51A00, CC51A01_1;                         -- All primitive subprograms
                                                   -- directly visible.

   package Fraction_IO     is new CC51A01_0 (Fraction_Type);
   package Pos_Fraction_IO is new CC51A01_0 (Pos_Fraction);
   package Distance_IO     is new CC51A01_0 (Distance);

   -- For each of the instances above, the subprogram "Put" should produce
   -- the same result. That is, the primitive subprograms called by Put
   -- should in all cases be those of the type Fraction_Type, which is the
   -- ancestor type for the formal derived type in the generic unit. In
   -- particular, for Pos_Fraction_IO and Distance_IO, the versions of
   -- Numerator called should NOT be those of the actual types, which override
   -- Fraction_Type's version.

   TC_Expected_Result : constant String := "-3/ 16";

   TC_Root_Type_Of_Class  : Fraction_Type := -3/16;
   TC_Direct_Derivative   : Pos_Fraction  := -3/16;
   TC_Indirect_Derivative : Distance      := -3/16;

begin
   Report.Test ("CC51A01", "Check that, in an instance, each implicit "     &
                "declaration of a user-defined subprogram of a formal "     &
                "derived record type declares a view of the corresponding " &
                "primitive subprogram of the ancestor, even if the "        &
                "primitive subprogram has been overridden for the actual "  &
                "type");

   if (Fraction_IO.Put (TC_Root_Type_Of_Class) /= TC_Expected_Result) then
      Report.Failed ("Wrong result for root type");
   end if;

   if (Pos_Fraction_IO.Put (TC_Direct_Derivative) /= TC_Expected_Result) then
      Report.Failed ("Wrong result for direct derivative");
   end if;

   if (Distance_IO.Put (TC_Indirect_Derivative) /= TC_Expected_Result) then
      Report.Failed ("Wrong result for INdirect derivative");
   end if;

   Report.Result;
end CC51A01;
