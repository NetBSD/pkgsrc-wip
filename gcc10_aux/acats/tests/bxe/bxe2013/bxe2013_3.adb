        -- Subprogram cannot be shared passive.

function BXE2013_3(X: Integer) return Boolean is
begin
    return BXE2013_3(X); -- Can't have a missing "return".
end BXE2013_3;
