
     --==================================================================--

with Report;

package body C3A1001_0 is

   protected body Incomplete5 is    

      function Get_Priv_Val return Enu_Type is
      begin
         return Enu_Obj;
      end Get_Priv_Val; 

    end Incomplete5; 

   ----------------------------------------------------------------------
   protected body Incomplete6 is                                             
            
      function Get_Priv_Val return Small_Int is
      begin
         return Num;
      end Get_Priv_Val; 

    end Incomplete6; 

   ----------------------------------------------------------------------
   function Return_String (S : String) return String is
   begin
      if Report.Ident_Bool(True) = True then
         return S;
      end if;

      return S;
   end Return_String;
   
end C3A1001_0;
