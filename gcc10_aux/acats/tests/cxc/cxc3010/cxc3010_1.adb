
package body CXC3010_1 is
   protected body Alternate_Device_Interface is
      procedure Handler is
      begin
         Handled := True;
      end Handler;
      procedure Check (Success : out Boolean) is
      begin
         Success := Handled;
         Handled := False;
      end Check;
   end Alternate_Device_Interface;
end  CXC3010_1;
