

     --===================================================================--


with B393006_0;
generic
   with package Formal_Package is new B393006_0 (<>);
package B393006_1 is

   type Derived_Type is new Formal_Package.Formal_Type with record
      Field : Boolean;                              -- Non-abstract derivative.
   end record;
   -- In the instance, inherits primitive subprograms of the actual.

end B393006_1;
