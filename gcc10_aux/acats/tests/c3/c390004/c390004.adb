
with Report;
with Ada.Tags;
with C390004_1;
procedure C390004 is
  package DMV renames C390004_1;

  The_Vehicle     : aliased DMV.Vehicle;
  The_Car         : aliased DMV.Car;
  The_Convertible : aliased DMV.Convertible;
  The_Jeep        : aliased DMV.Jeep;

  type C_Reference is access all DMV.Car'Class;
  type V_Reference is access all DMV.Vehicle'Class;

  Designator : V_Reference;
  Storage    : Natural;

  procedure Valet( It: in out DMV.Vehicle'Class ) is
  begin
    DMV.Park( It );
  end Valet;

  procedure TC_Match( Object: DMV.Vehicle'Class;
                      Taglet: Ada.Tags.Tag;
                      Where : String ) is
    use Ada.Tags;
  begin
    if Object'Tag /= Taglet then
      Report.Failed("Tag mismatch: " & Where);
    end if;
  end TC_Match;

  procedure Parking_Validation( It: DMV.Vehicle; TC_Message: String ) is
  begin
    if DMV.Wheels( It ) /= 1  or not It.Parked then
      Report.Failed ("Failed Vehicle " & TC_Message);
    end if;
  end Parking_Validation;

  procedure Parking_Validation( It: DMV.Car; TC_Message: String ) is
  begin
    if DMV.Wheels( It ) /= 2 or DMV.Passengers( It ) /= 0
       or not It.Parked then
      Report.Failed ("Failed Car " & TC_Message);
    end if;
  end Parking_Validation;

  procedure Parking_Validation( It: DMV.Convertible;
                                TC_Message: String ) is
  begin
    if DMV.Wheels( It ) /= 3 or DMV.Passengers( It ) /= 0
       or not DMV.Top_Up( It ) or not It.Parked then
      Report.Failed ("Failed Convertible " & TC_Message);
    end if;
  end Parking_Validation;

  procedure Parking_Validation( It: DMV.Jeep; TC_Message: String ) is
  begin
    if DMV.Wheels( It ) /= 4 or DMV.Passengers( It ) /= 0
       or not DMV.Top_Up( It ) or not DMV.Windshield_Up( It )
       or not It.Parked then
      Report.Failed ("Failed Jeep " & TC_Message);
    end if;
  end Parking_Validation;

  function Wash( It: V_Reference; TC_Expect : Ada.Tags.Tag )
                                    return DMV.Vehicle'Class is
    This_Machine : DMV.Vehicle'Class := It.all;
  begin
    TC_Match( It.all, TC_Expect, "Class-wide object in Wash" );
    Storage := DMV.Wheels( This_Machine );
    return This_Machine;
  end Wash;

  function Wash( It: C_Reference; TC_Expect : Ada.Tags.Tag )
                                    return DMV.Car'Class is
    This_Machine : DMV.Car'Class := It.all;
  begin
    TC_Match( It.all, TC_Expect, "Class-wide object in Wash" );
    Storage := DMV.Wheels( This_Machine );
    return This_Machine;
  end Wash;

begin

  Report.Test( "C390004", "Check that the tags of allocated objects "
                        & "correctly identify the type of the allocated "
                        & "object.  Check that tags resulting from "
                        & "normal and view conversions.  Check tags of "
                        & "accessed values designating aliased objects. "
                        & "Check function result tags" );

  DMV.Set_Wheels( The_Vehicle, 1 );
  DMV.Set_Wheels( The_Car, 2 );
  DMV.Set_Wheels( The_Convertible, 3 );
  DMV.Set_Wheels( The_Jeep, 4 );

  Valet( The_Vehicle );
  Valet( The_Car );
  Valet( The_Convertible );
  Valet( The_Jeep );

  Parking_Validation( The_Vehicle,     "setup" );
  Parking_Validation( The_Car,         "setup" );
  Parking_Validation( The_Convertible, "setup" );
  Parking_Validation( The_Jeep,        "setup" );

-- Check that the tags of allocated objects correctly identify the type
-- of the allocated object.

  Designator := new DMV.Vehicle;
  DMV.TC_Check( Designator.all, DMV.T_Veh );
  TC_Match( Designator.all, DMV.Vehicle'Tag, "allocated Vehicle" );

  Designator := new DMV.Car;
  DMV.TC_Check( Designator.all, DMV.T_Car );
  TC_Match( Designator.all, DMV.Car'Tag, "allocated Car");

  Designator := new DMV.Convertible;
  DMV.TC_Check( Designator.all, DMV.T_Con );
  TC_Match( Designator.all, DMV.Convertible'Tag, "allocated Convertible" );

  Designator := new DMV.Jeep;
  DMV.TC_Check( Designator.all, DMV.T_Jep );
  TC_Match( Designator.all, DMV.Jeep'Tag, "allocated Jeep" );

-- Check that view conversion causes the correct dispatch
  DMV.TC_Check( DMV.Vehicle( The_Jeep ),     DMV.T_Veh );
  DMV.TC_Check( DMV.Car( The_Jeep ),         DMV.T_Car );
  DMV.TC_Check( DMV.Convertible( The_Jeep ), DMV.T_Con );

-- And that view conversion does not change the tag
  TC_Match( DMV.Vehicle( The_Jeep ),     DMV.Jeep'Tag, "View Conv Veh" );
  TC_Match( DMV.Car( The_Jeep ),         DMV.Jeep'Tag, "View Conv Car" );
  TC_Match( DMV.Convertible( The_Jeep ), DMV.Jeep'Tag, "View Conv Jep" );

-- Check that the tags of accessed values designating aliased objects
-- correctly identify the type of the object.
  Designator := The_Vehicle'Access;
  DMV.TC_Check( Designator.all, DMV.T_Veh );
  TC_Match( Designator.all, DMV.Vehicle'Tag, "aliased Vehicle" );

  Designator := The_Car'Access;
  DMV.TC_Check( Designator.all, DMV.T_Car );
  TC_Match( Designator.all, DMV.Car'Tag, "aliased Car" );

  Designator := The_Convertible'Access;
  DMV.TC_Check( Designator.all, DMV.T_Con );
  TC_Match( Designator.all, DMV.Convertible'Tag, "aliased Convertible" );

  Designator := The_Jeep'Access;
  DMV.TC_Check( Designator.all, DMV.T_Jep );
  TC_Match( Designator.all, DMV.Jeep'Tag, "aliased Jeep" );

-- Check that the tag of a function result correctly evaluates.
-- Check this for class-wide functions.  The tag of a class-wide
-- function result should be the tag appropriate to the actual value
-- returned, not the tag of the ancestor type.
  Function_Check: declare
    A_Vehicle     : V_Reference := new DMV.Vehicle'( The_Vehicle );
    A_Car         : C_Reference := new DMV.Car'( The_Car );
    A_Convertible : C_Reference := new DMV.Convertible'( The_Convertible );
    A_Jeep        : C_Reference := new DMV.Jeep'( The_Jeep );
  begin
    DMV.Unpark( A_Vehicle.all );
    DMV.Load_Passengers( A_Car.all, 5 );
    DMV.Load_Passengers( A_Convertible.all, 6 );
    DMV.Load_Passengers( A_Jeep.all, 7 );
    DMV.Lower_Top( DMV.Convertible(A_Convertible.all) );
    DMV.Lower_Top( DMV.Jeep(A_Jeep.all) );
    DMV.Lower_Windshield( DMV.Jeep(A_Jeep.all) );

    if DMV.Wheels( Wash( A_Jeep, DMV.Jeep'Tag ) ) /= 4
       or Storage /= 4 then
      Report.Failed("Did not correctly wash Jeep");
    end if;

    if DMV.Wheels( Wash( A_Convertible, DMV.Convertible'Tag ) ) /= 3
       or Storage /= 3 then
      Report.Failed("Did not correctly wash Convertible");
    end if;

    if DMV.Wheels( Wash( A_Car, DMV.Car'Tag ) ) /= 2
       or Storage /= 2 then
      Report.Failed("Did not correctly wash Car");
    end if;

    if DMV.Wheels( Wash( A_Vehicle, DMV.Vehicle'Tag ) ) /= 1
       or Storage /= 1 then
      Report.Failed("Did not correctly wash Vehicle");
    end if; 

  end Function_Check;

  Report.Result;
end C390004;
