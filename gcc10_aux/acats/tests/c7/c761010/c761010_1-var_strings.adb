
package body C761010_1.Var_Strings is

    Some_Error: exception;

    procedure Initialize(X: in out Var_String) is
    begin
        Failed("Initialize should never be called");
        raise Some_Error;
    end Initialize;

    procedure Adjust(X: in out Var_String) is
    begin
        Failed("Adjust should never be called - case " & X.TC_Lab);
        raise Some_Error;
    end Adjust;

    procedure Finalize(X: in out Var_String) is
    begin
        Comment("Finalize called - case " & X.TC_Lab);
	C761010_1.TC_Finalize_Called := True;
    end Finalize;

    function "=" (X, Y: Var_String) return Boolean is
        -- Don't check the TC_Lab component, but do check the contents of the
	-- access values.
    begin
        if X.Length /= Y.Length then
            return False;
        end if;
        if X.Comp_3 /= Y.Comp_3 then
            return False;
        end if;
        if X.Comp_1 /= Y.Comp_1 then
            -- Still OK if the values are the same.
            if X.Comp_1 = null or else
               Y.Comp_1 = null or else
               X.Comp_1.all /= Y.Comp_1.all then
               return False;
            --else OK.
            end if;
        end if;
        if X.Comp_2 /= Y.Comp_2 then
            -- Still OK if the values are the same.
            if X.Comp_2 = null or else
               Y.Comp_2 = null or else
               X.Comp_2.all /= Y.Comp_2.all then
               return False;
            end if;
        end if;
        return True;
    end "=";

    procedure Check_Equal(X, Y: Var_String) is
    begin
        if X /= Y then
            Failed("Check_Equal of Var_String");
        end if;
    end Check_Equal;

begin
    Check_Equal(Another_String, Another_String);
end C761010_1.Var_Strings;
