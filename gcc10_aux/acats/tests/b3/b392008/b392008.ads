

     --===================================================================--


with B392008_0;
package B392008 is

--
-- Generic subprogram declaring formal derived type:
--

   generic
      type Tag is new B392008_0.Ancestor with private;
      -- Implicit Dyn_Tag_Func (A: Tag) return Tag declared here.

      type CW_Access is access Tag'Class;

      type Access_Proc is access procedure (A: in Tag);
      type Access_Func is access function (A: Tag) return Tag;
   procedure Derived_Class_Wide_Formal (AP     : in     Access_Proc;
                                        AF     : in     Access_Func;
                                        Ptr    : in out CW_Access;
                                        Operand: in out Tag'Class);

--
-- Generic package declaring formal private type:
--

   generic
      type Tag is tagged private;

      type CW_Access is access Tag'Class;

      type Access_Proc is access procedure (A: in Tag);
      type Access_Func is access function (A: Tag) return Tag;
   package Private_Class_Wide_Formal is

      function Dyn_Tag_Func (A: Tag) return Tag;       

      procedure Inner_Proc (AP     : in     Access_Proc;
                            AF     : in     Access_Func;
                            Ptr    : in out CW_Access;
                            Operand: in out Tag'Class);

   end Private_Class_Wide_Formal;

end B392008;
