
     --==================================================================--

generic               

   type Formal_Scalar is range <>;  

   FSO : Formal_Scalar;

package C540001_2 is              

   type Enum is (Alpha, Beta, Theta);

   procedure Assign_Enum (ET : out Enum);

end C540001_2;
