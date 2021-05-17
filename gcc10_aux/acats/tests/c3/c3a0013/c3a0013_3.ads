
with C3A0013_1;
package C3A0013_3 is
  type Truck is new C3A0013_1.Vehicle with private;
  procedure TC_Validate( It     : Truck;
                         TC_ID  : Character);
  function  Gear_Factor( It : Truck ) return Natural;
private
  type Truck is new C3A0013_1.Vehicle with record
    Displacement : Natural;
  end record;
end C3A0013_3;
