 
      --=================================================================--
 
 -- Public child procedure.  This child procedure is NOT inherited.
 
 procedure BA11004_0.Not_Inherited_Proc (I : in     Visible_Integer;
                                         R :    out Visible_Integer) is
 begin
 
    -- Real body of child procedure goes here.
 
    R := I - 2;
 
 end BA11004_0.Not_Inherited_Proc;
