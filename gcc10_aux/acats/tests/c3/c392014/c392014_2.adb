
with Report;
use Report;
package body C392014_2 is

    procedure P (X : access T) is
    begin
	C392014_0.Result := C392014_0.Result + X.D + X.C2;
    end P;

    function Create (X : Integer) return T'Class is
	Y : T (D => X mod Ident_Int (20));
    begin
	Y.C2 := X / Ident_Int (600);
	return T'Class (Y);
    end Create;

end C392014_2;
