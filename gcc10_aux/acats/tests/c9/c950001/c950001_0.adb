
     --==================================================================--

package body C950001_0 is
   protected body Lock_Type is
      procedure Unlock is
      begin
         Unlocked := True;
      end Unlock;

      procedure Unlock_2 is
      begin
         Unlocked := True;
      end Unlock_2;

      entry Lock when Unlocked is
      begin
         Unlocked := False;
      end;

      entry Lock_2 when Unlocked is
      begin
         Unlocked := False;
      end Lock_2;
   end Lock_Type;

   procedure Try_Lock (L : in out Lock_Type; Success : out Boolean) is
   begin
      Success := False;
   end Try_Lock;

   function Get_Lock return Spinlock'Class is
   begin
      return Result : Lock_Type; -- Default initialized.
   end Get_Lock;

end C950001_0;
