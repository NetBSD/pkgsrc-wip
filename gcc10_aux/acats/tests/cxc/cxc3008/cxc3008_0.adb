

     --==================================================================--


package body CXC3008_0 is

   protected body Handler_Type is
      procedure Handler is
      begin
         Count := Count + 1;
      end Handler;

      function Handle_Count return Natural is
      begin
         return Count;
      end Handle_Count;
   end Handler_Type;


   protected body Dynamic1 is
      procedure Handler is
      begin
         Count := Count + 1;
      end Handler;

      function Handle_Count return Natural is
      begin
         return Count;
      end Handle_Count;
   end Dynamic1;


   protected body Dynamic2 is
      procedure Handler is
      begin
         Count := Count + 1;
      end Handler;

      function Handle_Count return Natural is
      begin
         return Count;
      end Handle_Count;
   end Dynamic2;

end CXC3008_0;
