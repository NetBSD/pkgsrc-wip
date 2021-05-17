

  --=======================================================================--

with Report;

package body C3A0014_0 is

   procedure NP_Proc (A: out UC) is
   begin
      A := (3, "Bye");
   end NP_Proc;

   procedure NP_Cons (A: in out UC; B: out Boolean) is
   begin
      B := A'Constrained;
   end NP_Cons;

   procedure P_Cons (A: out AUC; B: out Boolean) is
   begin
      B := A.all'Constrained;
   end P_Cons;


   package body Gen is

      procedure Proc is
      begin
         F := (2, "Fi");
      end Proc;

   end Gen;


   procedure Avoid_Optimization_and_Fail ( P : UC; Msg : String ) is
      Default : UC := (1, "!"); -- Unique value.
   begin
      if P = Default then       -- Both If branches can't do the same thing.
         Report.Failed  (Msg & ": Constraint_Error not raised");
      else                      -- Subtests should always select this path.
         Report.Failed ("Constraint_Error not raised " & Msg);
      end if;
   end Avoid_Optimization_and_Fail;


end C3A0014_0;
