
     --=================================================================--

package body B393003 is

   function Func return Tagged_Type is                                -- OK
   begin
      return (Field_1 => false);
   end Func;
   -------------------------------------
   procedure Abstract_Vis_Proc (P : Abstract_Visible) is              -- ERROR:
                                                      -- Procedure is abstract.
   begin                                              
      null;
   end Abstract_Vis_Proc;

   function Abstract_Vis_Func (P : Abstract_Visible)                  -- ERROR:
                                                       -- Function is abstract.
     return Short is                               
   begin
      return 1;
   end Abstract_Vis_Func;

   procedure Untag_Abs_Proc (P1 : Abstract_Visible;                   -- ERROR:
                             P2 : Untagged_Rec) is    -- Procedure is abstract.
   begin
      null;
   end Untag_Abs_Proc;
   -------------------------------------
   procedure Abstract_Vis_Proc (P : New_Abs_Vis) is                   -- ERROR:
                                                      -- New_Abs_Vis is frozen.
   begin
      null;
   end Abstract_Vis_Proc;


   function Abstract_Vis_Func (P : New_Abs_Vis)                       -- ERROR:
                                                      -- New_Abs_Vis is frozen.
     return Short is
   begin
      return 2;
   end Abstract_Vis_Func;

   procedure Untag_Abs_Proc (P1 : New_Abs_Vis;                        -- ERROR:
                             P2 : Untagged_Rec) is     -- New_Abs_Vis is frozen.
   begin
      null;
   end Untag_Abs_Proc;
   -------------------------------------
   procedure Untag_Abs_Proc (P1 : Abstract_Visible;                      -- OK.
                             P2 : New_Untag_Rec) is   -- override inherited op
   begin                                              
      null;
   end Untag_Abs_Proc;
   -------------------------------------
   procedure Abstract_Vis_Proc (P : New_New_Abs_Vis) is               -- ERROR:
                                                  -- New_New_Abs_Vis is frozen.
   begin
      null;
   end Abstract_Vis_Proc;
   
   function Abstract_Vis_Func (P : New_New_Abs_Vis)                   -- ERROR:
                                                  -- New_New_Abs_Vis is frozen.
     return Short is                                                          
   begin
      return 5;
   end Abstract_Vis_Func;
   
   procedure Untag_Abs_Proc (P1 : New_New_Abs_Vis;                      -- OK. 
                             P2 : New_Untag_Rec) is   -- no homograph for this
   begin                                             
      null;
   end Untag_Abs_Proc;
   -------------------------------------
   procedure Abs_Tag_Lim_Proc (P : New_Abs_Tag_Lim) is                -- ERROR:
                                                  -- New_Abs_Tag_Lim is frozen.
   begin                                             
      null;
   end Abs_Tag_Lim_Proc;
   -------------------------------------
   procedure Abstract_Vis_Proc (P : New_Abs_Pri) is                   -- ERROR:
                                                      -- New_Abs_Pri is frozen.
   begin                                             
      null;
   end Abstract_Vis_Proc;

   function Abstract_Vis_Func (P : New_Abs_Pri)                       -- ERROR:
                                                      -- New_Abs_Pri is frozen.
     return Short is                                  
   begin
      return 7;
   end Abstract_Vis_Func;
   
   procedure Untag_Abs_Proc (P1 : New_Abs_Pri;                        -- ERROR:
                             P2 : Untagged_Rec) is    -- New_Abs_Pri is frozen.
   begin                                             
      null;
   end Untag_Abs_Proc;
   -------------------------------------
   procedure Abstract_Pri_Proc (P1 : Abstract_Private;                  -- OK.
                                P2 : New_Short := 0) is
   begin                                             -- Override inherited op.
      null;
   end Abstract_Pri_Proc;

   function Abstract_Vis_Func (P : Abstract_Visible)                    -- OK.
     return New_Short is                              
   begin                                          
      return 9;
   end Abstract_Vis_Func;

   -------------------------------------
   Object01 : Abstract_Visible;                                       -- ERROR:
                                          -- Type of object cannot be abstract.
   Object02 : New_Untag_Rec;                                          -- OK.
                                         -- Object with abstract operation.
   
   Object03 : Non_Abstract_Extension;
   Object04 : Non_Abstract_Extension;

begin
   Abstract_Visible (Object03) := Abstract_Visible (Object04);        -- ERROR:
                      -- Target of an assignment operation may not be abstract.

end B393003;
