
     --==================================================================--

with FA13A00_1.CA13A01_5;                 -- Emergency Operation
                                          -- implicitly with Basic Elevator
                                          -- Operations

with FA13A00_1.CA13A01_6;                 -- Express Operation

with Report;

procedure CA13A01 is

begin

   Report.Test ("CA13A01", "Check that subunits declared in non-generic " &
                "child units of a public parent have the same visibility " &
                "into its parent, its parent's siblings, and packages on " &
                "which its parent depends");

   -- Go to Penthouse.

   FA13A00_1.CA13A01_6;

   -- Call emergency operation.

   FA13A00_1.CA13A01_5.Emergency;

   if not FA13A00_1.TC_Operation then
      Report.Failed ("Incorrect elevator operation");
   end if;

   Report.Result;

end CA13A01;
