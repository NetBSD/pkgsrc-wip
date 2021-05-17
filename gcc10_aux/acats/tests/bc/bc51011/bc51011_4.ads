

-- No body for BC51011_3;


     --==================================================================--


with BC51011_3;
generic  -- Formal tagged private type; disc. subtype is formal of formal pack.
   with package Signature is new BC51011_3 (<>);
   type Formal_Type (Disc : Signature.Discrete_Type) is tagged private;
package BC51011_4 is end;
