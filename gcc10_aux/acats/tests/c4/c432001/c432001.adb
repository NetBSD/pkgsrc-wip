

with C432001_0;
with C432001_1;
with C432001_2;
with Report;
procedure C432001 is

   N_Object : C432001_0.N := (How_Long_Ago => Report.Ident_Int(375),
                              Era          => C432001_0.Paleozoic);

   P_Object : C432001_0.P; -- default value is (150,
                           --                   C432001_0.Mesozoic)

   N_N_Object : C432001_1.N_N :=
      (N_Object with Period => C432001_1.Devonian);

   P_N_Object : C432001_1.P_N :=
      (P_Object with Period => C432001_1.Jurassic);

   N_P_Object : C432001_1.N_P; -- default is (1,
                               --             C432001_0.Cenozoic,
                               --             C432001_1.Quaternary)

   P_P_Object : C432001_1.P_P; -- default is (150,
                               --             C432001_0.Mesozoic,
                               --             C432001_1.Jurassic)

   P_P_Null_Ob:C432001_1.P_P_Null := (P_Object with null record);

   N_N_N_Object : C432001_2.N_N_N :=
      (N_N_Object with Sample_On_Loan => Report.Ident_Bool(True));

   N_P_N_Object : C432001_2.N_P_N :=
      (N_P_Object with Sample_On_Loan => Report.Ident_Bool(False));

   P_N_N_Object : C432001_2.P_N_N :=
      (P_N_Object with Sample_On_Loan => Report.Ident_Bool(True));

   P_P_N_Object : C432001_2.P_P_N :=
      (P_P_Object with Sample_On_Loan => Report.Ident_Bool(False));

   P_N_Object_2 : C432001_1.P_N := (C432001_0.P(P_N_N_Object)
                                    with C432001_1.Carboniferous);

   N_N_Object_2 : C432001_1.N_N := (C432001_0.N'(42,C432001_0.Precambrian)
                                    with C432001_1.Carboniferous);

begin

   Report.Test ("C432001", "Extension aggregates");

   -- check ultimate ancestor types

   if not C432001_0.Check (N_Object,
                           375,
                           C432001_0.Paleozoic) then
      Report.Failed ("Object of " &
                     "nonprivate type " &
                     "failed content check");
   end if;

   if not C432001_0.Check (P_Object) then
      Report.Failed ("Object of " &
                     "private type " &
                     "failed content check");
   end if;

   -- check direct type extensions

   if not C432001_1.Check (N_N_Object,
                           375,
                           C432001_0.Paleozoic,
                           C432001_1.Devonian) then
      Report.Failed ("Object of " &
                     "nonprivate extension of nonprivate type " &
                     "failed content check");
   end if;

   if not C432001_1.Check (N_P_Object) then
      Report.Failed ("Object of " &
                     "private extension of nonprivate type " &
                     "failed content check");
   end if;

   if not C432001_1.Check (P_N_Object,
                           C432001_1.Jurassic) then
      Report.Failed ("Object of " &
                     "nonprivate extension of private type " &
                     "failed content check");
   end if;

   if not C432001_1.Check (P_P_Object) then
      Report.Failed ("Object of " &
                     "private extension of private type " &
                     "failed content check");
   end if;

    if not C432001_1.Check (P_P_Null_Ob) then
      Report.Failed ("Object of " &
                     "private type " &
                     "failed content check");
   end if;


   -- check direct extensions of extensions

   if not C432001_2.Check (N_N_N_Object,
                           375,
                           C432001_0.Paleozoic,
                           C432001_1.Devonian,
                           True) then
      Report.Failed ("Object of " &
                     "nonprivate extension of nonprivate extension " &
                     "(of nonprivate parent) " &
                     "failed content check");
   end if;

   if not C432001_2.Check (N_P_N_Object, False) then
      Report.Failed ("Object of " &
                     "nonprivate extension of private extension " &
                     "(of nonprivate parent) " &
                     "failed content check");
   end if;

   if not C432001_2.Check (P_N_N_Object,
                           C432001_1.Jurassic,
                           True) then
      Report.Failed ("Object of " &
                     "nonprivate extension of nonprivate extension " &
                     "(of private parent) " &
                     "failed content check");
   end if;

   if not C432001_2.Check (P_P_N_Object, False) then
      Report.Failed ("Object of " &
                     "nonprivate extension of private extension " &
                     "(of private parent) " &
                     "failed content check");
   end if;

   -- check that the extension aggregate may specify an expression of
   -- a "grandparent" ancestor type

   -- types tested are derived through nonprivate extensions only
   -- (extension aggregates are not allowed if the path from the
   -- ancestor type wanders through a private extension)
   
   N_N_N_Object :=
      (N_Object with Period => C432001_1.Devonian,
                     Sample_On_Loan => Report.Ident_Bool(True));

   if not C432001_2.Check (N_N_N_Object,
                           375,
                           C432001_0.Paleozoic,
                           C432001_1.Devonian,
                           True) then
      Report.Failed ("Object of " &
                     "nonprivate extension " &
                     "of nonprivate ancestor " &
                     "failed content check");
   end if;

   P_N_N_Object :=
      (P_Object with Period => C432001_1.Jurassic,
                     Sample_On_Loan => Report.Ident_Bool(True));

   if not C432001_2.Check (P_N_N_Object,
                           C432001_1.Jurassic,
                           True) then
      Report.Failed ("Object of " &
                     "nonprivate extension " &
                     "of private ancestor " &
                     "failed content check");
   end if;

  -- Check additional cases
   if not C432001_1.Check (P_N_Object_2,
                           C432001_1.Carboniferous) then
      Report.Failed ("Additional Object of " &
                     "nonprivate extension of private type " &
                     "failed content check");
   end if;

   if not C432001_1.Check (N_N_Object_2,
                           42,
                           C432001_0.Precambrian,
                           C432001_1.Carboniferous) then
      Report.Failed ("Additional Object of " &
                     "nonprivate extension of nonprivate type " &
                     "failed content check");
   end if;

   Report.Result;

end C432001;
