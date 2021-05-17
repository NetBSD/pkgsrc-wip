

with Report;
pragma Elaborate (Report);
private package CA12002_Parent.Priv_Pack_Child is
   X : constant Integer := Report.Ident_Int (5);
end CA12002_Parent.Priv_Pack_Child;
