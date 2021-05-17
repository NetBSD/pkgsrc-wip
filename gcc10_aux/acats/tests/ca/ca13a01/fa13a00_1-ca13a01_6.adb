
     --==================================================================--

-- Context clauses required for visibility needed by separate subunit.

with FA13A00_0;                           -- Building Manager

with FA13A00_1.FA13A00_2;                 -- Floor Calculation (private)

with FA13A00_1.FA13A00_3;                 -- Move Elevator

use  FA13A00_0;

procedure FA13A00_1.CA13A01_6 is          -- Express Operation

   -- Other type definitions in real application.

   procedure GoTo_Penthouse is separate;

begin
   GoTo_Penthouse;

end FA13A00_1.CA13A01_6;
