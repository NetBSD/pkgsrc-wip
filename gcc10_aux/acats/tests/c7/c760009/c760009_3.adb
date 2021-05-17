 
-- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

with Report;
with C760009_1;
package body C760009_3 is

  procedure Initialize( AC: in out Master_Control ) is
  begin
    AC.Data := 42;
    C760009_2.Initialize(C760009_2.Control(AC));
    C760009_1.TC_Trace( "Initialize Master_Control" );
  end Initialize;

  procedure Validate( AC: in out Master_Control ) is
  begin
    if AC.Data not in 0..1000 then
      Report.Failed("C760009_3.Control did not Initialize" );
    end if;
  end Validate;

end C760009_3;
