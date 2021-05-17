
with Report;
use Report;
with C392014_0;
package body C392014_1.Child is

    procedure P (X : access T) is
    begin
	C392014_0.Result := C392014_0.Result + X.D + X.C1 + X.C1C;
    end P;

    function Create (X : Integer) return T'Class is
	Y : T (D => X mod Ident_Int (20));
    begin
	Y.C1 := (X / Ident_Int (20)) mod Ident_Int (20);
	Y.C1C := X / Ident_Int (400);
	return T'Class (Y);
    end Create;

end C392014_1.Child;
