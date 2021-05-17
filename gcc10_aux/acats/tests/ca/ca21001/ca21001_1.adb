
procedure CA21001_1(X: out Integer) is
    function F return Integer is separate;

    package Sub is
        function G(X: Integer) return Integer;
            -- Returns X + 1.
        Not_Preelaborable: Integer := F; -- OK, by AI-2.
    end Sub;

    package body Sub is separate;

begin
    X := -1;
    X := F;
    X := Sub.G(X);
end CA21001_1;
