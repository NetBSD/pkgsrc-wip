

     --===================================================================--


package body B3A0003 is

--
-- Subprogram with parameters of formal type local to B3A0003:
--

   procedure Local_Op (Acc_Parm : in out Acc_Type) is
   begin

   --
   -- Update of access object:
   --

      Local_AC         := Local_Val;                                  -- OK.
      Local_Formal_Obj := Local_Val;                                  -- OK.
      Acc_Parm         := Local_Val;                                  -- OK.


   --
   -- Update of designated object (explicit dereference):
   --

      Local_AC.all         := Local_Val.all;                          -- ERROR:
      Local_Formal_Obj.all := Local_Val.all;                          -- ERROR:
      Acc_Parm.all         := Local_Val.all;                          -- ERROR:


   --
   -- Update of component of designated object (implicit dereference):
   --

      Local_AC.Item         := Local_Val.Item;                        -- ERROR:
      Local_Formal_Obj.Item := Local_Val.Item;                        -- ERROR:
      Acc_Parm.Item         := Local_Val.Item;                        -- ERROR:

   end Local_Op;



--
-- Subprogram with parameters of formal type of Formal_Package:
--

   procedure FP_Formal_Op (Acc_Parm : in out Formal_Package.FP_Formal_Acc) is
   begin

   --
   -- Update of access object:
   --

      FP_Formal_AC                 := FP_Formal_Val;                  -- OK.
      Formal_Package.FP_Formal_Obj := FP_Formal_Val;                  -- OK.
      Acc_Parm                     := FP_Formal_Val;                  -- OK.


   --
   -- Update of designated object (explicit dereference):
   --

      FP_Formal_AC.all                 := FP_Formal_Val.all;          -- ERROR:
      Formal_Package.FP_Formal_Obj.all := FP_Formal_Val.all;          -- ERROR:
      Acc_Parm.all                     := FP_Formal_Val.all;          -- ERROR:

   end FP_Formal_Op;


--
-- Subprogram with parameters of type declared in Formal_Package:
--

   procedure FP_Local_Op (Acc_Parm : in out Formal_Package.FP_Local_Acc) is
   begin

   --
   -- Update of access object:
   --

      FP_Local_AC         := FP_Local_Val;                            -- OK.
      FP_Local_Formal_Obj := FP_Local_Val;                            -- OK.
      Acc_Parm            := FP_Local_Val;                            -- OK.


   --
   -- Update of designated object (explicit dereference):
   --

      FP_Local_AC.all         := FP_Local_Val.all;                    -- ERROR:
      FP_Local_Formal_Obj.all := FP_Local_Val.all;                    -- ERROR:
      Acc_Parm.all            := FP_Local_Val.all;                    -- ERROR:


   --
   -- Update of component of designated object (implicit dereference):
   --

      FP_Local_AC.Item         := FP_Local_Val.Item;                  -- ERROR:
      FP_Local_Formal_Obj.Item := FP_Local_Val.Item;                  -- ERROR:
      Acc_Parm.Item            := FP_Local_Val.Item;                  -- ERROR:

   end FP_Local_Op;

end B3A0003;
