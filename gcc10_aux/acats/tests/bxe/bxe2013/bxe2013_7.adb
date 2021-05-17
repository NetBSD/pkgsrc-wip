        -- Subprogram cannot be remote types.

function BXE2013_7(X: Integer) return Boolean is
begin
    return BXE2013_7(X); -- Can't have a missing "return".
end BXE2013_7;
