

  --=======================================================================--


with C3A0014_0;  use C3A0014_0;
with Report;

procedure C3A0014 is
begin

   Report.Test("C3A0014", "Check that if the view defined by an object " &
                          "declaration is aliased, has discriminants, and " &
                          "its nominal subtype is unconstrained, then the " &
                          "object is unconstrained. Check that the " &
                          "attribute A'Constrained returns False if A is a " &
                          "formal out or in out parameter and A denotes an " &
                          "aliased view of an object with an unconstrained " &
                          "nominal subtype.");

   Non_Pointer_Block:
   begin

      begin
         Obj0 := (3, "Bye");              -- OK: Obj0 not constrained.
         if Obj0 /= (3, "Bye") then
            Report.Failed
              ("Wrong value after aggregate assignment - Subtest 1");
         end if;
      exception
         when others =>
            Report.Failed ("Unexpected exception raised - Subtest 1");
      end;


      begin
         Obj1 := (3, "Bye");              -- OK: Obj1 not constrained.
         if Obj1 /= (3, "Bye") then
            Report.Failed
              ("Wrong value after aggregate assignment - Subtest 2");
         end if;
      exception
         when others =>
            Report.Failed ("Unexpected exception raised - Subtest 2");
      end;


      begin
         Obj2 := (3, "Bye");              -- OK: Obj2 not constrained
         if Obj2 /= (3, "Bye") then
            Report.Failed
              ("Wrong value after aggregate assignment - Subtest 3");
         end if;
         Obj2 := (5, "Hello");            -- OK: reassign original value
      exception
         when others =>
            Report.Failed ("Unexpected exception raised - Subtest 3");
      end;


      begin
         Obj3 := (3, "Bye");              -- OK: Obj3 not constrained
         if Obj3 /= (3, "Bye") then
            Report.Failed
              ("Wrong value after aggregate assignment - Subtest 4");
         end if;
         Obj3 := (5, "Hello");            -- OK: reassign original value
      exception
         when others =>
            Report.Failed ("Unexpected exception raised - Subtest 4");
      end;


      begin
         Obj4 := (3, "Bye");              -- OK: Obj4 not constrained
         if Obj4 /= (3, "Bye") then
            Report.Failed
              ("Wrong value after aggregate assignment - Subtest 5");
         end if;
         Obj4 := (2, "Hi");               -- OK: restore original value
      exception
         when others =>
            Report.Failed ("Unexpected exception raised - Subtest 5");
      end;

   exception
      when others => Report.Failed("Unexpected exception: Non_Pointer_Block");
   end Non_Pointer_Block;


   Pointer_Block:
   begin

      begin
         Ptr1.all := (3, "Bye");        -- C_E: Ptr1.all is constrained (D=>5).
         Avoid_Optimization_and_Fail (Ptr1.all, "Subtest 6");
      exception
         when Constraint_Error => null; -- Exception is expected.
      end;


      begin
         Ptr2.all := (3, "Bye");        -- C_E: Ptr2.all is constrained (D=>2).
         Avoid_Optimization_and_Fail (Ptr2.all, "Subtest 7");
      exception
         when Constraint_Error => null; -- Exception is expected.
      end;


      begin
         Ptr3.all := (3, "Bye");        -- C_E: Ptr3.all is constrained (D=>5).
         Avoid_Optimization_and_Fail (Ptr3.all, "Subtest 8");
      exception
         when Constraint_Error => null; -- Exception is expected.
      end;


      begin
         Ptr4.all := (3, "Bye");        -- C_E: Ptr4.all is constrained (D=>2).
         Avoid_Optimization_and_Fail (Ptr4.all, "Subtest 9");
      exception
         when Constraint_Error => null; -- Exception is expected.
      end;

   exception
      when others => Report.Failed("Unexpected exception: Pointer_Block");
   end Pointer_Block;


   Subprogram_Block:
   declare
      Is_Constrained : Boolean;
   begin

      begin
         NP_Proc (Obj0);                 -- OK: Obj0 not constrained, can
         if Obj0 /= (3, "Bye") then      -- change discriminant value.
            Report.Failed
              ("Wrong value after aggregate assignment - Subtest 10");
         end if;
      exception
         when others =>
            Report.Failed ("Unexpected exception raised - Subtest 10");
      end;


      begin
         NP_Proc (Obj2);                 -- OK: Obj2 not constrained, can
         if Obj2 /= (3, "Bye") then      -- change discriminant value.
            Report.Failed
              ("Wrong value after aggregate assignment - Subtest 11");
         end if;
      exception
         when others =>
            Report.Failed ("Unexpected exception raised - Subtest 11");
      end;


      begin
         NP_Proc (Obj3);                 -- OK: Obj3 not constrained, can
         if Obj3 /= (3, "Bye") then      -- change discriminant value.
            Report.Failed
              ("Wrong value after aggregate assignment - Subtest 12");
         end if;
      exception
         when others =>
            Report.Failed ("Unexpected exception raised - Subtest 12");
      end;


      begin
         NP_Proc (Obj4);                 -- OK: Obj4 not constrained, can
         if Obj3 /= (3, "Bye") then      -- change discriminant value.
            Report.Failed
              ("Wrong value after aggregate assignment - Subtest 13");
         end if;
      exception
         when others =>
            Report.Failed ("Unexpected exception raised - Subtest 13");
      end;



      begin
         Is_Constrained := True;
         NP_Cons (Obj1, Is_Constrained);  -- Should return False, since Obj1
         if Is_Constrained then           -- is not constrained.
            Report.Failed ("Wrong result from 'Constrained - Subtest 14");
         end if;
      exception
         when others =>
            Report.Failed ("Unexpected exception raised - Subtest 14");
      end;


      begin
         Is_Constrained := False;
         NP_Cons (Obj2, Is_Constrained);  -- Should return False, Obj2 is
         if Is_Constrained then           -- not constrained.
            Report.Failed ("Wrong result from 'Constrained - Subtest 15");
         end if;
      exception
         when others =>
            Report.Failed ("Unexpected exception raised - Subtest 15");
      end;




      begin
         Is_Constrained := False;
         P_Cons (Ptr2, Is_Constrained);   -- Should return True, Ptr2.all
         if not Is_Constrained then       -- is constrained.
            Report.Failed ("Wrong result from 'Constrained - Subtest 16");
         end if;
      exception
         when others =>
            Report.Failed ("Unexpected exception raised - Subtest 16");
      end;


      begin
         Is_Constrained := False;
         P_Cons (Ptr3, Is_Constrained);   -- Should return True, Ptr3.all
         if not Is_Constrained then       -- is constrained.
            Report.Failed ("Wrong result from 'Constrained - Subtest 17");
         end if;
      exception
         when others =>
            Report.Failed ("Unexpected exception raised - Subtest 17");
      end;


   exception
      when others => Report.Failed("Exception raised in Subprogram_Block");
   end Subprogram_Block;


   Generic_Block:
   declare

      type NUC is new UC;

      Obj : NUC;


      package Instance_A is new Gen (NUC, Obj);
      package Instance_B is new Gen (UC, Obj2);
      package Instance_C is new Gen (UC, Obj3);
      package Instance_D is new Gen (UC, Obj4);

   begin

      begin
         Instance_A.Proc;                -- OK: Obj.D = 2.
         if Instance_A.F /= (2, "Fi") then
            Report.Failed
              ("Wrong value after aggregate assignment - Subtest 18");
         end if;
      exception
         when others =>
            Report.Failed ("Unexpected exception raised - Subtest 18");
      end;


      begin
         Instance_B.Proc;                -- OK: Obj2.D = 5.
         if Instance_B.F /= (2, "Fi") then
            Report.Failed
              ("Wrong value after aggregate assignment - Subtest 19");
         end if;
      exception
         when others =>
            Report.Failed ("Unexpected exception raised - Subtest 19");
      end;


      begin
         Instance_C.Proc;                -- OK: Obj3.D = 5.
         if Instance_C.F /= (2, "Fi") then
            Report.Failed
              ("Wrong value after aggregate assignment - Subtest 20");
         end if;
      exception
         when others =>
            Report.Failed ("Unexpected exception raised - Subtest 20");
      end;


      begin
         Instance_D.Proc;                -- OK: Obj4.D = 2.
         if Instance_D.F /= (2, "Fi") then
            Report.Failed
              ("Wrong value after aggregate assignment - Subtest 21");
         end if;
      exception
         when others =>
            Report.Failed ("Unexpected exception raised - Subtest 21");
      end;

   exception
      when others => Report.Failed("Exception raised in Generic_Block");
   end Generic_Block;


   Report.Result;

end C3A0014;
