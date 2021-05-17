
     --==================================================================--

with C540001_1;
package C540001_5 is
   type New_Tagged is new C540001_1.Tagged_Type with
      record
         C2 : C540001_1.Mixed;
      end record;

    -- Inherits Get_Tagged (P : New_Tagged) return C540001_0.Int;
    -- Note that the return type of the inherited function is not
    -- nameable here.

   procedure Assign_Tagged (P1 : in     New_Tagged;
                            P2 :    out New_Tagged);

end C540001_5;
