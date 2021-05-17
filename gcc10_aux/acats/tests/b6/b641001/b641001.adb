

     --===================================================================--


package body B641001 is

--
-- Null bodies for declared subprograms (bodies not needed for test):
--

   procedure Local_Acc_Op (P_In    : in     Acc_Type;
                           P_InOut : in out Acc_Type;
                           P_Out   :    out Acc_Type) is
   begin
      null;
   end Local_Acc_Op;


   procedure Local_Des_Op (P_In    : in     B641001_0.Designated;
                           P_InOut : in out B641001_0.Designated;
                           P_Out   :    out B641001_0.Designated) is
   begin
      null;
   end Local_Des_Op;


   procedure Local_Cmp_Op (P_In    : in     B641001_0.Component;
                           P_InOut : in out B641001_0.Component;
                           P_Out   :    out B641001_0.Component) is
   begin
      null;
   end Local_Cmp_Op;


   procedure FP_Form_Acc_Op (P_In    : in     Formal_Pack.FP_Formal_Acc;
                             P_InOut : in out Formal_Pack.FP_Formal_Acc;
                             P_Out   :    out Formal_Pack.FP_Formal_Acc) is
   begin
      null;
   end FP_Form_Acc_Op;


   procedure FP_Form_Des_Op (P_In    : in     Formal_Pack.FP_Formal_Des;
                             P_InOut : in out Formal_Pack.FP_Formal_Des;
                             P_Out   :    out Formal_Pack.FP_Formal_Des) is
   begin
      null;
   end FP_Form_Des_Op;


   procedure FP_Loc_Acc_Op (P_In    : in     Formal_Pack.FP_Local_Acc;
                            P_InOut : in out Formal_Pack.FP_Local_Acc;
                            P_Out   :    out Formal_Pack.FP_Local_Acc) is
   begin
      null;
   end FP_Loc_Acc_Op;


   procedure FP_Loc_Des_Op (P_In    : in     Formal_Pack.FP_Local_Desig;
                            P_InOut : in out Formal_Pack.FP_Local_Desig;
                            P_Out   :    out Formal_Pack.FP_Local_Desig) is
   begin
      null;
   end FP_Loc_Des_Op;


   procedure FP_Loc_Cmp_Op (P_In    : in     B641001_0.Component;
                            P_InOut : in out B641001_0.Component;
                            P_Out   :    out B641001_0.Component) is
   begin
      null;
   end FP_Loc_Cmp_Op;



