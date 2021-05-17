
--============================--
-- no body for C940004_2
--============================--

with C940004_0; -- Resource_Pkg,
with C940004_2; -- Printer_Mgr_Pkg;

package C940004_3 is
-- User_Task_Pkg

-- This package models user tasks  that will request and release
-- the printer
   package Resource_Pkg    renames C940004_0;
   package Printer_Mgr_Pkg renames C940004_2;

   task type User_Task_Type (ID : Resource_Pkg.ID_Type) is
      entry Get_Printer;   -- instructs task to request resource

      entry Release_Printer    -- instructs task to release printer
          (Descriptor : in out Printer_Mgr_pkg.Instantiation.User_Rec_Type);

      --==================--
      -- Test management machinery
      --==================--
      entry TC_Get_Descriptor       -- returns descriptor
            (Descriptor :  out Printer_Mgr_Pkg.Instantiation.User_Rec_Type);

   end User_Task_Type;

   --==================--
   -- Test management machinery
   --==================--
   TC_Times_Obtained : Integer := 0;
   TC_Times_Released : Integer := 0;

end C940004_3; -- User_Task_Pkg;
