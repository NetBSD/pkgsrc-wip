

     --==================================================================--


with TCTouch;
package body C490002_0 is

   procedure Fixed_Subtest (A, B: in My_Fix; Msg: in String) is
   begin
       TCTouch.Assert (A = B, Msg);
   end Fixed_Subtest;

   procedure Fixed_Subtest (A, B, C: in My_Fix; Msg: in String) is
   begin
       TCTouch.Assert (A = B or A = C, Msg);
   end Fixed_Subtest;

end C490002_0;
