

     --==================================================================--


package body C460A02_1 is
   procedure Dummy is
   begin
      null;
   end Dummy;
begin
   FRes := F460A00.UN_Init;
   FObj := Target_Type(Ptr);
   FRes := F460A00.OK;
exception
   when Program_Error => FRes := F460A00.PE_Exception;
   when others        => FRes := F460A00.Others_Exception;
end C460A02_1;
