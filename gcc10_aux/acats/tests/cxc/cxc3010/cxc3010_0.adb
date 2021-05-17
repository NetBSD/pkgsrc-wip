
package body CXC3010_0 is
   protected body Device_Interface_T is
      procedure Handler is
      begin
         Handled := True;
      end Handler;
      procedure Check (Success : out Boolean) is
      begin
         Success := Handled;
         Handled := False;
      end Check;
   end Device_Interface_T;
end  CXC3010_0;
