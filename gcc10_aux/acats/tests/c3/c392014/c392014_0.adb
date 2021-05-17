
with Report;
use Report;
with C392014_1.Child;
with C392014_2;
package body C392014_0 is

    function Create (X : Integer) return T'Class is
    begin
	case X mod 3 is
	    when 0 =>
		return C392014_1.Create (X / Ident_Int (3));
	    when 1 =>
		return C392014_1.Child.Create (X / Ident_Int (3));
	    when 2 =>
		return C392014_2.Create (X / Ident_Int (3));
	    when others =>
		null;
	end case;
    end Create;

end C392014_0;
