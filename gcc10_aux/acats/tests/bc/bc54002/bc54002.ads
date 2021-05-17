

     --===================================================================--


with BC54002_0;
package BC54002 is

--
-- Support declarations:
--

   type New_Integer is new Integer;
   subtype New_Natural is New_Integer range 0 .. New_Integer'Last;

   subtype My_String is String (1 .. 20);

   subtype Rec_10 is BC54002_0.Rec(Len => 10);
   type New_Rec   is new BC54002_0.Rec(Len => 20) with null record;


--
-- Access-to-subprogram types to be passed as actuals:
--

   -- Access-to-procedure types:

   type Proc_Missing_Parameter is access
     procedure (A: in out String);

   type Proc_Extra_Parameter is access
     procedure (A: in out String; B, C: Natural);

   type Proc_Different_Default is access
     procedure (A: in out String; B: Natural := 25);

   type Wrong_Order is access
     procedure (A: Natural; B: in out String);

   type B_Has_Wrong_Type is access
     procedure (A: in out String; B: New_Natural);

   type Proc_Subtype_Diff is access
     procedure (A: in out My_String; B: in Integer);

   type Modes_Are_Swapped is access
     procedure (A: String; B: in out Natural);

   type A_Has_Wrong_Mode is access
     procedure (A: out String; B: Natural);

   type B_Has_Explicit_In_Mode is access
     procedure (A: in out String; B: in Natural);

   type Proc_Protected_Error is access protected
     procedure (A: in out String; B: Natural);

   type Proc_Protected_OK is access protected
     procedure (A: in Boolean);

   type Proc_Not_Protected_Error is access
     procedure (A: Boolean);


   -- Access-to-function types:

   type Func_Missing_Parameter is access
     function (A: BC54002_0.Rec) return Integer;

   type Func_Extra_Parameter is access
     function (A, B: BC54002_0.Rec; C: BC54002_0.Rec) return Integer;

   type Func_Has_Defaults is access
     function (A: BC54002_0.Rec := (3,"Nil");
               B: BC54002_0.Rec := (4,"None")) return Integer;

   type Wrong_Result_Type is access
     function (A, B: BC54002_0.Rec) return New_Integer;

   type A_And_B_Have_Wrong_Type is access
     function (A, B: New_Rec) return Integer;

   type Func_Subtype_Diff is access
     function (A: BC54002_0.Rec; B: Rec_10) return Natural;

   type Func_Explicitly_Aliased_Diff is access
     function (A: aliased BC54002_0.Rec; B: BC54002_0.Rec) return Natural;

   type Func_Protected_Error is access protected
     function (A, B: BC54002_0.Rec) return Integer;


--
-- Instantiations:
--

   -- Number of parameters; presence of defaults:

   package Instance01 is new
     BC54002_0.Procedure_Access (Proc_Missing_Parameter);             -- ERROR:
                                   -- Profile of actual has too few parameters.

   package Instance02 is new
     BC54002_0.Procedure_Access (Proc_Extra_Parameter);               -- ERROR:
                                  -- Profile of actual has too many parameters.

   package Instance03 is new
     BC54002_0.Procedure_Access (Proc_Different_Default);             -- OK.


   package Instance04 is new
     BC54002_0.Function_Access (Func_Missing_Parameter);              -- ERROR:
                                   -- Profile of actual has too few parameters.

   package Instance05 is new
     BC54002_0.Function_Access (Func_Extra_Parameter);                -- ERROR:
                                  -- Profile of actual has too many parameters.

   package Instance06 is new
     BC54002_0.Function_Access (Func_Has_Defaults);                   -- OK.


   -- Type/subtype of corresponding parameters:

   package Instance07 is new
     BC54002_0.Procedure_Access (Wrong_Order);                        -- ERROR:
             -- Corresponding parameters do not have same type (order swapped).

   package Instance08 is new
     BC54002_0.Procedure_Access (B_Has_Wrong_Type);                   -- ERROR:
            -- 2nd parameter in profile of actual has wrong type (New_Natural).

   package Instance09 is new
     BC54002_0.Procedure_Access (Proc_Subtype_Diff);                  -- ERROR:
                  -- Profile is mode conformant, but not subtype conformant.
                  -- Changed by AI05-0288-1, OK in Ada 95.

   package Instance10 is new
     BC54002_0.Function_Access (Wrong_Result_Type);                   -- ERROR:
                   -- Result in profile of actual has wrong type (New_Integer).

   package Instance11 is new
     BC54002_0.Function_Access (A_And_B_Have_Wrong_Type);             -- ERROR:
                  -- Parameters in profile of actual have wrong type (New_Rec).

   package Instance12 is new
     BC54002_0.Function_Access (Func_Subtype_Diff);                   -- ERROR:
                  -- Profile is mode conformant, but not subtype conformant.
                  -- Changed by AI05-0288-1, OK in Ada 95.


   -- Mode of corresponding parameters:

   package Instance13 is new
     BC54002_0.Procedure_Access (Modes_Are_Swapped);                  -- ERROR:
             -- Corresponding parameters do not have same mode (order swapped).

   package Instance14 is new
     BC54002_0.Procedure_Access (A_Has_Wrong_Mode);                   -- ERROR:
                    -- 1st parameter in profile of actual has wrong mode (out).

   package Instance15 is new
     BC54002_0.Procedure_Access (B_Has_Explicit_In_Mode);             -- OK.


   -- Protected vs. non-protected calling conventions:

   package Instance16 is new
     BC54002_0.Procedure_Access (Proc_Protected_Error);               -- ERROR:
                                  -- Calling convention of actual is protected.

   package Instance17 is new
     BC54002_0.Protected_Subprogram (Proc_Protected_OK);              -- OK.


   package Instance18 is new
     BC54002_0.Protected_Subprogram (Proc_Not_Protected_Error);       -- ERROR:
                              -- Calling convention of actual is not protected.

   package Instance19 is new
     BC54002_0.Function_Access (Func_Protected_Error);                -- ERROR:
                                  -- Calling convention of actual is protected.

   -- Mismatch of aliased parameters:

   package Instance20 is new
     BC54002_0.Function_Access (Func_Explicitly_Aliased_Diff);        -- ERROR:
                                  -- Function has explicitly aliased parameter.

   generic
      type Access_To_Proc is access
        procedure (P1: aliased in out String; P2: Natural := 0);
                                  -- Two parameters, first is aliased.
   package Aliased_Procedure_Access is end;

   package Instance21 is new
     Aliased_Procedure_Access (Proc_Different_Default);              -- ERROR:
                                  -- Procedure does not have explicitly aliased
                                  -- parameter.

end BC54002;
