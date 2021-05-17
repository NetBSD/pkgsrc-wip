

------------------------------------------------------------------

with Ada.Task_Attributes;
with CXC7002_0;
package CXC7002_1 is new Ada.Task_Attributes (
    Attribute => CXC7002_0.Int_Array,
    Initial_Value => CXC7002_0.Countdown);   -- 3,2,1
