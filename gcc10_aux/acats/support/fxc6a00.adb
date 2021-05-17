

     --==================================================================--


package body FXC6A00 is

   task body Task_Type is
   begin
      accept Calculate (C: in out Natural) do
         C := C * 10;
      end Calculate;
   end Task_Type;


   protected body Protected_Type is
      procedure Op is
      begin
         Count := Count + 1;
      end Op;
   end Protected_Type;


   protected body Volatile_Protected is
      procedure Handler is
      begin
         Was_Handled := True;
      end Handler;

      function Handled return Boolean is
      begin
         return Was_Handled;
      end Handled;
   end Volatile_Protected;

end FXC6A00;
