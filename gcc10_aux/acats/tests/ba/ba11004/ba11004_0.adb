 
      --=================================================================--
 
 package body BA11004_0 is
 
    function Inherited_Function (I : Visible_Integer) 
      return Visible_Integer is
 
    begin
 
       -- Real body of function goes here.
 
       return (I / 2);
 
    end Inherited_Function;
 
    ----------------------------------------------------
 
    procedure Inherited_Procedure (I : in     Visible_Integer;
                                   R :    out Visible_Integer) is
    begin
 
       -- Real body of procedure goes here.
 
       R := I - 2;
 
    end Inherited_Procedure;
 
 end BA11004_0;
