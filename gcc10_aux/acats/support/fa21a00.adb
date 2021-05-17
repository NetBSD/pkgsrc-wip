

     --===================================================================--


package body FA21A00 is

   procedure Initialize (Object : in out My_Controlled) is
   begin
       Object.C := 10;
   end Initialize;

   task body Tsk is
   begin
      null;
   end Tsk;

   protected body Prot is
      entry E when False is
      begin
         null;
      end E;
   end Prot;

   function Func return My_Int is
   begin
      return 0;
   end Func;

end FA21A00;
