
package body B650004 is

   -- Note: All errors are because of a return statement that is in a body
   -- that is within the construct that the return statement applies to,
   -- unless otherwise noted.

   procedure Proc is
      package Pack is
         procedure Dummy;
      end Pack;

      package body Pack is
         procedure Dummy is
         begin
            null;
         end Dummy;
      begin
         return;                               -- ERROR:
      end Pack;

      task Tsk1;

      task body Tsk1 is
      begin
         return;                               -- ERROR:
      end Tsk1;

   begin
      declare
         package Pack2 is
            procedure Dummy;
         end Pack2;

         package body Pack2 is
            procedure Dummy is
            begin
               null;
            end Dummy;
         begin
            return;                            -- ERROR:
         end Pack2;

         task Tsk2;

         task body Tsk2 is
         begin
            return;                            -- ERROR:
         end Tsk2;
      begin
         return;                               -- OK.
      end;
   end Proc;


   function Func return Natural is
      package Pack3 is
         procedure Dummy;
      end Pack3;

      package body Pack3 is
         procedure Dummy is
         begin
            null;
         end Dummy;
      begin
         if Obj = 10 then
            return 3;                          -- ERROR:
         else
            return Ret : Natural do            -- ERROR:
               Ret := 3;
            end return;
         end if;
      end Pack3;

      task Tsk3;

      task body Tsk3 is
      begin
         if Obj = 10 then
            return 3;                          -- ERROR:
         else
            return Ret : Natural do            -- ERROR:
               Ret := 3;
            end return;
         end if;
      end Tsk3;

   begin
      declare
         package Pack4 is
            procedure Dummy;
         end Pack4;

         package body Pack4 is
            procedure Dummy is
            begin
               null;
            end Dummy;
         begin
            if Obj = 10 then
               return 4;                       -- ERROR:
            else
               return Ret : Natural do         -- ERROR:
                  Ret := 4;
               end return;
            end if;
         end Pack4;

         task Tsk4;

         task body Tsk4 is
         begin
            if Obj = 10 then
               return 4;                       -- ERROR:
            else
               return Ret : Natural do         -- ERROR:
                  Ret := 4;
               end return;
            end if;
         end Tsk4;
      begin
         null;
      end;

      if Obj = 10 then
         return 10;                            -- OK.
      else
         return Ret : Natural do               -- OK.
            declare
               package Pack5 is
                  procedure Dummy;
               end Pack5;

               package body Pack5 is
                  procedure Dummy is
                  begin
                     null;
                  end Dummy;
               begin
                  return;                      -- ERROR:
               end Pack5;

               task Tsk5;

               task body Tsk5 is
               begin
                  return;                      -- ERROR:
               end Tsk5;
            begin
              Ret := 4;
              return;                          -- OK.
            end;
         end return;
      end if;
   end Func;

   task body Tsk is
   begin
      accept Ent do
         declare
            package Pack6 is
               procedure Dummy;
            end Pack6;

            package body Pack6 is
               procedure Dummy is
               begin
                  null;
               end Dummy;
            begin
               return;                         -- ERROR:
            end Pack6;

            task Tsk6;

            task body Tsk6 is
            begin
               return;                         -- ERROR:
            end Tsk6;
         begin
            null;
         end;
         return;                               -- OK.
      end Ent;

      return;                  -- ERROR: Not in a callable construct.
   end Tsk;

   protected body Prot is
      entry Ent when True is
         package Pack is
            procedure Dummy;
         end Pack;

         package body Pack is
            procedure Dummy is
            begin
               null;
            end Dummy;
         begin
            return;                            -- ERROR:
         end Pack;

         task Tsk6;

         task body Tsk6 is
         begin
            return;                            -- ERROR:
         end Tsk6;

      begin
         declare
            package Pack7 is
               procedure Dummy;
            end Pack7;

            package body Pack7 is
               procedure Dummy is
               begin
                  null;
               end Dummy;
            begin
               return;                         -- ERROR:
            end Pack7;

            task Tsk7;

            task body Tsk7 is
            begin
               return;                         -- ERROR:
            end Tsk7;
         begin
            return;                            -- OK.
         end;
      end Ent;
   end Prot;

begin
   return;                     -- ERROR: Not in a callable construct.
end B650004;



