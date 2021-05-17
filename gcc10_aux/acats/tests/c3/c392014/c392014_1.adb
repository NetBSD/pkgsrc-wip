
with Report;
use Report;
with C392014_1.Child;
package body C392014_1 is

    procedure P (X : access T) is
    begin
	C392014_0.Result := C392014_0.Result + X.D + X.C1;
    end P;

    function Create (X : Integer) return T'Class is
    begin
	case X mod Ident_Int (2) is
	    when 0 =>
		return C392014_1.Child.Create (X / Ident_Int (2));
	    when 1 =>
		declare
		    Y : T (D => (X / Ident_Int (2)) mod Ident_Int (20));
		begin
		    Y.C1 := X / Ident_Int (40);
		    return T'Class (Y);
		end;
	    when others =>
		null;
	end case;
    end Create;

end C392014_1;
