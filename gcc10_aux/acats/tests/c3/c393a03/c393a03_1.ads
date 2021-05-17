
------------------------------------------------------------------- C393A03_1

with C393A03_0;
package C393A03_1 is

  type Modular_Object is new C393A03_0.Counting_Object with private;
  -- inherits Initialize, Bump, Zero and Value,
  -- inherits abstract Swap, Create and Clear

  procedure Swap( A,B: in out Modular_Object );
  procedure Clear( It: in out Modular_Object );
  procedure Set_Max( It : in out Modular_Object; Value : Natural );
  function  Create return Modular_Object;

private

  type Modular_Object is new C393A03_0.Counting_Object with
    record
      Max_Value : Natural;
    end record;

end C393A03_1;
