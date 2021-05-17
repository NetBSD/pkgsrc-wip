
with C392014_0;
with C392014_1;
package C392014_2 is
    type T is new C392014_0.T with private;
    function Create (X : Integer) return T'Class;
private
    type T is new C392014_1.T with
	record
	    C2 : Integer;
	end record;
    procedure P (X : access T);
end C392014_2;
