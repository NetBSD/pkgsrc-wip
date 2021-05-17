

     --==================================================================--


package body CXC3001_0 is

   protected body Good is

      procedure Handler is
      begin
         Counter := Counter + 1;
      end Handler;

      function Count return Natural is
      begin
         return Counter;
      end Count;

      procedure Reset is
      begin
         Counter := 0;
      end Reset;

   end Good;


   protected body Bad is

      procedure Handler is
      begin
         Counter := Counter + 1;
      end Handler;

      function Count return Natural is
      begin
         return Counter;
      end Count;

   end Bad;

end CXC3001_0;
