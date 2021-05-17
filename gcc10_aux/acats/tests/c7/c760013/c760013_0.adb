
with Report;
use Report;
package body C760013_0 is

    procedure Initialize (Obj1 : in out Ctrl1) is
    begin
	Obj1.C := Ident_Int (47);
    end Initialize;

    procedure Initialize (Obj2 : in out Ctrl2) is
    begin
	Failed ("Initialize called for type Ctrl2");
    end Initialize;

end C760013_0;
