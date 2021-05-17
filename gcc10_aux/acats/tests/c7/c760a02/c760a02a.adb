

package body C760A02A is

   function Func_Lim_Rec (Int : in Integer) return F760A00.Lim_Rec is
   begin
      return (A => Int, B => False, TC => <>);
   end Func_Lim_Rec;


   function Func_Lim_Comp (Int : in Integer) return F760A00.Lim_Comp is
   begin
      return (N => Int, others => <>);
   end Func_Lim_Comp;


   function Func_Lim_Array (Int : in Integer) return F760A00.Lim_Array is
   begin
      return (1 .. Int => (A => 10, B => True, TC => <>));
   end Func_Lim_Array;


   function Func_Lim_Ext (Int : in Integer) return F760A00.Child.Lim_Ext is
   begin
      if Int = 10 then
         return (F760A00.Lim_Tagged with G => 10, TC2 => <>);
      else
         return (F760A00.Lim_Tagged with G => Int, TC2 => <>);
      end if;
   end Func_Lim_Ext;

end C760A02A;
