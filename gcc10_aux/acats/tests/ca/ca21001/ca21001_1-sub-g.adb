
separate(CA21001_1.Sub)
function G(X: Integer) return Integer is

    package G_Sub is
        function H(X: Integer) return Integer;
            -- Returns X + 1.
        Not_Preelaborable: Integer := F; -- OK, by AI-2.
    end G_Sub;
    package body G_Sub is separate;

begin
    return G_Sub.H(X);
end G;
