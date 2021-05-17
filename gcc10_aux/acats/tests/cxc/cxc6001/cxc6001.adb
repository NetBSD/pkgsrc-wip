
--------------------------------------------------------------------------

with Report;
with CXC6001_0;
with CXC6001_1;
procedure CXC6001 is

begin  -- Main test procedure.

   Report.Test ("CXC6001", "Check semantics for atomic and volatile " &
                           "types" );
   
  ------------ Subtest 1, Atomic Reference Semantics, Object

   CXC6001_0.Check_Reference_Semantics( CXC6001_0.Plutonium );

  ------------ Subtest 2, Atomic Reference Semantics, Component

   CXC6001_0.Check_Reference_Semantics( CXC6001_0.Water );

  ------------ Subtest 3, Volatile Reference Semantics, Object

   CXC6001_1.Check_Reference_Semantics( CXC6001_1.Chlorine );

  ------------ Subtest 4, Volatile Reference Semantics, Component

   CXC6001_1.Check_Reference_Semantics( CXC6001_1.Smog );

   Report.Result;

end CXC6001;
