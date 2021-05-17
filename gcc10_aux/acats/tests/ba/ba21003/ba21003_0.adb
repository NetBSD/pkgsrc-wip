

     --===================================================================--


package body BA21003_0 is

   function Func return My_Int is
   begin
      return 0;
   end Func;

   task body Tsk is
   begin
      null;
   end Tsk;

   procedure Initialize (Obj : in out My_Controlled) is
   begin
      if Func /= 0 then
          raise Program_Error;
      end if;
   end Initialize;

   package body Bad_Subunit     is separate;
   package body Subunit_BadWith is separate; -- Body for this subunit is
                                             -- in file BA210031.A.
end BA21003_0;
