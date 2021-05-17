
     --==================================================================--

package body BB20001_2 is                                  

   function Do_Something (P : Formal_Pck2.Element_Type) return 
     Formal_Pck2.Element_Type is 
       Res : Formal_Pck2.Element_Type := P;
   begin
      return Res;
   exception
      when Exception_2           => null;                             -- OK.
      when RN_Common_Exception_2 => null;                             -- OK.

      when RN_FP_Exception_2     => null;                             -- ERROR:
                         -- Exception was declared in a generic formal package.

   end Do_Something;  

end BB20001_2;
