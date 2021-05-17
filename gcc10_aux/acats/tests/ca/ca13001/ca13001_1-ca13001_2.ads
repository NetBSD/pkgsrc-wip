
-- No bodies required for CA13001_1.

     --==================================================================--

-- Private child. 

private package CA13001_1.CA13001_2 is       

   type Transport is
      record
         In_Use : boolean := false;
      end record;
   Vehicles : array (Transportation) of Transport;

   -- Other type definitions and procedure declarations in real application.

end CA13001_1.CA13001_2;
