

     --==================================================================--


package body CC70003_1 is

   procedure Execute_List (L : List_Mgr.List_Type; F : in out Float) is
   begin
      for I in L'Range loop
         F := List_Mgr.View_Element(I, L)(F);   -- Execute next operation in
      end loop;                                 -- list with current value of
   end Execute_List;                            -- F as operand.


end CC70003_1;
