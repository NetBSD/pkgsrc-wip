
-- ----------------------------------------------------------------------------
with Report;
package body C432005_0 is

   protected body T_PO is
      entry Set (Value : in Integer) when True is
      begin
         Data := Value;
      end Set;
      procedure Get (Value : out Integer) is
      begin
         Value := Data;
      end Get;
   end T_PO;

   task body T_Task is
      Data : Integer := 0;
   begin
      accept Set (Value : in Integer) do
         Data := Value;
      end Set;
      accept Get (Value : out Integer) do
         Value := Data;
      end Get;
   end T_Task;

end C432005_0;
