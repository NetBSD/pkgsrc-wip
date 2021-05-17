 
 -- No body for BA11004_2.
 
      --=================================================================--
 
 with BA11004_2;
 use  BA11004_2;              -- New_Visible_Int directly visible,
                              -- Inherited_Function directly visible,
                              -- Inherited_Procedure directly visible.
 with BA11004_0.Not_Inherited_Proc;
 with BA11004_0.Not_Inherited_Func; 
 
 use BA11004_0;
 
 procedure BA11004 is
 
    Client_Integer1 : New_Visible_Int := 36;
 
    Client_Integer2 : New_Visible_Int;
 
    Client_Integer3 : New_Visible_Int  
                    := Inherited_Function (Client_Integer1);   -- OK
 
    Client_Integer4 : New_Visible_Int  
                    := Not_Inherited_Func (Client_Integer1);   -- ERROR:
                                  -- function not defined for this type
 
    Parent_Integer1 : Visible_Integer := 36;
 
    Parent_Integer2 : Visible_Integer;
 
    Parent_Integer3 : Visible_Integer
                    := Inherited_Function (Parent_Integer1);   -- OK
 
    Parent_Integer4 : Visible_Integer
                    := Not_Inherited_Func (Parent_Integer1);   -- OK
 begin      
 
    Inherited_Procedure (Client_Integer1, Client_Integer2);    -- OK
 
    Not_Inherited_Proc (Client_Integer1, Client_Integer2);     -- ERROR:
                                 -- procedure not defined for this type
 
    Inherited_Procedure (Parent_Integer1, Parent_Integer2);    -- OK
 
    Not_Inherited_Proc (Parent_Integer1, Parent_Integer2);     -- OK 
 
 end BA11004;
 
