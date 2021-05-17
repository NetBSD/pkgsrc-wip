
separate(CA21001_1.Sub.G)
package body G_Sub is
    function H(X: Integer) return Integer is separate;
begin
    Not_Preelaborable := H(F); -- OK, by AI-2.
    if Not_Preelaborable /= 101 then
        raise Program_Error; -- Can't call Report.Failed, here,
            -- because Report is not preelaborated.
    end if;
end G_Sub;
