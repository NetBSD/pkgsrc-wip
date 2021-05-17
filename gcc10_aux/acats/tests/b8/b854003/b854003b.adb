
package body B854003B is

   -- Objective A tests:

   procedure ReConf_1 (Val : in out Integer)
                    renames B854003A.Munge_1;                 -- ERROR: {1:4;1}

   procedure ReConf_2 (Val : in out Integer)
                    renames B854003A.Munge_1;                 -- ERROR: {1:4;1}

   procedure ReConf_3 (Val : in out Integer)
                    renames B854003A.Munge_1;                 -- ERROR: {1:4;1}

   procedure ReConf_4 (Val : in out Integer)
                    renames B854003A.Munge_1;                 -- OK. {1:4;1}

   function ReConf_F1 (Val : in Integer) return Integer
                    renames B854003A.Double_1;                -- OK. {1:4;1}

   function ReConf_F2 (Val : in Integer) return Integer
                    renames B854003A.Double_1;                -- ERROR: {1:4;1}

   function ReConf_F3 (Val : in Integer) return Integer
                    renames B854003A.Double_1;                -- ERROR: {1:4;1}

   function ReConf_F4 (Val : in Integer) return Integer
                    renames B854003A.Double_1;                -- ERROR: {1:4;1}

   -- Objective B tests:

   procedure ReMunge_1 (Val : in out Natural)
                    renames B854003A.Munge_1;                 -- ERROR: {1:4;1}

   procedure ReMunge_2 (Val : in out Natural)
                    renames B854003A.Munge_2;                 -- OK. {1:4;1}

   procedure ReMunge_3 (Val : in out Natural)
                    renames B854003A.Munge_3;                 -- ERROR: {1:4;1}

   procedure ReMunge_4 (Val : in out Natural)
                    renames B854003A.Munge_4;                 -- ERROR: {1:4;1}

   procedure ReMunge_5 (Val : in out Positive)
                    renames B854003A.Munge_5;                 -- ERROR: {1:4;1}

   procedure ReMunge_6 (Val : in out Positive)
                    renames B854003A.Munge_6;                 -- ERROR: {1:4;1}

   procedure ReMunge_11 (Val : in out Dyn_Positive)
                    renames B854003A.Munge_3;                 -- ERROR: {1:4;1}

   procedure ReMunge_12 (Val : in out B854003A.Dyn_Positive)
                    renames B854003A.Munge_3;                 -- OK. {1:4;1}

   package body Gen1 is
      procedure ReMunge_G (Val : in out Natural)
                    renames Munge_G;                          -- ERROR: {1:7;1}
      -- Note: See the second sentence of 6.3.1(17/3)!
   end Gen1;

   function ReDouble_1 (Val : in Integer) return Integer
                    renames B854003A.Double_1;                -- OK. {1:4;1}

   function ReDouble_2 (Val : in Integer) return Integer
                    renames B854003A.Double_2;                -- ERROR: {1:4;1}

   function ReDouble_3 (Val : in Integer) return Integer
                    renames B854003A.Double_3;                -- ERROR: {1:4;1}

   function ReDouble_11 (Val : in Integer) return Dyn_Positive
                    renames B854003A.Double_3;                -- ERROR: {1:4;1}

   function ReDouble_12 (Val : in Integer) return B854003A.Dyn_Positive
                    renames B854003A.Double_3;                -- OK. {1:4;1}

   -- Objective C tests:

   function Ren_1 (Left, Right : Integer'Base) return Integer'Base
                    renames Standard."+";                     -- ERROR: {1:4;1}

   function Ren_2 (Left, Right : Integer'Base) return Boolean
                    renames Standard."/=";                    -- ERROR: {1:4;1}

   -- Objective D tests:

   procedure ReProc (Obj : in out B854003A.T)
                    renames B854003A.Proc;                    -- ERROR: {1:4;1}

   function ReFunc (Obj : in B854003A.T) return Boolean
                    renames B854003A.Func;                    -- ERROR: {1:4;1}

   function ReCount (Obj : in B854003A.T) return Natural
                    renames B854003A.Count;                   -- OK. {1:4;1}

   procedure ReSink (Obj : in B854003A.T)
                    renames B854003A.Sink;                    -- OK. {1:4;1}

end B854003B;
