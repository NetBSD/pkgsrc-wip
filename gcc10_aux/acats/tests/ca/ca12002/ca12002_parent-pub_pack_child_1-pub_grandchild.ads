

package CA12002_Parent.Pub_Pack_Child_1.Pub_Grandchild is
   W : constant Boolean;
private
   W : constant Boolean := not CA12002_Parent.Priv_Func_Child;
end CA12002_Parent.Pub_Pack_Child_1.Pub_Grandchild;
