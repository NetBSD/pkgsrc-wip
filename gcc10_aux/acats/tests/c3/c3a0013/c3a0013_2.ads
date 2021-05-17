
with C3A0013_1;
package C3A0013_2 is
  type Car is new C3A0013_1.Vehicle with private;
  procedure TC_Validate( It     : Car;
                         TC_ID  : Character);
  function  Gear_Factor( It : Car ) return Natural;
private
  type Car is new C3A0013_1.Vehicle with record
    Displacement : Natural;
  end record;
end C3A0013_2;
