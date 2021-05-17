
with Ada.Finalization;
with CXC7006_1;
package CXC7006_2 is
   type Fin_Type is new Ada.Finalization.Controlled with record
      Raise_Exc : Boolean := False;
      Fin_ID    : Integer := -1;
   end record;

   Fin_Exception : exception;

   overriding
   procedure Finalize (Obj : in out Fin_Type);

   procedure Clear_Fin_Array;

   procedure Test_Finalized (ID        : in Integer;
                             Finalized : out Boolean;
                             Err_Msg   : out CXC7006_1.String_Acc);

end CXC7006_2;
