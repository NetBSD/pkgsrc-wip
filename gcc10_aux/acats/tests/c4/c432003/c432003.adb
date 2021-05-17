

   --=====================================================================--


with C432003_0;
with Report;
procedure C432003 is
begin

   Report.Test("C432003", "Extension aggregates where ancestor part "      &
                          "is a subtype mark that denotes a constrained "  &
                          "subtype causing Constraint_Error if any "       &
                          "discriminant of the ancestor has a different "  &
                          "value than that specified for a corresponding " &
                          "discriminant in the derived type definition "   &
                          "for some ancestor of the type of the aggregate");

   Test_Block:
      declare

         -- Variety of string object declarations.
         String2  : String(1..2)  := Report.Ident_Str("12");
         String5  : String(1..5)  := Report.Ident_Str("12345");
         String8  : String(1..8)  := Report.Ident_Str("AbCdEfGh");
         String10 : String(1..10) := Report.Ident_Str("1234567890");
         String15 : String(1..15) := Report.Ident_Str("123456789012345");
         String20 : String(1..20) := Report.Ident_Str("12345678901234567890");

      begin


         begin
            declare
               A : C432003_0.NT_A1 :=                                  -- OK
                     (C432003_0.ROOT with D2   => 5,
                                          Str1 => "cdefg",
                                          S2   => String5);
            begin
               C432003_0.Avoid_Optimization(A);
               if A.Acc  /= 356       or
                  A.Str1 /= "cdefg"   or
                  A.S2   /= String5   or 
                  A.D2   /= 5         or
                  A.S1   /= C432003_0.Default_String(1..5)
               then
                  Report.Failed("Incorrect object values for Object A");
               end if;
            end;
         exception
            when Constraint_Error =>
               Report.Failed("Constraint_Error raised for Object A");
         end;


         begin
            declare
               C: C432003_0.NT_A1 :=                                   -- OK
                    (C432003_0.Constrained_Subtype with D2 => 10,
                                                        S2 => String10);
            begin
               C432003_0.Avoid_Optimization(C);
               if C.D2   /= 10        or  C.Acc /= 356      or
                  C.Str1 /= "abcde"   or  C.S2  /= String10 or
                  C.S1   /= C432003_0.Default_String(1..10)
               then
                  Report.Failed("Incorrect object values for Object C");
               end if;
            end;
         exception
            when Constraint_Error =>
               Report.Failed("Constraint_Error raised for Object C");
         end;


         begin
            declare 
               D: C432003_0.NT_A1 :=                                  -- C_E
                    (C432003_0.Constrained_Subtype with 
                       D2 => Report.Ident_Int(5),
                       S2 => String5);
            begin
               C432003_0.Avoid_Optimization(D);
               Report.Failed("Constraint_Error not raised for Object D");
            end;
         exception
            when Constraint_Error =>
               null;  -- Raise of Constraint_Error is expected.
         end;


         begin
            declare
               E: C432003_0.NT_A2 :=                                   -- OK
                    (C432003_0.Constrained_Subtype with D3 => 10,
                                                        S2 => String10,
                                                        S3 => String10);
            begin
               C432003_0.Avoid_Optimization(E);
               if E.D3   /= 10        or  E.Acc /= 356        or
                  E.Str1 /= "abcde"   or  E.S2  /= String10   or
                  E.S3   /= String10  or
                  E.S1   /= C432003_0.Default_String(1..10)
               then
                  Report.Failed("Incorrect object values for Object E");
               end if;
            end;
         exception
            when Constraint_Error =>
               Report.Failed("Constraint_Error raised for Object E");
         end;


         begin
            declare
               F: C432003_0.NT_A2 :=                                  -- C_E
                    (C432003_0.Constrained_Subtype with 
                       D3 => Report.Ident_Int(5),  
                       S2 => String5,
                       S3 => String5);
            begin
               C432003_0.Avoid_Optimization(F);
               Report.Failed("Constraint_Error not raised for Object F");
            end;
         exception
            when Constraint_Error =>
               null;  -- Raise of Constraint_Error is expected.
         end;


         begin
            declare
               G: C432003_0.NT_B2 :=                                  -- OK
                    (C432003_0.ROOT with D3   => 5,     
                                         Str1 => "cdefg",
                                         S2   => String10,
                                         S3   => String5);
            begin
               C432003_0.Avoid_Optimization(G);
               if G.D3   /= 5         or  G.Acc /= 356       or
                  G.Str1 /= "cdefg"   or  G.S2  /= String10  or
                  G.S3   /= String5   or
                  G.S1   /= C432003_0.Default_String(1..5)
               then
                  Report.Failed("Incorrect object values for Object G");
               end if;
            end;
         exception
            when Constraint_Error =>
               Report.Failed("Constraint_Error raised for Object G");
         end;


         begin
            declare
               H: C432003_0.NT_B3 :=                                    -- OK
                    (C432003_0.Unconstrained_Der with D2 => 5,
                                                      S2 => String5);
            begin
               C432003_0.Avoid_Optimization(H);
               if H.D2   /= 5          or  H.Acc /= 356      or
                  H.Str1 /= "abcde"    or  H.S2  /= String5  or
                  H.S1   /= C432003_0.Default_String(1..10)
               then
                  Report.Failed("Incorrect object values for Object H");
               end if;
            end;
         exception
            when Constraint_Error =>
               Report.Failed("Constraint_Error raised for Object H");
         end;


         begin
            declare
               I: C432003_0.NT_B1 :=                                  -- C_E
                    (C432003_0.Constrained_Subtype with 
                        D2 => Report.Ident_Int(10),
                        S2 => String10);
            begin
               C432003_0.Avoid_Optimization(I);
               Report.Failed("Constraint_Error not raised for Object I");
            end;
         exception
            when Constraint_Error =>
               null;  -- Raise of Constraint_Error is expected.
         end;


         begin
            declare
               J: C432003_0.NT_B2 :=                                  -- C_E
                    (C432003_0.Constrained_Subtype with 
                       D3 => Report.Ident_Int(10),
                       S2 => String10,
                       S3 => String10);
            begin
               C432003_0.Avoid_Optimization(J);
               Report.Failed("Constraint_Error not raised by Object J");
            end;
         exception
            when Constraint_Error =>
               null;  -- Raise of Constraint_Error is expected.
         end;


         begin
            declare
               K: C432003_0.NT_B3 :=                                   -- OK
                    (C432003_0.Constrained_Subtype with D2 => 5,
                                                        S2 => String5);
            begin
               C432003_0.Avoid_Optimization(K);
               if K.D2   /= 5          or  K.Acc /= 356       or
                  K.Str1 /= "abcde"    or  K.S2  /= String5   or
                  K.S1   /= C432003_0.Default_String(1..10)
               then
                  Report.Failed("Incorrect object values for Object K");
               end if;
            end;
         exception
            when Constraint_Error =>
               Report.Failed("Constraint_Error raised for Object K");
         end;


         begin
            declare
               M: C432003_0.NT_C2 :=                                   -- OK
                    (C432003_0.ROOT with D2   => 10,
                                         Str1 => "cdefg",
                                         Str2 => String5,
                                         S2   => String10);
            begin
               C432003_0.Avoid_Optimization(M);
               if M.D2   /= 10         or  M.Acc /= 356       or
                  M.Str1 /= "cdefg"    or  M.S2  /= String10  or
                  M.Str2 /= String5    or
                  M.S1   /= C432003_0.Default_String(1..5)
               then
                  Report.Failed("Incorrect object values for Object M");
               end if;
            end;
         exception
            when Constraint_Error =>
               Report.Failed("Constraint_Error raised for Object M");
         end;


         begin
            declare
               O: C432003_0.NT_C1 :=                                  -- C_E
                    (C432003_0.Constrained_Subtype with 
                       Str2 => Report.Ident_Str(String5));
            begin
               C432003_0.Avoid_Optimization(O);
               Report.Failed("Constraint_Error not raised for Object O");
            end;
         exception
            when Constraint_Error =>
               null;  -- Raise of Constraint_Error is expected.
         end;


         begin
            declare
               P: C432003_0.NT_C2 :=                                  -- C_E
                    (C432003_0.Constrained_Subtype with 
                       D2   => Report.Ident_Int(10),
                       Str2 => String5,
                       S2   => String10);
            begin
               C432003_0.Avoid_Optimization(P);
               Report.Failed("Constraint_Error not raised by Object P");
            end;
         exception
            when Constraint_Error =>
               null;  -- Raise of Constraint_Error is expected.
         end;


         begin
            declare
               Q: C432003_0.NT_C3 := 
                  (C432003_0.Constrained_Subtype with Str2 => String5);  -- OK
            begin
               C432003_0.Avoid_Optimization(Q);
               if Q.Str2 /= String5  or  
                  Q.Acc  /= 356      or  
                  Q.Str1 /= "abcde"  or
                  Q.D1   /= 10       or
                  Q.S1   /= C432003_0.Default_String(1..10)
               then
                  Report.Failed("Incorrect object values for Object Q");
               end if;
            end;
         exception
            when Constraint_Error =>
               Report.Failed("Constraint_Error raised for Object Q");
         end;


         -- The following cases test where a new discriminant corresponds
         -- to multiple discriminants of the type of the ancestor part.

         begin
            declare
               S: C432003_0.Mult_NT_A1 :=                              -- OK
                    (C432003_0.Mult_Unconstr_Der with D3 => 15,
                                                      S3 => String15);
            begin
               C432003_0.Avoid_Optimization(S);
               if S.S1   /= C432003_0.Default_String(1..15)  or  
                  S.Str1 /= String8                          or
                  S.S2   /= C432003_0.Another_String(1..15)  or  
                  S.S3   /= String15                         or
                  S.D3   /= 15
               then
                  Report.Failed("Incorrect object values for Object S");
               end if;
            end;
         exception
            when Constraint_Error =>
               Report.Failed("Constraint_Error raised for Object S");
         end;


         begin
            declare
               U: C432003_0.Mult_NT_A1 :=                             -- C_E
                    (C432003_0.Mult_Constr_Sub1 with 
                       D3 => Report.Ident_Int(15),
                       S3 => String15);
            begin
               C432003_0.Avoid_Optimization(U);
               Report.Failed("Constraint_Error not raised for Object U");
            end;
         exception
            when Constraint_Error =>
               null;  -- Raise of Constraint_Error is expected.
         end;


         begin
            declare
               V: C432003_0.Mult_NT_A1 :=                              -- OK
                    (C432003_0.Mult_Constr_Sub2 with D3 => 15,
                                                     S3 => String15);
            begin
               C432003_0.Avoid_Optimization(V);
               if V.D3   /= 15        or  
                  V.Str1 /= String8   or
                  V.S3   /= String15  or
                  V.S1   /= C432003_0.Default_String(1..15) or
                  V.S2   /= C432003_0.Another_String(1..15)
               then
                  Report.Failed("Incorrect object values for Object V");
               end if;
            end;
         exception
            when Constraint_Error =>
               Report.Failed("Constraint_Error raised for Object V");
         end;


      exception
         when others => Report.Failed("Exception raised in Test_Block");
      end Test_Block;

      Report.Result;

end C432003;
