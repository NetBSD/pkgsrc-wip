

     --==================================================================--


with Report;

with FC70A00;    -- Complex integer abstraction.
with CC70A02_0;  -- Mathematical group signature.
with CC70A02_1;  -- Mathematical group operations.

procedure CC70A02 is

   -- Declare an instance of complex integers:

   type My_Integer is range -100 .. 100;
   package Complex_Integers is new FC70A00 (My_Integer);


   -- Define an addition group for complex integers:

   package Complex_Addition_Group is new CC70A02_0
     (Group_Type => Complex_Integers.Complex_Type,  -- For complex integers...
      Identity   => Complex_Integers.Zero,          -- Additive identity.
      Operation  => Complex_Integers."+",           -- Additive operation.
      Inverse    => Complex_Integers."-");          -- Additive inverse.

   function Complex_Multiplication is new           -- Multiplication of a
     CC70A02_1.Power(Complex_Addition_Group);       -- complex integer by a
                                                    -- constant.


   -- Define a multiplication group for complex integers:

   package Complex_Multiplication_Group is new CC70A02_0
     (Group_Type => Complex_Integers.Complex_Type,  -- For complex integers...
      Identity   => Complex_Integers.One,           -- Multiplicative identity.
      Operation  => Complex_Integers."*",           -- Multiplicative oper.
      Inverse    => Complex_Integers.Reciprocal);   -- Multiplicative inverse.

   function Complex_Exponentiation is new           -- Exponentiation of a
     CC70A02_1.Power(Complex_Multiplication_Group); -- complex integer by a
                                                    -- constant.

   use Complex_Integers;


begin  -- Main program.

   Report.Test ("CC70A02", "Check that the visible part of a generic " &
                "formal package includes the first list of basic " &
                "declarative items of the package specification. Check " &
                "for a generic subprogram where formal package has (<>) " &
                "actual part");

   declare
      Mult_Operand         : constant Complex_Type := Complex ( -4,  9);
      Exp_Operand          : constant Complex_Type := Complex (  0, -7);

      Expected_Mult_Result : constant Complex_Type := Complex ( 28, -63);
      Expected_Exp_Result  : constant Complex_Type := Complex (-49,   0);
   begin

      if Complex_Multiplication (Mult_Operand, -7) /= Expected_Mult_Result then
         Report.Failed ("Incorrect results from complex multiplication");
      end if;

      if Complex_Exponentiation (Exp_Operand, 2) /= Expected_Exp_Result then
         Report.Failed ("Incorrect results from complex exponentiation");
      end if;

   end;

   Report.Result;

end CC70A02;
