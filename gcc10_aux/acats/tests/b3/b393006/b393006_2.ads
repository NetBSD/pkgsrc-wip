
     --===================================================================--

generic
   type Formal_Type is abstract tagged private;     -- Abstract formal private
package B393006_2 is                                -- type.

   type Derived_Type2 is new Formal_Type
      with null record;                             -- Non-abstract derivative.
   -- In the instance, inherits primitive subprograms of the actual.

end B393006_2;
