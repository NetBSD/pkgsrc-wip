
with Ada.Finalization;
with C760013_0;
use C760013_0;
with Report;
use Report;
procedure C760013 is

    type T is tagged
	record
	    C1 : Ctrl1;
	    C2 : Ctrl2 := (Ada.Finalization.Controlled with
			   C => Ident_Int (23));
	end record;

    type Nt is new T with
	record
	    C3 : Float;
	end record;

    X : Nt;

begin
    Test ("C760013",
	  "Check that Initialize is not called for " &
	     "default-initialized subcomponents of the ancestor type of an " &
	     "extension aggregate");

    X := (T with C3 => 5.0);

    if X.C1.C /= Ident_Int (47) then
	Failed ("Initialize not called for type Ctrl1");
    end if;
    if X.C2.C /= Ident_Int (23) then
	Failed ("Initial value not assigned for type Ctrl2");
    end if;

    Result;
end C760013;

