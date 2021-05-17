
     --==================================================================--

procedure BB20001_3 is                                   
begin
   null;
exception
   when Formal_Pck3.RN_Common_Exception_1 => null;                       -- OK.

   when Formal_Pck3.FP_Exception_1     => null;                       -- ERROR:
                         -- Exception was declared in a generic formal package.
end BB20001_3;      
