 
package body C760007_0 is

  procedure Adjust( Object: in out Controlled ) is
  begin
    Adjust_Count := Adjust_Count +1;
  end Adjust;

  procedure Adjust( Object: in out Child ) is
  begin
    Child_Adjust_Count := Child_Adjust_Count +1;
  end Adjust;

end C760007_0;
