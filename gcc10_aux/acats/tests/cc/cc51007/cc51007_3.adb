

     --===================================================================--


package body CC51007_3 is

   function Clear_Message (A: Alert_Type) return Alert_Type is
      Temp : Alert_Type := A;                       -- Object declaration.
   begin
      Temp.Message := (others => '-');
      return Temp;
   end Clear_Message;

   function Annotate_Alert (A: in Alert_Type'Class) return Extended_Alert is
      Temp : Alert_Type'Class := A;
   begin
      Handle (Temp);                                -- Dispatching call to
                                                    -- operation of ancestor.
      return (Alert_Type(Temp) with Addendum => "No comment");
   end Annotate_Alert;

end CC51007_3;
