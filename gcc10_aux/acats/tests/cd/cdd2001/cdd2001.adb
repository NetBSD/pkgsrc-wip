
with Ada.Exceptions;
use Ada.Exceptions;
with CDD2001_0;
use CDD2001_0;
with Io_Exceptions;
use Io_Exceptions;
with Report;
use Report;
procedure CDD2001 is

    subtype Int is Integer range -20 .. 20;

    type R (D : Int) is
	record
	    C1 : Character := Ident_Char ('a');
	    case D is
		when 0 .. 20 =>
		    C2 : String (1 .. D) := (others => Ident_Char ('b'));
		when others =>
		    C3, C4 : Float := Float (-D);
	    end case;
	end record;

    S : aliased My_Stream (200);

begin
    Test
       ("CDD2001",
	   "Check that the default implementation of Read and Input " &
	   "raise End_Error if the end of stream is reached before the " &
           "reading of a value is completed");

    Read:
	declare
	    X : R (Ident_Int (13));
	begin
	    Clear (S);

	    -- A complete object.
	    R'Write (S'Access, X);
	    X.C1 := Ident_Char ('A');
	    X.C2 := (others => Ident_Char ('B'));
	    R'Read (S'Access, X);
	    if X.C1 /= Ident_Char ('a') or X.C2 /=
					      (1 .. 13 => Ident_Char ('b')) then
		Failed ("Read did not produce the expected result");
	    end if;

	    Clear (S);

	    -- Not enough data.
	    Character'Write (S'Access, 'a');
	    String'Write (S'Access, "bbb");

	    begin
		R'Read (S'Access, X);
		Failed
		   ("No exception raised when the end of stream is reached " &
		    "before the reading of a value is completed - 1");
	    exception
		when End_Error =>
		    null;
		when E: others =>
		    Failed ("Wrong Exception " & Exception_Name (E) &
			    " - " & Exception_Information (E) &
			    " - " & Exception_Message (E) & " - 1");
	    end;

	end Read;

    Input:
	declare
	    X : R (Ident_Int (-11));
	begin
	    Clear (S);

	    -- A complete object.
	    R'Output (S'Access, X);
	    X.C1 := Ident_Char ('A');
	    X.C3 := 4.0;
	    X.C4 := 5.0;
	    X := R'Input (S'Access);
	    if X.C1 /= Ident_Char ('a') or X.C3 /= 11.0 or X.C4 /= 11.0 then
		Failed ("Input did not produce the expected result");
	    end if;

	    Clear (S);

	    -- Not enough data.
	    Integer'Output (S'Access, Ident_Int (-11)); -- The discriminant
	    Character'Output (S'Access, 'a');
	    Float'Output (S'Access, 11.0);

	    begin
		X := R'Input (S'Access);
		Failed
		   ("No exception raised when the end of stream is reached " &
		    "before the reading of a value is completed - 2");
	    exception
		when End_Error =>
		    null;
		when E: others =>
		    Failed ("Wrong exception " & Exception_Name (E) &
			    " - " & Exception_Message (E) & " - 2");
	    end;

	end Input;

    Result;
end CDD2001;