--
-- Bodies for subprograms which attempt illegal parameter-passing:
--

   procedure Local_Calls (Acc_Parm : in out Acc_Type) is
   begin

   --
   -- Actual parameter is of access-to-constant type:
   --

      -- Interested primarily in last two parameter positions;
      -- use B641001_0.Rec'Access as "placeholder" for first parameter:

      Local_Acc_Op (B641001_0.Rec'Access, Local_Stat, Local_Dyna);    -- OK.
      Local_Acc_Op (B641001_0.Rec'Access, Local_Form_Obj, Acc_Parm);  -- OK.


   --
   -- Actual parameter is of designated type (explicit dereference):
   --

      -- Use Loc_DVar as "placeholder" when not checking a particular
      -- parameter:

      Local_Des_Op (Local_Stat.all, Loc_DVar, Loc_DVar);              -- OK.
      Local_Des_Op (Loc_DVar, Local_Stat.all, Loc_DVar);              -- ERROR:
      Local_Des_Op (Loc_DVar, Loc_DVar, Local_Stat.all);              -- ERROR:

      Local_Des_Op (Local_Dyna.all, Loc_DVar, Loc_DVar);              -- OK.
      Local_Des_Op (Loc_DVar, Local_Dyna.all, Loc_DVar);              -- ERROR:
      Local_Des_Op (Loc_DVar, Loc_DVar, Local_Dyna.all);              -- ERROR:

      Local_Des_Op (Local_Form_Obj.all, Loc_DVar, Loc_DVar);          -- OK.
      Local_Des_Op (Loc_DVar, Local_Form_Obj.all, Loc_DVar);          -- ERROR:
      Local_Des_Op (Loc_DVar, Loc_DVar, Local_Form_Obj.all);          -- ERROR:

      Local_Des_Op (Acc_Parm.all, Loc_DVar, Loc_DVar);                -- OK.
      Local_Des_Op (Loc_DVar, Acc_Parm.all, Loc_DVar);                -- ERROR:
      Local_Des_Op (Loc_DVar, Loc_DVar, Acc_Parm.all);                -- ERROR:


   --
   -- Actual parameter is of component type (implicit dereference):
   --

      -- Use Loc_CVar and Loc_CVar2 as "placeholders" when not checking a
      -- particular parameter:

      Local_Cmp_Op (Local_Stat.Item, Loc_CVar, Loc_CVar2);            -- OK.
      Local_Cmp_Op (Loc_CVar, Local_Stat.Item, Loc_CVar2);            -- ERROR:
      Local_Cmp_Op (Loc_CVar, Loc_CVar2, Local_Stat.Item);            -- ERROR:

      Local_Cmp_Op (Local_Dyna.Item, Loc_CVar, Loc_CVar2);            -- OK.
      Local_Cmp_Op (Loc_CVar, Local_Dyna.Item, Loc_CVar2);            -- ERROR:
      Local_Cmp_Op (Loc_CVar, Loc_CVar2, Local_Dyna.Item);            -- ERROR:

      Local_Cmp_Op (Local_Form_Obj.Item, Loc_CVar, Loc_CVar2);        -- OK.
      Local_Cmp_Op (Loc_CVar, Local_Form_Obj.Item, Loc_CVar2);        -- ERROR:
      Local_Cmp_Op (Loc_CVar, Loc_CVar2, Local_Form_Obj.Item);        -- ERROR:

      Local_Cmp_Op (Acc_Parm.Item, Loc_CVar, Loc_CVar2);              -- OK.
      Local_Cmp_Op (Loc_CVar, Acc_Parm.Item, Loc_CVar2);              -- ERROR:
      Local_Cmp_Op (Loc_CVar, Loc_CVar2, Acc_Parm.Item);              -- ERROR:

   end Local_Calls;



--
-- Subprogram with parameters of formal type of Formal_Pack:
--

   procedure FP_Formal_Calls (Acc_Parm : in out Formal_Pack.FP_Formal_Acc) is
      use Formal_Pack;
   begin

   --
   -- Actual parameter is of access-to-constant type:
   --

      -- Interested primarily in last two parameter positions;
      -- use Priv'Access as "placeholder" for first parameter:

      FP_Form_Acc_Op (Priv'Access, FP_Form_Stat, FP_Form_Dyna);       -- OK.
      FP_Form_Acc_Op (Priv'Access, FP_Formal_Obj, Acc_Parm);          -- OK.


   --
   -- Actual parameter is of designated type (explicit dereference):
   --

      -- Use FP_Form_DVar as "placeholder" when not checking a particular
      -- parameter:

      FP_Form_Des_Op (FP_Form_Stat.all, FP_Form_DVar, FP_Form_DVar);  -- OK.
      FP_Form_Des_Op (FP_Form_DVar, FP_Form_Stat.all, FP_Form_DVar);  -- ERROR:
      FP_Form_Des_Op (FP_Form_DVar, FP_Form_DVar, FP_Form_Stat.all);  -- ERROR:

      FP_Form_Des_Op (FP_Form_Dyna.all, FP_Form_DVar, FP_Form_DVar);  -- OK.
      FP_Form_Des_Op (FP_Form_DVar, FP_Form_Dyna.all, FP_Form_DVar);  -- ERROR:
      FP_Form_Des_Op (FP_Form_DVar, FP_Form_DVar, FP_Form_Dyna.all);  -- ERROR:

      FP_Form_Des_Op (FP_Formal_Obj.all, FP_Form_DVar, FP_Form_DVar); -- OK.
      FP_Form_Des_Op (FP_Form_DVar, FP_Formal_Obj.all, FP_Form_DVar); -- ERROR:
      FP_Form_Des_Op (FP_Form_DVar, FP_Form_DVar, FP_Formal_Obj.all); -- ERROR:

      FP_Form_Des_Op (Acc_Parm.all, FP_Form_DVar, FP_Form_DVar);      -- OK.
      FP_Form_Des_Op (FP_Form_DVar, Acc_Parm.all, FP_Form_DVar);      -- ERROR:
      FP_Form_Des_Op (FP_Form_DVar, FP_Form_DVar, Acc_Parm.all);      -- ERROR:

   end FP_Formal_Calls;



--
-- Subprogram with parameters of type declared in Formal_Pack:
--

   procedure FP_Local_Calls (Acc_Parm : in out Formal_Pack.FP_Local_Acc) is
      use Formal_Pack;
   begin

   --
   -- Actual parameter is of access-to-constant type:
   --

      -- Interested primarily in last two parameter positions;
      -- use Tag'Access as "placeholder" for first parameter:

      FP_Loc_Acc_Op (Tag'Access, FP_Local_Stat, FP_Local_Dyna);       -- OK.
      FP_Loc_Acc_Op (Tag'Access, FP_Loc_Form_Obj, Acc_Parm);          -- OK.


   --
   -- Actual parameter is of designated type (explicit dereference):
   --

      -- Use FP_Loc_DVar as "placeholder" when not checking a particular
      -- parameter:

      FP_Loc_Des_Op (FP_Local_Stat.all, FP_Loc_DVar, FP_Loc_DVar);    -- OK.
      FP_Loc_Des_Op (FP_Loc_DVar, FP_Local_Stat.all, FP_Loc_DVar);    -- ERROR:
      FP_Loc_Des_Op (FP_Loc_DVar, FP_Loc_DVar, FP_Local_Stat.all);    -- ERROR:

      FP_Loc_Des_Op (FP_Local_Dyna.all, FP_Loc_DVar, FP_Loc_DVar);    -- OK.
      FP_Loc_Des_Op (FP_Loc_DVar, FP_Local_Dyna.all, FP_Loc_DVar);    -- ERROR:
      FP_Loc_Des_Op (FP_Loc_DVar, FP_Loc_DVar, FP_Local_Dyna.all);    -- ERROR:

      FP_Loc_Des_Op (FP_Loc_Form_Obj.all, FP_Loc_DVar, FP_Loc_DVar);  -- OK.
      FP_Loc_Des_Op (FP_Loc_DVar, FP_Loc_Form_Obj.all, FP_Loc_DVar);  -- ERROR:
      FP_Loc_Des_Op (FP_Loc_DVar, FP_Loc_DVar, FP_Loc_Form_Obj.all);  -- ERROR:

      FP_Loc_Des_Op (Acc_Parm.all, FP_Loc_DVar, FP_Loc_DVar);         -- OK.
      FP_Loc_Des_Op (FP_Loc_DVar, Acc_Parm.all, FP_Loc_DVar);         -- ERROR:
      FP_Loc_Des_Op (FP_Loc_DVar, FP_Loc_DVar, Acc_Parm.all);         -- ERROR:


   --
   -- Actual parameter is of component type (implicit dereference):
   --

      -- Use FP_Loc_CVar and FP_Loc_CVar2 as "placeholders" when not checking a
      -- particular parameter:

      FP_Loc_Cmp_Op (FP_Local_Stat.Item, FP_Loc_CVar, FP_Loc_CVar2);  -- OK.
      FP_Loc_Cmp_Op (FP_Loc_CVar, FP_Local_Stat.Item, FP_Loc_CVar2);  -- ERROR:
      FP_Loc_Cmp_Op (FP_Loc_CVar, FP_Loc_CVar2, FP_Local_Stat.Item);  -- ERROR:

      FP_Loc_Cmp_Op (FP_Local_Dyna.Item, FP_Loc_CVar, FP_Loc_CVar2);  -- OK.
      FP_Loc_Cmp_Op (FP_Loc_CVar, FP_Local_Dyna.Item, FP_Loc_CVar2);  -- ERROR:
      FP_Loc_Cmp_Op (FP_Loc_CVar, FP_Loc_CVar2, FP_Local_Dyna.Item);  -- ERROR:

      FP_Loc_Cmp_Op (FP_Loc_Form_Obj.Item, FP_Loc_CVar, FP_Loc_CVar2);-- OK.
      FP_Loc_Cmp_Op (FP_Loc_CVar, FP_Loc_Form_Obj.Item, FP_Loc_CVar2);-- ERROR:
      FP_Loc_Cmp_Op (FP_Loc_CVar, FP_Loc_CVar2, FP_Loc_Form_Obj.Item);-- ERROR:

      FP_Loc_Cmp_Op (Acc_Parm.Item, FP_Loc_CVar, FP_Loc_CVar2);       -- OK.
      FP_Loc_Cmp_Op (FP_Loc_CVar, Acc_Parm.Item, FP_Loc_CVar2);       -- ERROR:
      FP_Loc_Cmp_Op (FP_Loc_CVar, FP_Loc_CVar2, Acc_Parm.Item);       -- ERROR:

   end FP_Local_Calls;


end B641001;
