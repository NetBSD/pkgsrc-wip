
with Report;
use Report;
with C392014_0;
with C392014_1.Child;
with C392014_2;
procedure C392014 is

    subtype S0 is C392014_0.T'Class;
    subtype S1 is C392014_1.T'Class;

    X0 : aliased C392014_0.T'Class := C392014_0.Create (Ident_Int (5218));
    X1 : aliased C392014_1.T'Class := C392014_1.Create (Ident_Int (8253));

    Y0 : aliased S0 := C392014_0.Create (Ident_Int (2693));
    Y1 : aliased S1 := C392014_1.Create (Ident_Int (5622));

    procedure TC_Check (Subtest : String; Expected : Integer) is
    begin
	if C392014_0.Result = Expected then
	    Comment ("Subtest " & Subtest & " Passed");
	else
	    Failed ("Subtest " & Subtest & " Failed");
	end if;
	C392014_0.Result := Ident_Int (0);
    end TC_Check;

begin
    Test ("C392014",
	  "Check that objects designated by X'Access " &
	     "(where X is of a class-wide type) and New T'Class'(...) " &
	     "are dynamically tagged and can be used in dispatching " &
	     "calls");

    C392014_0.P (X0'Access);
    TC_Check ("X0'Access", Ident_Int (29));
    C392014_0.P (new C392014_0.T'Class'(C392014_0.Create (Ident_Int (12850))));
    TC_Check ("New C392014_0.T'Class", Ident_Int (27));
    C392014_1.P (X1'Access);
    TC_Check ("X1'Access", Ident_Int (212));
    C392014_1.P (new C392014_1.T'Class'(C392014_1.Create (Ident_Int (2031))));
    TC_Check ("New C392014_1.T'Class", Ident_Int (65));
    C392014_0.P (Y0'Access);
    TC_Check ("Y0'Access", Ident_Int (18));
    C392014_0.P (new S0'(C392014_0.Create (Ident_Int (6893))));
    TC_Check ("New S0", Ident_Int (20));
    C392014_1.P (Y1'Access);
    TC_Check ("Y1'Access", Ident_Int (18));
    C392014_1.P (new S1'(C392014_1.Create (Ident_Int (1861))));
    TC_Check ("New S1", Ident_Int (56));

    Result;
end C392014;
