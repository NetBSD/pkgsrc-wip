
with Report;
with C413003Q;
procedure C413003 is
begin
   Report.Test ("C413003", "Check that for the prefixed view L.R, if L " &
                           "represents an object or value of a tagged type T, " &
                           "that R may represent a subprogram with a first " &
                           "access parameter that designates the type T or " &
                           "a class-wide type covered by T that is declared " &
                           "immediately in the declarative region of " &
                           "an ancestor of T.");

   -- Verify that the primitive operation in the ancestor is properly called.

   declare
      Q1_Obj  : aliased C413003Q.TQ;
      Q2_Obj  : aliased C413003Q.TQ;
   begin
      -- -------------------------------------------------------------------
      -- call on inherited procedure (with no parameters)

      Q1_Obj.Base_Proc;
      C413003Q.Base_Proc (Q2_Obj'access);
      if Q1_Obj.Data /= Q2_Obj.Data then
         Report.Failed ("Wrong value (inherited procedure -1-)");
      end if;

      -- call on inherited function (with no parameters)
      if Q1_Obj.Base_Func /= C413003Q.Base_Func (Q1_Obj'access) then
         Report.Failed ("Wrong value (inherited function -2-)");
      end if;

      -- call on inherited procedure (with parameters)
      Q1_Obj.Base_Proc (Value => 123);
      if Q1_Obj.Data /= 123 then
         Report.Failed ("Wrong value (inherited procedure -3-)");
      end if;

      --  call on inherited function (with parameters)
      if Q1_Obj.Base_Func (Value => 1234)
        /= C413003Q.Base_Func (Q1_Obj'access, 1234)
      then
         Report.Failed ("Wrong value (inherited function -4-)");
      end if;
   end;

   -- -----------------------------------------------------------------
   --  Verify that the redefined primitive operation is properly called.

   declare
      Q1_Obj  : aliased C413003Q.TQ;
      Q2_Obj  : aliased C413003Q.TQ;

   begin
      --  call on primitive procedure (with no parameters)

      Q1_Obj.Prim_Proc;
      C413003Q.Prim_Proc (Q2_Obj'access);
      if Q1_Obj.Data /= Q2_Obj.Data then
         Report.Failed ("Wrong value (primitive procedure -1-)");
      end if;

      --  call on primitive function (with no parameters)
      if Q1_Obj.Prim_Func /= C413003Q.Prim_Func (Q1_Obj'access) then
         Report.Failed ("Wrong value (primitive function -2-)");
      end if;

      --  call on primitive procedure (with parameters)
      Q1_Obj.Prim_Proc (Value => 123);
      C413003Q.Prim_Proc (Q2_Obj'access, Value => 123);
      if Q1_Obj.Data /= Q2_Obj.Data then
         Report.Failed ("Wrong value (primitive procedure -3-)");
      end if;

      --  call on primitive function (with parameters)
      if Q1_Obj.Prim_Func (Value => 123)
        /= C413003Q.Prim_Func (Q1_Obj'access, Value => 123)
      then
         Report.Failed ("Wrong value (primitive function -4-)");
      end if;
   end;

   -- -------------------------------------------------------------------
   --  Verify dispatching calls.

   declare
      Q1_Obj  : aliased C413003Q.TQ;
      Q2_Obj  : aliased C413003Q.TQ;
      Q1_Cobj : aliased C413003Q.TQ'Class := Q1_Obj;
      Q2_Cobj : aliased C413003Q.TQ'Class := Q2_Obj;
   begin
      --  dispatching call to procedure (with no parameters)
      Q1_Cobj.Base_Proc;
      C413003Q.Base_Proc (Q2_CObj'access);
      if Q1_Obj.Data /= Q2_Obj.Data then
         Report.Failed ("Wrong value (dispatching call to procedure -1-)");
      end if;

      --  dispatching call to funcion (with no parameters)
      if Q1_Cobj.Base_Func /= C413003Q.Base_Func (Q1_CObj'access) then
         Report.Failed ("Wrong value (dispatching call to function -2-)");
      end if;

      -- call on inherited procedure (with parameters)
      Q1_CObj.Base_Proc (Value => 123);
      if Q1_CObj.Data /= 123 then
         Report.Failed ("Wrong value (inherited procedure -3-)");
      end if;

      --  call on inherited function (with parameters)
      if Q1_CObj.Base_Func (Value => 1234)
        /= C413003Q.Base_Func (Q1_Obj'access, 1234)
      then
         Report.Failed ("Wrong value (inherited function -4-)");
      end if;

      --  dispatching call on new primitive function
      if Q1_Cobj.Prim_New_Func /= C413003Q.Prim_New_Func (Q1_CObj'access) then
         Report.Failed ("Wrong value (dispatching call on "
                        & "primitive function)");
      end if;
   end;

   -- -------------------------------------------------------------------
   --  Test class-wide subprograms.

   declare
      Q_Obj : aliased C413003Q.TQ;
   begin
      --  call class-wide procedure (with no parameters)
      Q_Obj.Class_Wide_Proc;                  --  Call P.Class_Wide_Proc
      if Q_Obj.Data /= -1 then
         Report.Failed ("Wrong value (class-wide procedure -1-)");
      end if;

      --  call class-wide function (with no parameters)
      if Q_Obj.Class_Wide_Func /= -2 then     --  Call P.Class_Wide_Func
         Report.Failed ("Wrong value (class-wide function -2-)");
      end if;

      --  call class-wide procedure (with parameters)
      Q_Obj.Class_Wide_Proc (Value => 3);     --  Call P.Class_Wide_Proc
      if Q_Obj.Data /= 9 then
         Report.Failed ("Wrong value (class-wide procedure -3-)");
      end if;

      --  call class-wide function (with parameters)
      if Q_Obj.Class_Wide_Func (Value => 3) /= 9 then -- P.Call_Wide_Func
         Report.Failed ("Wrong value (class-wide function -4-)");
      end if;

      --  call class-wide procedure (with parameters)
      Q_Obj.Class_Wide_Proc (Value => 3.0);
      --  C413003Q.Class_Wide_Proc
      if Q_Obj.Value /= 9.0 then
         Report.Failed ("Wrong value (class-wide procedure -5-)");
      end if;

      --  call class-wide function (with parameters)
      if Q_Obj.Class_Wide_Func (Value => 3.0) /= 9.0 then
         -- C413003Q.Call_Wide_Func
         Report.Failed ("Wrong value (class-wide function -6-)");
      end if;
   end;

   -- -------------------------------------------------------------------
   --  Test nested package.

   declare
      L1_Obj : aliased C413003Q.Local.TPP;
      L2_Obj : aliased C413003Q.Local.TPP;
   begin
      --  call on primitive procedure in nested package (with no parameters)
      L1_Obj.Prim_Proc;
      C413003Q.Local.Prim_Proc (L2_Obj'access);
      if L1_Obj.Data /= L2_Obj.Data then
         Report.Failed ("Wrong value (primitive op in nested package -1-)");
      end if;

      --  call on primitive function in nested package (with no parameters)
      if L1_Obj.Prim_Func /= C413003Q.Local.Prim_Func (L1_Obj'access) then
         Report.Failed ("Wrong value (primitive op in nested package -2-)");
      end if;

      --  call on primitive procedure in nested package (with parameters)
      L1_Obj.Prim_Proc (Value => 123);
      C413003Q.Local.Prim_Proc (L2_Obj'access, Value => 123);
      if L1_Obj.Data /= L2_Obj.Data then
         Report.Failed ("Wrong value (primitive op in nested package -3-)");
      end if;

      --  call on primitive function in nested package (with parameters)
      if L1_Obj.Prim_Func (Value => 123)
        /= C413003Q.Local.Prim_Func (L1_Obj'access, Value => 123)
      then
         Report.Failed ("Wrong value (primitive function -4-)");
      end if;
   end;

   Report.Result;
end C413003;
