

with C432002_0;
with Report;
procedure C432002 is

   -- Various different-sized strings for variety
   String_3  : String (1..3)  := Report.Ident_Str("123");
   String_5  : String (1..5)  := Report.Ident_Str("12345");
   String_8  : String (1..8)  := Report.Ident_Str("12345678");
   String_10 : String (1..10) := Report.Ident_Str("1234567890");
   String_11 : String (1..11) := Report.Ident_Str("12345678901");
   String_20 : String (1..20) := Report.Ident_Str("12345678901234567890");

begin

   Report.Test ("C432002",
                "Extension aggregates for discriminated types");

   --------------------------------------------------------------------
   -- Extension constrains parent's discriminant to value of expression
   --------------------------------------------------------------------

   -- Successful cases - value matches corresponding discriminant value

   CD_Matched_Aggregate:
   begin
      declare
         CD : C432002_0.Constrained_Discriminant_Extension :=
            (C432002_0.Discriminant'(L  => 10,
                                     S1 => String_10)
               with S2 => String_20);
      begin
         C432002_0.Do_Something(CD); -- success
      end;
   exception
      when Constraint_Error =>
         Report.Comment ("Ancestor expression is an aggregate");
         Report.Failed ("Aggregate of extension " &
                        "with discriminant constrained: " &
                        "Constraint_Error was incorrectly raised " &
                        "for value that matches corresponding " &
                        "discriminant");
   end CD_Matched_Aggregate;
   
   CD_Matched_Variable:
   begin
      declare
         D : C432002_0.Discriminant(L => 10) :=
            C432002_0.Discriminant'(L  => 10,
                                    S1 => String_10);

         CD : C432002_0.Constrained_Discriminant_Extension :=
            (D with S2 => String_20);
      begin
         C432002_0.Do_Something(CD); -- success
      end;
   exception
      when Constraint_Error =>
         Report.Comment ("Ancestor expression is a variable");
         Report.Failed ("Aggregate of extension " &
                        "with discriminant constrained: " &
                        "Constraint_Error was incorrectly raised " &
                        "for value that matches corresponding " &
                        "discriminant");
   end CD_Matched_Variable;

   
   -- Unsuccessful cases - value does not match value of corresponding
   --                      discriminant. Constraint_Error should be
   --                      raised.

   CD_Unmatched_Aggregate:
   begin
      declare
         CD : C432002_0.Constrained_Discriminant_Extension :=
            (C432002_0.Discriminant'(L  => 5,
                                     S1 => String_5)
               with S2 => String_20);
      begin
         Report.Comment ("Ancestor expression is an aggregate");
         Report.Failed ("Aggregate of extension " &
                        "with discriminant constrained: " &
                        "Constraint_Error was not raised " &
                        "for discriminant value that does not match " &
                        "corresponding discriminant");
         C432002_0.Do_Something(CD); -- disallow unused var optimization
      end;
   exception
      when Constraint_Error =>
         null; -- raise of Constraint_Error is expected
   end CD_Unmatched_Aggregate;
   
   CD_Unmatched_Variable:
   begin
      declare
         D : C432002_0.Discriminant(L => 5) :=
            C432002_0.Discriminant'(L  => 5,
                                    S1 => String_5);

         CD : C432002_0.Constrained_Discriminant_Extension :=
            (D with S2 => String_20);
      begin
         Report.Comment ("Ancestor expression is an variable");
         Report.Failed ("Aggregate of extension " &
                        "with discriminant constrained: " &
                        "Constraint_Error was not raised " &
                        "for discriminant value that does not match " &
                        "corresponding discriminant");
         C432002_0.Do_Something(CD); -- disallow unused var optimization
      end;
   exception
      when Constraint_Error =>
         null; -- raise of Constraint_Error is expected
   end CD_Unmatched_Variable;

   -----------------------------------------------------------------------
   -- Extension constrains parent's discriminant to equal new discriminant
   -----------------------------------------------------------------------

   -- Successful cases - value matches corresponding discriminant value

   ND_Matched_Aggregate:
   begin
      declare
         ND : C432002_0.New_Discriminant_Extension (N => 8) :=
            (C432002_0.Discriminant'(L  => 8,
                                     S1 => String_8)
               with N  => 8,
                    S2 => String_8);
      begin
         C432002_0.Do_Something(ND); -- success
      end;
   exception
      when Constraint_Error =>
         Report.Comment ("Ancestor expression is an aggregate");
         Report.Failed ("Aggregate of extension " &
                        "with new discriminant: " &
                        "Constraint_Error was incorrectly raised " &
                        "for value that matches corresponding " &
                        "discriminant");
   end ND_Matched_Aggregate;
   
   ND_Matched_Variable:
   begin
      declare
         D : C432002_0.Discriminant(L => 3) :=
            C432002_0.Discriminant'(L  => 3,
                                    S1 => String_3);

         ND : C432002_0.New_Discriminant_Extension (N => 3) :=
            (D with N  => 3,
                    S2 => String_3);
      begin
         C432002_0.Do_Something(ND); -- success
      end;
   exception
      when Constraint_Error =>
         Report.Comment ("Ancestor expression is an variable");
         Report.Failed ("Aggregate of extension " &
                        "with new discriminant: " &
                        "Constraint_Error was incorrectly raised " &
                        "for value that matches corresponding " &
                        "discriminant");
   end ND_Matched_Variable;

   
   -- Unsuccessful cases - value does not match value of corresponding
   --                      discriminant. Constraint_Error should be
   --                      raised.
   
   ND_Unmatched_Aggregate:
   begin
      declare
         ND : C432002_0.New_Discriminant_Extension (N => 20) :=
            (C432002_0.Discriminant'(L  => 11,
                                     S1 => String_11)
               with N  => 20,
                    S2 => String_20);
      begin
         Report.Comment ("Ancestor expression is an aggregate");
         Report.Failed ("Aggregate of extension " &
                        "with new discriminant: " &
                        "Constraint_Error was not raised " &
                        "for discriminant value that does not match " &
                        "corresponding discriminant");
         C432002_0.Do_Something(ND); -- disallow unused var optimization
      end;
   exception
      when Constraint_Error =>
         null; -- raise is expected
   end ND_Unmatched_Aggregate;
   
   ND_Unmatched_Variable:
   begin
      declare
         D : C432002_0.Discriminant(L => 5) :=
            C432002_0.Discriminant'(L  => 5,
                                    S1 => String_5);

         ND : C432002_0.New_Discriminant_Extension (N => 20) :=
            (D with N  => 20,
                    S2 => String_20);
      begin
         Report.Comment ("Ancestor expression is an variable");
         Report.Failed ("Aggregate of extension " &
                        "with new discriminant: " &
                        "Constraint_Error was not raised " &
                        "for discriminant value that does not match " &
                        "corresponding discriminant");
         C432002_0.Do_Something(ND); -- disallow unused var optimization
      end;
   exception
      when Constraint_Error =>
         null; -- raise is expected
   end ND_Unmatched_Variable;

   --------------------------------------------------------------------
   -- Extension constrains parent's discriminant to value of expression
   -- Parent is a discriminant extension
   --------------------------------------------------------------------

   -- Successful cases - value matches corresponding discriminant value

   CE_Matched_Aggregate:
   begin
      declare
         CE : C432002_0.Constrained_Extension_Extension :=
            (C432002_0.Discriminant'(L  => 20,
                                     S1 => String_20)
               with N => 20,
                    S2 => String_20,
                    S3 => String_5);
      begin
         C432002_0.Do_Something(CE); -- success
      end;
   exception
      when Constraint_Error =>
         Report.Comment ("Ancestor expression is an aggregate");
         Report.Failed ("Aggregate of extension (of extension) " &
                        "with discriminant constrained: " &
                        "Constraint_Error was incorrectly raised " &
                        "for value that matches corresponding " &
                        "discriminant");
   end CE_Matched_Aggregate;
   
   CE_Matched_Variable:
   begin
      declare
         ND : C432002_0.New_Discriminant_Extension (N => 20) :=
            C432002_0.New_Discriminant_Extension'
               (N  => 20,
                S1 => String_20,
                S2 => String_20);

         CE : C432002_0.Constrained_Extension_Extension :=
            (ND with S3 => String_5);
      begin
         C432002_0.Do_Something(CE); -- success
      end;
   exception
      when Constraint_Error =>
         Report.Comment ("Ancestor expression is a variable");
         Report.Failed ("Aggregate of extension (of extension) " &
                        "with discriminant constrained: " &
                        "Constraint_Error was incorrectly raised " &
                        "for value that matches corresponding " &
                        "discriminant");
   end CE_Matched_Variable;

   
   -- Unsuccessful cases - value does not match value of corresponding
   --                      discriminant. Constraint_Error should be
   --                      raised.

   CE_Unmatched_Aggregate:
   begin
      declare
         CE : C432002_0.Constrained_Extension_Extension :=
            (C432002_0.New_Discriminant_Extension'
               (N  => 11,
                S1 => String_11,
                S2 => String_11)
            with S3 => String_5);
      begin
         Report.Comment ("Ancestor expression is an aggregate");
         Report.Failed ("Aggregate of extension (of extension) " &
                        "Constraint_Error was not raised " &
                        "with discriminant constrained: " &
                        "for discriminant value that does not match " &
                        "corresponding discriminant");
         C432002_0.Do_Something(CE); -- disallow unused var optimization
      end;
   exception
      when Constraint_Error =>
         null; -- raise of Constraint_Error is expected
   end CE_Unmatched_Aggregate;
   
   CE_Unmatched_Variable:
   begin
      declare
         D : C432002_0.Discriminant(L => 8) :=
            C432002_0.Discriminant'(L  => 8,
                                    S1 => String_8);

         CE : C432002_0.Constrained_Extension_Extension :=
            (D with N  => 8,
                    S2 => String_8,
                    S3 => String_5);
      begin
         Report.Comment ("Ancestor expression is a variable");
         Report.Failed ("Aggregate of extension (of extension) " &
                        "with discriminant constrained: " &
                        "Constraint_Error was not raised " &
                        "for discriminant value that does not match " &
                        "corresponding discriminant");
         C432002_0.Do_Something(CE); -- disallow unused var optimization
      end;
   exception
      when Constraint_Error =>
         null; -- raise of Constraint_Error is expected
   end CE_Unmatched_Variable;

   -----------------------------------------------------------------------
   -- Extension constrains parent's discriminant to equal new discriminant
   -- Parent is a discriminant extension
   -----------------------------------------------------------------------

   -- Successful cases - value matches corresponding discriminant value

   NE_Matched_Aggregate:
   begin
      declare
         NE : C432002_0.New_Extension_Extension (I => 8) :=
            (C432002_0.Discriminant'(L  => 8,
                                     S1 => String_8)
               with I  => 8,
                    S2 => String_8,
                    S3 => String_8);
      begin
         C432002_0.Do_Something(NE); -- success
      end;
   exception
      when Constraint_Error =>
         Report.Comment ("Ancestor expression is an aggregate");
         Report.Failed ("Aggregate of extension (of extension) " &
                        "with new discriminant: " &
                        "Constraint_Error was incorrectly raised " &
                        "for value that matches corresponding " &
                        "discriminant");
   end NE_Matched_Aggregate;
   
   NE_Matched_Variable:
   begin
      declare
         ND : C432002_0.New_Discriminant_Extension (N => 3) :=
            C432002_0.New_Discriminant_Extension'
               (N  => 3,
                S1 => String_3,
                S2 => String_3);

         NE : C432002_0.New_Extension_Extension (I => 3) :=
            (ND with I  => 3,
                     S3 => String_3);
      begin
         C432002_0.Do_Something(NE); -- success
      end;
   exception
      when Constraint_Error =>
         Report.Comment ("Ancestor expression is a variable");
         Report.Failed ("Aggregate of extension (of extension) " &
                        "with new discriminant: " &
                        "Constraint_Error was incorrectly raised " &
                        "for value that matches corresponding " &
                        "discriminant");
   end NE_Matched_Variable;

   
   -- Unsuccessful cases - value does not match value of corresponding
   --                      discriminant. Constraint_Error should be
   --                      raised.

   NE_Unmatched_Aggregate:
   begin
      declare
         NE : C432002_0.New_Extension_Extension (I => 8) :=
            (C432002_0.New_Discriminant_Extension'
               (C432002_0.Discriminant'(L  => 11,
                                        S1 => String_11)
                with N  => 11,
                     S2 => String_11)
            with I  => 8,
                 S3 => String_8);
      begin
         Report.Comment ("Ancestor expression is an extension aggregate");
         Report.Failed ("Aggregate of extension (of extension) " &
                        "with new discriminant: " &
                        "Constraint_Error was not raised " &
                        "for discriminant value that does not match " &
                        "corresponding discriminant");
         C432002_0.Do_Something(NE); -- disallow unused var optimization
      end;
   exception
      when Constraint_Error =>
         null; -- raise is expected
   end NE_Unmatched_Aggregate;
   
   NE_Unmatched_Variable:
   begin
      declare
         D : C432002_0.Discriminant(L => 5) :=
            C432002_0.Discriminant'(L  => 5,
                                    S1 => String_5);

         NE : C432002_0.New_Extension_Extension (I => 20) :=
            (D with I  => 5,
                    S2 => String_5,
                    S3 => String_20);
      begin
         Report.Comment ("Ancestor expression is a variable");
         Report.Failed ("Aggregate of extension (of extension) " &
                        "with new discriminant: " &
                        "Constraint_Error was not raised " &
                        "for discriminant value that does not match " &
                        "corresponding discriminant");
         C432002_0.Do_Something(NE); -- disallow unused var optimization
      end;
   exception
      when Constraint_Error =>
         null; -- raise is expected
   end NE_Unmatched_Variable;

   -----------------------------------------------------------------------
   -- Corresponding discriminant is two levels deeper than aggregate
   -----------------------------------------------------------------------

   -- Successful case - value matches corresponding discriminant value

   TR_Matched_Variable:
   begin
      declare
         D : C432002_0.Discriminant (L => 10) :=
            C432002_0.Discriminant'(L  => 10,
                                    S1 => String_10);

         TR : C432002_0.Twice_Removed :=
            C432002_0.Twice_Removed'(D with S2 => String_20,
                                            S3 => String_3,
                                            S4 => String_8);
         -- N is constrained to a value in the derived_type_definition
         -- of Constrained_Discriminant_Extension. Its omission from
         -- the above record_component_association_list is allowed by
         -- 4.3.2(6).

      begin
         C432002_0.Do_Something(TR); -- success
      end;
   exception
      when Constraint_Error =>
         Report.Failed ("Aggregate of far-removed extension " &
                        "with discriminant constrained: " &
                        "Constraint_Error was incorrectly raised " &
                        "for value that matches corresponding " &
                        "discriminant");
   end TR_Matched_Variable;
   
   
   -- Unsuccessful case - value does not match value of corresponding
   --                      discriminant. Constraint_Error should be
   --                      raised.

   TR_Unmatched_Variable:
   begin
      declare
         D : C432002_0.Discriminant (L => 5) :=
            C432002_0.Discriminant'(L  => 5,
                                    S1 => String_5);

         TR : C432002_0.Twice_Removed :=
            C432002_0.Twice_Removed'(D with S2 => String_20,
                                            S3 => String_3,
                                            S4 => String_8);

      begin
         Report.Failed ("Aggregate of far-removed extension " &
                        "with discriminant constrained: " &
                        "Constraint_Error was not raised " &
                        "for discriminant value that does not match " &
                        "corresponding discriminant");
         C432002_0.Do_Something(TR); -- disallow unused var optimization
      end;
   exception
      when Constraint_Error =>
         null; -- raise is expected
   end TR_Unmatched_Variable;
   
   ------------------------------------------------------------------------
   -- Parent has multiple discriminants.
   -- Discriminant in extension corresponds to both parental discriminants.
   ------------------------------------------------------------------------

   -- Successful case - value matches corresponding discriminant value

   MD_Matched_Variable:
   begin
      declare
         MD : C432002_0.Multiple_Discriminants (A => 10, B => 10) :=
            C432002_0.Multiple_Discriminants'(A  => 10,
                                              B  => 10,
                                              S1 => String_10,
                                              S2 => String_10);
         MDE : C432002_0.Multiple_Discriminant_Extension (C => 10) :=
            (MD with C  => 10,
                     S3 => String_10);

      begin
         C432002_0.Do_Something(MDE); -- success
      end;
   exception
      when Constraint_Error =>
         Report.Failed ("Aggregate of extension " &
                        "of multiply-discriminated parent: " &
                        "Constraint_Error was incorrectly raised " &
                        "for value that matches corresponding " &
                        "discriminant");
   end MD_Matched_Variable;

   
   -- Unsuccessful case - value does not match value of corresponding
   --                      discriminant. Constraint_Error should be
   --                      raised.

   MD_Unmatched_Variable:
   begin
      declare
         MD : C432002_0.Multiple_Discriminants (A => 10, B => 8) :=
            C432002_0.Multiple_Discriminants'(A  => 10,
                                              B  => 8,
                                              S1 => String_10,
                                              S2 => String_8);
         MDE : C432002_0.Multiple_Discriminant_Extension (C => 10) :=
            (MD with C  => 10,
                     S3 => String_10);

      begin
         Report.Failed ("Aggregate of extension " &
                        "of multiply-discriminated parent: " &
                        "Constraint_Error was not raised " &
                        "for discriminant value that does not match " &
                        "corresponding discriminant");
         C432002_0.Do_Something(MDE); -- disallow unused var optimization
      end;
   exception
      when Constraint_Error =>
         null; -- raise is expected
   end MD_Unmatched_Variable;

   Report.Result;

end C432002;
