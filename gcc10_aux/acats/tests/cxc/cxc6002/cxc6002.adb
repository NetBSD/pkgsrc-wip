
------------------------------------------------------------------- CXC6002

with Report;
with CXC6002_1;
procedure CXC6002 is

begin  -- Main test procedure.

   Report.Test ("CXC6002", "Check semantics for volatile " &
                           "composite types" );
   
  ------------ Subtest 1, Volatile Copy Semantics, Object

   CXC6002_1.Check_Copy_Semantics( CXC6002_1.Hoover,
                                   CXC6002_1.Hoover );

  ------------ Subtest 2, Volatile Copy Semantics, Component

   CXC6002_1.Check_Copy_Semantics( CXC6002_1.Grid(1),
                                   CXC6002_1.Grid(1) );

   Report.Result;

end CXC6002;
