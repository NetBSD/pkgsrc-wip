

private with CA12002_Parent.Priv_Pack_Child;
private with CA12002_Parent.Priv_Proc_Child;
private with CA12002_Parent.Priv_Func_Child;
pragma Elaborate (CA12002_Parent.Priv_Pack_Child);
pragma Elaborate_All (CA12002_Parent.Priv_Func_Child);
package CA12002_Parent.Pub_Pack_Child_1 is
   X : constant Integer;
   Y : constant Boolean;
   procedure P (X : out Integer);
   function F return Integer;
   package Nested is
      Z : constant Integer;
   private
      Z : constant Integer := CA12002_Parent.Priv_Pack_Child.X * 3;
   end Nested;
private
   X : constant Integer := CA12002_Parent.Priv_Pack_Child.X;
   Y : constant Boolean := CA12002_Parent.Priv_Func_Child;
end CA12002_Parent.Pub_Pack_Child_1;
