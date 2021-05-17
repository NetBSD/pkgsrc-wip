
with C761010_1.Var_Strings;
with C761010_1.Var_Strings.Types;
procedure C761010_1.Main is
begin
    -- Report.Test is called by the elaboration of C761010_1, and
    -- Report.Result is called by the finalization of C761010_1.
    -- This will happen before any objects are created, and after any
    -- are finalized.
    null;
end C761010_1.Main;
