
package body CXC7006_2 is

   Fin_Array : array (1 .. 10) of Boolean := (others => False);

   overriding
   procedure Finalize (Obj : in out Fin_Type) is
   begin
      if Obj.Fin_ID in Fin_Array'range then
         Fin_Array (Obj.Fin_ID) := True;
      end if;
      if Obj.Raise_Exc then
         raise Fin_Exception;
      end if;
   end Finalize;

   procedure Clear_Fin_Array is
   begin
      Fin_Array := (others => False);
   end Clear_Fin_Array;

   procedure Test_Finalized (ID        : in Integer;
                             Finalized : out Boolean;
                             Err_Msg   : out CXC7006_1.String_Acc) is
   begin
      if ID not in Fin_Array'range then
         Finalized := False;
         Err_Msg := new String' ("Fin_Type ID not set up correctly");
      elsif not Fin_Array (ID) then
         Finalized := False;
         Err_Msg := new String' ("Fin_Type object not yet finalized");
      else
         Finalized := True;
      end if;
   end Test_Finalized;

end CXC7006_2;
