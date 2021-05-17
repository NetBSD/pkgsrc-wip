
separate(CA21001_1)
package body Sub is
    package Sub_Sub is
        -- Empty.
    end Sub_Sub;
    package body Sub_Sub is separate;

    function G(X: Integer) return Integer is separate;
begin
    Not_Preelaborable := G(F); -- OK, by AI-2.
    if Not_Preelaborable /= 101 then
        raise Program_Error; -- Can't call Report.Failed, here,
            -- because Report is not preelaborated.
    end if;
end Sub;
