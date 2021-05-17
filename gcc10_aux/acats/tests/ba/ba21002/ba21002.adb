

     --===================================================================--


package body BA21002 is

   Pri   : constant Priv := (0, True);                                -- OK.
                                 -- Declaration of a constant private object
                                 -- (within scope of full view) (o).

   type Rec (D: access BA21002_0.Tag) is limited record               -- OK.
                                               -- Anonymous access type (n).
      C : BA21002_0.My_Int;
   end record;


   procedure Proc is
      type NAcc is access BA21002_0.Tag;                              -- OK.
                               -- Named access type (within subprogram) (m).

      Obj1 : BA21002_0.My_Int := 10;                                  -- OK.
                            -- Variable declaration (within subprogram) (l).

      Obj2 : BA21002_0.Tag;                                           -- OK.
                            -- Variable declaration (within subprogram) (l).
   begin
      null;
   end Proc;


   Tag1  : constant BA21002_0.Tag := (0, 10);                         -- OK.
                                       -- Declaration of a constant (j) (k).

   Disc1 : constant BA21002_0.RecWithDisc(2) :=
     (2, (others => BA21002_0.Three));                                -- OK.
                                    -- Primary that is a name of an object
                                    -- but which is a static expression (i).

   Nine  : constant BA21002_0.My_Int := BA21002_0.Three**2;           -- OK.
                       -- Call to static function (predefined operator) (h).


   RExt  : constant BA21002_0.Tag'Class :=
     Tag_Ext'(BA21002_0.Tag with null record);                        -- ERROR:
                                        -- Call to nonstatic function (in
                                        -- component's default expression) (g).

   PExt  : constant Rec_Ext :=
     (BA21002_0.Pri_Ext with null record);                            -- ERROR:
           -- Extension aggregate with ancestor denoting private extension (f).

   type Named_Access_Type is access BA21002_0.Tag;                    -- ERROR:
                                                      -- Named access type (e).

   Obj1  : BA21002_0.My_Int;                                          -- ERROR:
                                                   -- Variable declaration (d).

   Obj2  : BA21002_0.My_Int := 10;                                    -- ERROR:
                                                   -- Variable declaration (d).

   protected Prot is                                                  -- ERROR:
                   -- (Anonymous) protected object with entry declarations (c).
      entry E;
   end Prot;

   protected body Prot is                                    -- OPTIONAL ERROR:
              -- No corresponding protected definition (due to previous error).
      entry E when False is
      begin
         null;
      end E;
   end Prot;


   Disc2 : constant BA21002_0.RecWithDisc(2) :=
     (2, BA21002_0.Arr);                                              -- ERROR:
                                       -- Primary that is a name of an object
                                       -- which is not a static expression (b).

begin
   Proc;                                                             -- ERROR:
                                                     -- Non-null statement (a).
end BA21002;
