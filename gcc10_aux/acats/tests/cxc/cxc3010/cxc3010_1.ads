
package CXC3010_1 is
   protected Alternate_Device_Interface is
      procedure Handler;
      procedure Check (Success : out Boolean);
   private
      Handled : Boolean := False; -- set to True by Handler; reset by Check
   end Alternate_Device_Interface;
end  CXC3010_1;
