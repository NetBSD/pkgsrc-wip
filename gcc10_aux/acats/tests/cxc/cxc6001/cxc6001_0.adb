
with Report;
package body CXC6001_0 is

  procedure Check_Reference_Semantics( Material : in out Element ) is
  -- perform a little alchemy here...
  -- this checks that the parameter is passed by reference by changing
  -- the object that was passed, and then checking that the parameter
  -- contains the updated value.  If the parameter was copied, the value
  -- will be that at the time the parameter was passed.
  begin
    Plutonium := ( Atomic_Weight => 195 );
    if Material.Atomic_Weight /= 195 then
      Report.Failed("Atomic Element not passed by reference");
    end if;
  end Check_Reference_Semantics;

  procedure Check_Reference_Semantics( Material : in out Compound ) is
  -- perform a little alchemy here
  begin
    Material := ( 1 => (Atomic_Weight => 12) );
    if Water(1).Atomic_Weight /= 12 then
      Report.Failed("Atomic Components not passed by reference");
    end if;
  end Check_Reference_Semantics;

end CXC6001_0;
