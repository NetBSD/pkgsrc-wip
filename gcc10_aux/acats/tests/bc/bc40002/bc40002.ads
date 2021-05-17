

     --==================================================================--


with BC40002_0; 
with BC40002_1; use BC40002_1;
package BC40002 is

   PT_Obj      : BC40002_0.PT;

   Tag_Obj     : BC40002_0.T;

   TClass_Obj  : BC40002_0.T'Class := Tag_Obj;

   DT_Obj      : BC40002_0.DT;

   DTClass_Obj : BC40002_0.DT'Class := DT_Obj;

--
-- Formal of: mode IN
--            type T
--

   package Formal_InT_Actual_T is new In_T (Tag_Obj);                 -- OK.

   package Formal_InT_Actual_PT is new In_T (PT_Obj);                 -- ERROR:
                                                    -- Type of actual is not T.

   package Formal_InT_Actual_DT is new In_T (DT_Obj);                 -- ERROR:
                                                    -- Type of actual is not T.
   package Formal_InT_Actual_TClass is new In_T (TClass_Obj);         -- ERROR:
                                                    -- Type of actual is not T.

   package Formal_InT_Actual_DTClass is new In_T (DTClass_Obj);       -- ERROR:
                                                    -- Type of actual is not T.


--
-- Formal of: mode IN
--            type T'Class
--

   package Formal_InTClass_Actual_T is new In_TClass (Tag_Obj);       -- OK.

   package Formal_InTClass_Actual_PT is new In_TClass (PT_Obj);       -- ERROR:
                                    -- Type of actual is not a type in class T.

   package Formal_InTClass_Actual_DT is new In_TClass (DT_Obj);       -- OK.

   package Formal_InTClass_Actual_TClass is 
     new In_TClass (TClass_Obj);                                      -- OK.

   package Formal_InTClass_Actual_DTClass is 
     new In_TClass (DTClass_Obj);                                     -- OK.


--
-- Formal of: mode IN OUT
--            type T
--

   package Formal_InOutT_Actual_T is new InOut_T (Tag_Obj);           -- OK.

   package Formal_InOutT_Actual_PT is new InOut_T (PT_Obj);           -- ERROR:
                                                    -- Type of actual is not T.

   package Formal_InOutT_Actual_DT is new InOut_T (DT_Obj);           -- ERROR:
                                                    -- Type of actual is not T.

   package Formal_InOutT_Actual_TClass is new InOut_T (TClass_Obj);   -- ERROR:
                                                    -- Type of actual is not T.

   package Formal_InOutT_Actual_DTClass is new InOut_T (DTClass_Obj); -- ERROR:
                                                    -- Type of actual is not T.


--
-- Formal of: mode IN OUT
--            type T'Class
--

   package Formal_InOutTClass_Actual_T is new InOut_TClass (Tag_Obj); -- ERROR:
                                              -- Type of actual is not T'Class.

   package Formal_InOutTClass_Actual_PT is new InOut_TClass (PT_Obj); -- ERROR:
                                              -- Type of actual is not T'Class.

   package Formal_InOutTClass_Actual_DT is new InOut_TClass (DT_Obj); -- ERROR:
                                              -- Type of actual is not T'Class.

   package Formal_InOutTClass_Actual_TClass is 
     new InOut_TClass (TClass_Obj);                                   -- OK.

   package Formal_InOutTClass_Actual_DTClass is 
     new InOut_TClass(DTClass_Obj);                                   -- ERROR:
                                              -- Type of actual is not T'Class.

end BC40002;
