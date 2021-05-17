

     --===================================================================--


package body BA21A02 is

   procedure Dummy is
   begin
      null;
   end Dummy;

   type ArrType is array (1 .. FA21A00.Func) of Boolean;              -- ERROR:
                                  -- Call to nonstatic function in a range (b).

   IntX  : FA21A00.My_Int range 10 .. FA21A00.Func;                   -- ERROR:
                             -- Call to nonstatic function in a constraint (b).

   Call1 : FA21A00.My_Int := FA21A00.Func;                            -- ERROR:
                                             -- Call to nonstatic function (b).

   Call2 : Int_Type := Init;                                          -- ERROR:
                                                -- Call to formal function (c).

   Bool  : Boolean := (FA21A00.Ten = 10);                             -- ERROR:
                                       -- Primary that is a name of an object
                                       -- which is not a static expression (d).

   Rec   : FA21A00.RecPrimDefault;                                    -- ERROR:
                                        -- Primary that is a name of an object
                                        -- which is not a static expression (in
                                        -- component's default expression) (d).

   TObj  : FA21A00.Tsk(5);                                            -- ERROR:
                                                  -- Object of a task type (e).

   Cont  : FA21A00.ContComp;                                          -- ERROR:
                     -- Default-initialized component of a controlled type (e).

   Arr   : Array_Type;                                                -- ERROR:
                        -- Default-initialized component of a private type (e).

   PExt  : FA21A00.Pri_Ext;                                           -- ERROR:
                      -- Default-initialized object of a private extension (e).

   PAgg  : DerPriv := (FA21A00.Priv with "mistake");                  -- ERROR:
                -- Extension aggregate with ancestor denoting private type (f).

   PType : Form_Priv;                                                 -- ERROR:
                    -- Default-initialized object of a formal private type (e).

   FPExt : Form_PriExt;                                               -- ERROR:
               -- Default-initialized object of a formal private extension (e).

begin
   Dummy;                                                             -- ERROR:
                                                     -- Non-null statement (a).
end BA21A02;
