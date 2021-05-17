
--------------------------------------------------------------------------

package CXC6001_1 is

  ------------ Subtest 3, Volatile Reference Semantics, Object

  type Element is record
    Atomic_Weight : Natural;
  end record;

  pragma Volatile( Element );

  Chlorine : Element := (Atomic_Weight => 35);

  pragma Volatile( Chlorine );

  procedure Check_Reference_Semantics( Material : in out Element );

  ------------ Subtest 4, Volatile Reference Semantics, Component

  type Compound is array(1..1) of Element;  -- By reference type since
                                            -- subcomponent is volatile

  Smog : Compound := ( 1 => (Atomic_Weight => 12) );

  procedure Check_Reference_Semantics( Material : in out Compound );

end CXC6001_1;
