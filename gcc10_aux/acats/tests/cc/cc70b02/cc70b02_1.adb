

     --==================================================================--


package body CC70B02_1 is

   procedure Double_List (L : in out List_Mgr.List_Type) is
      Element : Discrete_Type;  -- Formal part of Discrete_Ops template
   begin                        -- is directly visible here.
      List_Mgr.Reset (L);
      while not List_Mgr.End_Of_List (L) loop
         List_Mgr.View_Element (L, Element);
         Double (Element);
         List_Mgr.Write_Element (L, Element);
      end loop;
   end Double_List;

end CC70B02_1;
