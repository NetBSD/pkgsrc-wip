
     --=================================================================--

package body B392006_0 is

   function Func_1_1 (P1 : Tag'Class) return Tag is
   begin
      return (Field => True);
   end Func_1_1;
   ----------------------------------------------------
   function Func_2_1 (P1, P2 : Tag'Class) return Tag is
   begin
      return (Field => False);
   end Func_2_1;

end B392006_0;
