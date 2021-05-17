

with Report;
procedure CA12002_Parent.Priv_Proc_Child (X : out Integer) is
begin
   X := Report.Ident_Int (7);
end CA12002_Parent.Priv_Proc_Child;
