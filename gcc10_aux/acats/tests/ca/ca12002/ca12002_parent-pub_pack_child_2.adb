

with CA12002_Parent.Pub_Pack_Child_2.Priv_Grandchild.Pub_Greatgrandchild;
package body CA12002_Parent.Pub_Pack_Child_2 is

   function F return Float is
   begin
      return
         CA12002_Parent.Pub_Pack_Child_2.Priv_Grandchild.Pub_Greatgrandchild.X;
   end F;

end CA12002_Parent.Pub_Pack_Child_2;
