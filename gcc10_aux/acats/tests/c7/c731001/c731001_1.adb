
package body C731001_1 is

    Verbose: Boolean := False;

    procedure Check_String(X, Y: String) is
    begin
        if Verbose then
            Comment("""" & X & """ = """ & Y & """?");
        end if;
        if X /= Y then
            Failed("""" & X & """ should be """ & Y & """");
        end if;
    end Check_String;

    function Check_String(X, Y: String) return String is
    begin
        Check_String(X, Y);
        return X;
    end Check_String;

end C731001_1;
