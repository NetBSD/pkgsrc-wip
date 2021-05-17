
package C392014_1.Child is
    type T is new C392014_1.T with private;
    procedure P (X : access T);
    function Create (X : Integer) return T'Class;
private
    type T is new C392014_1.T with
	record
	    C1C : Integer;
	end record;
end C392014_1.Child;
