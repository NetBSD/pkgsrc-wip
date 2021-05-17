
with B854003A;
package B854003B is

   procedure ReConf_1 (Val : in Integer);

   procedure ReConf_2 (Val : in out Positive);

   procedure ReConf_3 (Pos : in out Integer);

   procedure ReConf_4 (Val : in out Integer);

   function ReConf_F1 (Val : in Integer) return Integer;

   function ReConf_F2 (Val : in Integer) return Positive;

   function ReConf_F3 (Val : in Integer := 1) return Integer;

   function ReConf_F4 (Pos : in Integer) return Integer;


   procedure ReMunge_1 (Val : in out Natural);

   procedure ReMunge_2 (Val : in out Natural);

   procedure ReMunge_3 (Val : in out Natural);

   procedure ReMunge_4 (Val : in out Natural);

   procedure ReMunge_5 (Val : in out Positive);

   procedure ReMunge_6 (Val : in out Positive);

   subtype Dyn_Positive is Integer range B854003A.One .. Integer'Last;

   procedure ReMunge_11 (Val : in out Dyn_Positive);

   procedure ReMunge_12 (Val : in out B854003A.Dyn_Positive);

   generic
      with procedure Munge_G (Val : in out Natural);
   package Gen1 is
      procedure ReMunge_G (Val : in out Natural);
   end Gen1;

   function ReDouble_1 (Val : in Integer) return Integer;

   function ReDouble_2 (Val : in Integer) return Integer;

   function ReDouble_3 (Val : in Integer) return Integer;

   function ReDouble_11 (Val : in Integer) return Dyn_Positive;

   function ReDouble_12 (Val : in Integer) return B854003A.Dyn_Positive;


   function Ren_1 (Left, Right : Integer'Base) return Integer'Base;

   function Ren_2 (Left, Right : Integer'Base) return Boolean;


   procedure ReProc (Obj : in out B854003A.T);

   function ReFunc (Obj : in B854003A.T) return Boolean;

   function ReCount (Obj : in B854003A.T) return Natural;

   procedure ReSink (Obj : in B854003A.T);

end B854003B;
