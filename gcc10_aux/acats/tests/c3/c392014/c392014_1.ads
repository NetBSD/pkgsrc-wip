
with C392014_0;
package C392014_1 is
    type T is new C392014_0.T with private;
    function Create (X : Integer) return T'Class;
private
    type T is new C392014_0.T with
	record
	    C1 : Integer;
	end record;
    procedure P (X : access T);
end C392014_1;
