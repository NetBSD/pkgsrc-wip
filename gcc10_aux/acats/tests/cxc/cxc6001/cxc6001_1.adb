
--------------------------------------------------------------------------

with Report;
package body CXC6001_1 is

  procedure Check_Reference_Semantics( Material : in out Element ) is
  -- perform a little alchemy here
  begin
    Chlorine := ( Atomic_Weight => 196 );
    if Material.Atomic_Weight = 35 then
      Report.Failed("Volatile Element not passed by reference");
    end if;
  end Check_Reference_Semantics;

  procedure Check_Reference_Semantics( Material : in out Compound ) is
  -- perform a little magic here
  begin
    Material := ( 1 => (Atomic_Weight => 16) );
    if Smog(1).Atomic_Weight /= 16 then
      Report.Failed("Volatile Components not passed by reference");
    end if;
  end Check_Reference_Semantics;

end CXC6001_1;
