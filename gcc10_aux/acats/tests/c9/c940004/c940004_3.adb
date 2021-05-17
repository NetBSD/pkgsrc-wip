
--==============================================--

with Report;
with C940004_0; -- Resource_Pkg,
with C940004_2; -- Printer_Mgr_Pkg,

package body C940004_3 is
-- User_Task_Pkg

   task body User_Task_Type is
      D : Printer_Mgr_Pkg.Instantiation.User_Rec_Type;
   begin
      D.Id := ID;
            -----------------------------------
      Main:
      loop
         select
            accept Get_Printer;
            Printer_Mgr_Pkg.Printer_Access_Mgr.Request (D);
                      -- request resource; if resource is not available,
                      -- task will be queued to wait
            --===================--
            -- Test management machinery
            --===================--
            TC_Times_Obtained := TC_Times_Obtained + 1;
                      -- when request granted, note it and post a message

         or
           accept Release_Printer  (Descriptor : in out
                             Printer_Mgr_Pkg.Instantiation.User_Rec_Type) do

              Printer_Mgr_Pkg.Printer_Access_Mgr.Release (D);
                          -- release the resource, note its release
              TC_Times_Released := TC_Times_Released + 1;
              Descriptor := D;
           end Release_Printer;
           exit Main;

         or
           accept TC_Get_Descriptor  (Descriptor : out
                            Printer_Mgr_Pkg.Instantiation.User_Rec_Type) do

              Descriptor := D;
           end TC_Get_Descriptor;

         end select;
      end loop main;

   exception
      when others => Report.Failed ("exception raised in User_Task");
   end User_Task_Type;

end C940004_3;   -- User_Task_Pkg;
