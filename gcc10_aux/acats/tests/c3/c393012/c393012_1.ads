
with C393012_0;
package C393012_1 is
  type Economy is new C393012_0.Ticket with null record;
  function Display( T: Economy ) return String;
  function Service( T: Economy ) return String;

  type Meal_Designator is ( B, L, D, V, SN );

  type First is new C393012_0.Ticket with
    record
      Meal : Meal_Designator;
    end record;
  function Display( T: First ) return String;
  function Service( T: First ) return String;
  procedure Set_Meal( T: in out First; To_Meal : Meal_Designator );

end C393012_1;
