

with C761013_0;
use C761013_0;
with Report;
use Report;
with TCTouch;
procedure C761013 is

    Outer : Ctrl;

    procedure Subtest_1 is
	X : Ctrl renames F;
	Y : Integer renames F.C;
	Z : User renames U;
    begin
	if X.Finalized or X.C /= Ident_Int (15) then
	    Failed
	       ("Function result finalized too early - X1");
	end if;
	if Y /= Ident_Int (15) then
	    Failed
	       ("Function result finalized too early - Y1");
	end if;
	if Z.Component.Finalized or Z.Component.C /= Ident_Int (15) then
	    Failed
	       ("Function result finalized too early - Z1");
	end if;
    end Subtest_1;

    procedure Subtest_3 is
	X : Ctrl renames Outer;
    begin
	if X.Finalized or X.C /= Ident_Int (15) then
	    Failed
	       ("Outer object finalized way too early - X3");
	end if;
    end Subtest_3;

begin
    Test ("C761013",
	  "Check that a function call for a which a part is renamed as an object " &
          "is not finalized until the unit or block that directly contains the " &
          "renaming is left. Also check that a renaming is not finalized too " &
          "soon.");

    TCTouch.Validate (Expected => "i",
                      Message  => "Initial object");

    Subtest_1;

    TCTouch.Validate (Expected => "iFfiFfiUffff",
                      Message  => "Renames in subprogram");

    Subtest_2: declare
	X : Ctrl renames F;
	Y : Integer renames F.C;
	Z : User renames U;
    begin
	if X.Finalized or X.C /= Ident_Int (15) then
	    Failed
	       ("Function result finalized too early - X2");
	end if;
	if Y /= Ident_Int (15) then
	    Failed
	       ("Function result finalized too early - Y2");
	end if;
	if Z.Component.Finalized or Z.Component.C /= Ident_Int (15) then
	    Failed
	       ("Function result finalized too early - Z1");
	end if;
    end Subtest_2;

    TCTouch.Validate (Expected => "iFfiFfiUffff",
                      Message  => "Renames in block");

    Subtest_3;

    if Outer.Finalized or Outer.C /= Ident_Int (15) then
        Failed
	   ("Outer object finalized too early - Outer3");
    end if;

    Subtest_4: declare
        X : Ctrl renames Outer;
    begin
	if X.Finalized or X.C /= Ident_Int (15) then
	    Failed
	       ("Outer object finalized way too early - X4");
	end if;
    end Subtest_4;

    if Outer.Finalized or Outer.C /= Ident_Int (15) then
        Failed
	   ("Outer object finalized too early - Outer4");
    end if;

    Result;
end C761013;

