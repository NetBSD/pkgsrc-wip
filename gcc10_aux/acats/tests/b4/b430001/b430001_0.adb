

     --==================================================================--

package body B430001_0 is

   procedure Op (P : Tag_Type) is
   begin
      null;
   end Op;

   -----------------------------------------
   function CW_Func return Tag_Type'Class is
   begin
      return Tag_Type'(Int1 => 100, Int2 => 100);
   end CW_Func;

end B430001_0;
