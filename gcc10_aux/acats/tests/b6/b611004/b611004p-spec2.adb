

-- Note: The following are provided for completeness. Processing these units
-- is not required.

separate (B611004P)
procedure Spec2 (P : in out Root) is                    -- OPTIONAL ERROR: {1}
begin
    P.N := P.N + 4;
end Spec2;
