
     --==================================================================--

with C950001_0;
package body C950001_1 is
   Lock : C950001_0.Spinlock'Class := C950001_0.Get_Lock;
       -- As this is an object of the interface type, all of the calls will
       -- be dispatching calls.

   type Count_Range is range 0 .. Num_Tasks * Num_Iters;
   protected Counter is
      procedure Clear_Count;
      procedure Bump_Count;
      function Read_Count return Count_Range;
   private
      Count : Count_Range;
   end Counter;

   protected body Counter is
      procedure Clear_Count is
      begin
         Count := 0;
      end Clear_Count;

      procedure Bump_Count is
      begin
         Count := Count + 1;
      end Bump_Count;

      function Read_Count return Count_Range is
      begin
         return Count;
      end Read_Count;
   end Counter;

   protected body Monitor is
      procedure Signal_Ready is
      begin
         Ready_Tasks := Ready_Tasks + 1;
      end Signal_Ready;

      procedure Signal_Started is
      begin
         Counter.Clear_Count;
         Started := True;
      end Signal_Started;

      entry Wait_Ready (Success : out Boolean) when Ready_Tasks = Num_Tasks is
      begin
         Success := Counter.Read_Count = Num_Tasks * Num_Iters;
         Ready_Tasks := 0;
      end Wait_Ready;

      entry Wait_Started when Started is
      begin
         null;
      end Wait_Started;
   end Monitor;

   task type Counter_Task is
   end Counter_Task;

   task body Counter_Task is
   begin
      Monitor.Wait_Started;

      for J in 1 .. Num_Iters loop
         if J mod 2 = 0 then
            Lock.Lock;
            Counter.Bump_Count;
            Lock.Unlock;
         else
            Lock.Lock_2;
            Counter.Bump_Count;
            Lock.Unlock_2;
         end if;
      end loop;

      Monitor.Signal_Ready;
   end Counter_Task;

   Counters : array (1 .. Num_Tasks) of Counter_Task;
end C950001_1;
