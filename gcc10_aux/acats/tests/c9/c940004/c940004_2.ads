
--=============================================--

with Report;
with C940004_0; -- Resource_Pkg,
with C940004_1; -- Generic_Semaphore_Pkg;

package C940004_2 is
-- Printer_Mgr_Pkg

   -- Instantiate the generic to get code to manage a single printer;
   -- User processes contend for the printer, asking for it by a call
   -- to Request, and relinquishing it by a call to Release

   -- This package extends a tagged type to customize it for the printer
   -- in question, then it uses the type to instantiate the generic and
   -- declare a semaphore specific to the particular resource

   package Resource_Pkg          renames C940004_0;

   type User_Desc_Type is new Resource_Pkg.User_Descriptor_Type with record
       New_Details : Integer := 0;    -- for example
   end record;

   package Instantiation is new C940004_1   -- Generic_Semaphore_Pkg
                                   (Generic_Record_Type => User_Desc_Type);

   Printer_Access_Mgr : Instantiation.Semaphore_Type;


end C940004_2; -- Printer_Mgr_Pkg
