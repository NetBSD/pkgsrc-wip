

     --==================================================================--


-- For the generic below, the subprogram P used in P'Access will be declared
-- within the instance itself. The accessibility of P is therefore tied to the
-- nesting level of the instance. The access type S of P'Access is also passed
-- as an actual. The nesting level of P must be at least as high as that of S.

generic
   type Formal_Acc is access procedure (I : Integer); 
package B3A2010_1 is

   procedure Designated_Proc_A (I : Integer);

   AP_GA : constant Formal_Acc := Designated_Proc_A'Access;

end B3A2010_1;
