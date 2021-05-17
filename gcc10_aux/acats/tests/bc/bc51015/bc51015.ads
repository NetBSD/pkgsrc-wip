

     --===================================================================--


with BC51015_0;
with BC51015_1;
with BC51015_2;
with BC51015_3;
with BC51015_4;
generic
   with package Formal_Package is new BC51015_4 (<>);
package BC51015 is

   --
   -- Actual is "basic" tagged type:
   --

   package Inst_1 is new BC51015_1 (BC51015_0.Tagged_Type);           -- ERROR:
                                                      -- Actual type is tagged.

   package Inst_2 is new BC51015_2 (BC51015_0.Tagged_Type);           -- OK.

   package Inst_3 is new BC51015_3 (BC51015_0.Tagged_Type);           -- OK.


   --
   -- Actual is private extension:
   --

   package Inst_4 is new BC51015_1 (BC51015_0.Private_Ext);           -- ERROR:
                                                      -- Actual type is tagged.

   package Inst_5 is new BC51015_2 (BC51015_0.Private_Ext);           -- OK.

   package Inst_6 is new BC51015_3 (BC51015_0.Private_Ext);           -- OK.


   --
   -- Actual is tagged formal private type:
   --

   package Inst_7 is new BC51015_1 (Formal_Package.Tagged_Private);   -- ERROR:
                                                      -- Actual type is tagged.

   package Inst_8 is new BC51015_2 (Formal_Package.Tagged_Private);   -- OK.

   package Inst_9 is new BC51015_3 (Formal_Package.Tagged_Private);   -- OK.


   --
   -- Actual is tagged formal derived type:
   --

   package Inst10 is new BC51015_1 (Formal_Package.Formal_Derived);   -- ERROR:
                                                      -- Actual type is tagged.

   package Inst11 is new BC51015_2 (Formal_Package.Formal_Derived);   -- OK.

   package Inst12 is new BC51015_3 (Formal_Package.Formal_Derived);   -- OK.

end BC51015;
