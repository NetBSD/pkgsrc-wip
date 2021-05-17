
     --==================================================================--

package body BB20001_7 is 
   procedure Proc_7 is
   begin
      null;
   exception
      when Exception_7                                => null;        -- OK.
      when Formal_Pck7.RN_FPck2.RN_Common_Exception_1 => null;        -- OK.
      
      when Formal_Pck7.RN_FPck2.FP_Exception_1        => null;        -- ERROR:
                         -- Exception was declared in a generic formal package.

      when Formal_Pck7.Exception_2                    => null;        -- ERROR:
                         -- Exception was declared in a generic formal package.
      
   end Proc_7;

end BB20001_7;
