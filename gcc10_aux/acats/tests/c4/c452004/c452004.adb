
with Report;
with TcTouch;
with C452004_A;
procedure C452004 is

   package Rats renames C452004_A;
   use type Rats.Rat;

   Third : Rats.Rat := 1 / 3;

begin

   Report.Test
     ("C452004",
      "Check that memberships with multiple choices are evaluated in order " &
      "and that primitive record equality is used to evaluate the tests");

   TcTouch.Validate (Expected => "V",
                     Message => "Wrong initialization (0)");

   -- Check that primitive equality works as expected:
   if Third + (2/4) = 5/6 then
      null;
   else
      Report.Failed ("Bad equality (0)");
   end if;
   TcTouch.Validate_One_Of (Expected_1 => "V+V=",
                            Expected_2 => "VV+=",
                            Message => "Wrong equality (0)");

   -- Choices evaluated in order:
   if +(1/1) in Rats.Zero | Rats.One then
      null; -- OK.
   else
      Report.Failed ("Wrong result (1)");
   end if;
   TcTouch.Validate (Expected => "Vp0=1=",
                     Message => "Wrong evaluation (1)");

   if -(1/3) not in Rats.Zero | Rats.One | -Third then
      Report.Failed ("Wrong result (2)");
   else
      null; -- OK.
   end if;
   TcTouch.Validate (Expected => "Vm0=1=m=",
                     Message => "Wrong evaluation (2)");

   if Third + Third in Rats.Zero | Rats.One | Rats.One + Rats.One then
      Report.Failed ("Wrong result (3)");
   else
      null; -- OK.
   end if;
   TcTouch.Validate (Expected => "+0=1=11+=",
                     Message => "Wrong evaluation (3)");

   if 2/4 not in Rats.Zero | Rats.One | 2/1 | 3/1 then
      null; -- OK.
   else
      Report.Failed ("Wrong result (4)");
   end if;
   TcTouch.Validate (Expected => "V0=1=V=V=",
                     Message => "Wrong evaluation (4)");


   -- Choices past first true test not evaluated:
   if 1/3 in Rats.Zero | +Third | Rats.One then
      null; -- OK.
   else
      Report.Failed ("Wrong result (5)");
   end if;
   TcTouch.Validate (Expected => "V0=p=",
                     Message => "Wrong evaluation (5)");

   if (1/3) - Third not in Rats.Zero | Rats.One | Rats.One + Rats.One then
      Report.Failed ("Wrong result (6)");
   else
      null; -- OK.
   end if;
   TcTouch.Validate (Expected => "V-0=",
                     Message => "Wrong evaluation (6)");

   -- Primitive rather than predefined equality used:
   -- (We try values that would not be equal for predefined equality. But
   -- note that TcTouch validation would fail if predefined equality is used.)

   if Third + Rats.One in Rats.Zero | 8/6 | Rats.One then
      null; -- OK.
   else
      Report.Failed ("Wrong equality used (7)");
   end if;
   TcTouch.Validate (Expected => "1+0=V=",
                     Message => "Wrong evaluation (7)");

   if Third + (2/4) not in Rats.Zero | Rats.One | 5/6 then
      Report.Failed ("Wrong equality used (8)");
   else
      null; -- OK.
   end if;
   TcTouch.Validate (Expected => "V+0=1=V=",
                     Message => "Wrong evaluation (8)");

   Report.Result;

end C452004;
