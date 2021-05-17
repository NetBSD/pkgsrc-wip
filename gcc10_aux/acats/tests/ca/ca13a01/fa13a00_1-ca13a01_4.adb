
     --==================================================================--

-- Context clauses required for visibility needed by separate subunit.

with FA13A00_0;                           -- Building Manager

with FA13A00_1.FA13A00_2;                 -- Floor Calculation (private)
                                         
with FA13A00_1.FA13A00_3;                 -- Move Elevator

use  FA13A00_0;                           

package body FA13A00_1.CA13A01_4 is              

   procedure Check_System is separate;

end FA13A00_1.CA13A01_4;
