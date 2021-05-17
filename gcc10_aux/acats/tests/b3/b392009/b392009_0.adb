

     --===================================================================--


package body B392009_0 is

   function Dyn_Tag_Func (A: Root) return Root is
   begin
      return A;
   end Dyn_Tag_Func;


   procedure Proc (A: in Root) is
   begin
      null;
   end Proc;


   function Func (A: Root) return Root is
   begin
      return A;
   end Func;


   function Access_Parm_Func (A: not null access Root) return Root is
   begin
      return A.all;
   end Access_Parm_Func;


   procedure Access_Parm_Proc (A: access Root'Class) is
   begin
      null;
   end Access_Parm_Proc;



   function Dyn_Tag_Func (A: Child) return Child is
   begin
      return A;
   end Dyn_Tag_Func;


   procedure Proc (A: in Child) is
   begin
      null;
   end Proc;


   function Func (A: Child) return Child is
   begin
      return A;
   end Func;


   function Access_Parm_Func (A: not null access Child) return Child is
   begin
      return A.all;
   end Access_Parm_Func;

end B392009_0;
