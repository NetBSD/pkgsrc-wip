
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
package body LXH4001_0 is

  function Existence return Boolean is
  begin
    return Report.Ident_Bool(True);
  end Existence;

end LXH4001_0;
