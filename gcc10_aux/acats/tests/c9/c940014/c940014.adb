


with Report;
with ImpDef;
with Ada.Finalization;
with C940014_0;

procedure C940014 is
   Verbose : constant Boolean := C940014_0.Verbose;

begin
 
   Report.Test ("C940014", "Check that the finalization of a protected" &
                           " object results in program_error being raised" &
                           " at the point of the entry call statement for" &
                           " any tasks remaining on any entry queue");

   First_Check: declare
       -- example from ARM 9.4(20a-f);6.0 with minor mods
       task T is
           entry E;
       end T;
       task body T is
           protected PO is
               entry Ee;
           end PO;
           protected body PO is
               entry Ee when Report.Ident_Bool (False) is
               begin
                   null;
               end Ee;
           end PO;
       begin
           accept E do
                requeue PO.Ee;
           end E;
           if Verbose then
                Report.Comment ("task about to terminate");
           end if;
       end T;
   begin  -- First_Check
       begin
           T.E;
           delay ImpDef.Clear_Ready_Queue;
           Report.Failed ("exception not raised in First_Check");
       exception
           when Program_Error =>
               if Verbose then
                   Report.Comment ("ARM Example passed");
               end if;
           when others =>
               Report.Failed ("wrong exception in First_Check");
       end;
   end First_Check;
 

   Second_Check : declare
      -- here we want to check that the raising of Program_Error
      -- occurs before the other finalization actions.
       task T is
           entry E;
       end T;
       task body T is
           protected PO is
               entry Ee;
           private
               Component : C940014_0.Has_Finalization;
           end PO;
           protected body PO is
               entry Ee when Report.Ident_Bool (False) is
               begin
                   null;
               end Ee;
           end PO;
       begin
           accept E do
                requeue PO.Ee;
           end E;
           if Verbose then
                Report.Comment ("task about to terminate");
           end if;
       end T;
   begin  -- Second_Check
       T.E;
       delay ImpDef.Clear_Ready_Queue;
       Report.Failed ("exception not raised in Second_Check");
   exception
       when Program_Error =>
           if C940014_0.Finalization_Occurred then
               Report.Failed ("wrong order for finalization");
           elsif Verbose then
               Report.Comment ("Second_Check passed");
           end if;
       when others =>
           Report.Failed ("Wrong exception in Second_Check");
   end Second_Check;


   Report.Result;
 
end C940014;
