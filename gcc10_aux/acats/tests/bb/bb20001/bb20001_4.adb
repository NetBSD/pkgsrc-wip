
     --==================================================================--

procedure BB20001_4 is
   RN_FP_Exception_4     : exception renames Formal_Pck4.FP_Exception_1;
   RN_Common_Exception_4 : exception renames Formal_Pck4.RN_Common_Exception_1;
begin
   null;
exception
   when RN_Common_Exception_4 => null;                                -- OK.

   when RN_FP_Exception_4     => null;                                -- ERROR:
                         -- Exception was declared in a generic formal package.
end BB20001_4;      
