
     --==================================================================--

package C950001_1 is

   Num_Tasks : constant := 2;
   Num_Iters : constant := 5_000;

   protected Monitor is
      procedure Signal_Ready;
      procedure Signal_Started;
      entry Wait_Ready (Success : out Boolean);
      entry Wait_Started;
   private
      Ready_Tasks : Natural := 0;
      Started     : Boolean := False;
   end Monitor;

end C950001_1;
