
-----------------------------------------------------------------------------

with F393A00_0;
package body C393A03_1 is

  procedure Swap( A,B: in out Modular_Object ) is
    T : constant Modular_Object := B;
  begin
    F393A00_0.TC_Touch('1');
    B := A;
    A := T;
  end Swap;

  procedure Clear( It: in out Modular_Object ) is
  begin
    F393A00_0.TC_Touch('2');
    null;
  end Clear;

  procedure Set_Max( It : in out Modular_Object; Value : Natural ) is
  begin
    F393A00_0.TC_Touch('3');
    It.Max_Value := Value;
  end Set_Max;

  function  Create return Modular_Object is
    AMO : Modular_Object;
  begin
    F393A00_0.TC_Touch('4');
    AMO.Max_Value := Natural'Last;
    return AMO;
  end Create;

end C393A03_1;
