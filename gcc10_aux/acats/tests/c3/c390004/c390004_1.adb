
with Report;
package body C390004_1 is

  procedure Set_Wheels( It: in out Vehicle; To_Count: in Natural ) is
  begin
    It.Wheels := To_Count;
  end Set_Wheels;

  function  Wheels( It: Vehicle ) return Natural is
  begin
    return It.Wheels;
  end Wheels;

  procedure Park      ( It: in out Vehicle ) is
  begin
    It.Parked := True;
  end Park;

  procedure UnPark    ( It: in out Vehicle ) is
  begin
    It.Parked := False;
  end UnPark;

  procedure TC_Check  ( It: in Vehicle; To_Equip: in Equipment ) is
  begin
    if To_Equip /= T_Veh then
      Report.Failed ("Failed, called Vehicle for "
                     & Equipment'Image(To_Equip));      
    end if;
  end TC_Check;

  procedure TC_Check  ( It: in Car; To_Equip: in Equipment ) is
  begin
    if To_Equip /= T_Car then
      Report.Failed ("Failed, called Car for "
                     & Equipment'Image(To_Equip));      
    end if;
  end TC_Check;

  procedure TC_Check  ( It: in Convertible; To_Equip: in Equipment ) is
  begin
    if To_Equip /= T_Con then
      Report.Failed ("Failed, called Convertible for "
                     & Equipment'Image(To_Equip));      
    end if;
  end TC_Check;

  procedure TC_Check  ( It: in Jeep; To_Equip: in Equipment ) is
  begin
    if To_Equip /= T_Jep then
      Report.Failed ("Failed, called Jeep for "
                     & Equipment'Image(To_Equip));      
    end if;
  end TC_Check;

  procedure Load_Passengers( It: in out Car; To_Count: in Natural ) is
  begin
    It.Passengers := To_Count;
    UnPark( It );
  end Load_Passengers;

  procedure Park( It: in out Car ) is
  begin
    It.Passengers := 0;
    Park( Vehicle( It ) );
  end Park;

  function  Passengers( It: Car ) return Natural is
  begin
    return It.Passengers;
  end Passengers;

  procedure Raise_Top( It: in out Convertible ) is
  begin
    It.Top_Up := True;
  end Raise_Top;

  procedure Lower_Top( It: in out Convertible ) is
  begin
    It.Top_Up := False;
  end Lower_Top;

  function  Top_Up   ( It: Convertible ) return Boolean is
  begin
    return It.Top_Up;
  end Top_Up;

  procedure Park     ( It: in out Convertible ) is
  begin
    It.Top_Up := True;
    Park( Car( It ) );
  end Park;

  procedure Raise_Windshield( It: in out Jeep ) is
  begin
    It.Windshield_Up := True;
  end Raise_Windshield;

  procedure Lower_Windshield( It: in out Jeep ) is
  begin
    It.Windshield_Up := False;
  end Lower_Windshield;

  function  Windshield_Up( It: Jeep ) return Boolean is
  begin
    return It.Windshield_Up;
  end Windshield_Up;

  procedure Park( It: in out Jeep ) is
  begin
    It.Windshield_Up := True;
    Park( Convertible( It ) );
  end Park;
end C390004_1;
