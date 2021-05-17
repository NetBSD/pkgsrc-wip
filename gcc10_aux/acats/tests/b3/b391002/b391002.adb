

     --===================================================================--


with B391002_2;
package body B391002 is

   procedure Dummy_Proc is             -- Needed to allow body
   begin                               -- for B391002.
      null;
   end Dummy_Proc;


   type Parent_In_Body    is tagged null record;
   type Extension_In_Body is new Parent_In_Body with null record;


   package Instance01 is new B391002_2 (Parent_In_Body);              -- OK.

   package Instance02 is new B391002_2 (B391002_0.Root);              -- OK.


   package Inner is
      type Inner_Parent  is tagged null record;
      type Inner_Pri_Ext is new Inner_Parent with private;
      type Inner_Rec_Ext is new Inner_Parent with null record;
   private
      type Inner_Pri_Ext is new Inner_Parent with null record;
   end Inner;

   type Derived01 is new Inner.Inner_Parent with null record;         -- OK.
   type Derived02 is new Inner.Inner_Pri_Ext with null record;        -- OK.
   type Derived03 is new Inner.Inner_Rec_Ext with null record;        -- OK.


   type Derived04 is new Parent_In_Body with null record;             -- OK.
   type Derived05 is new Extension_In_Body with null record;          -- OK.


   type Derived06 is new B391002_0.Root with null record;             -- OK.

   type Derived07 is new B391002_0.Pri_Der with null record;          -- OK.

   type Derived08 is new B391002_0.Vis_Der with null record;          -- OK.

   type Derived09 is new Local_Parent with null record;               -- OK.

   type Derived10 is new Local_Pri_Ext with null record;              -- ERROR:
                            -- Parent type is a descendant of a formal type.

   type Derived11 is new Local_Rec_Ext with null record;              -- ERROR:
                            -- Parent type is a descendant of a formal type.

   type Derived12 is new Formal_Private with null record;             -- ERROR:
                            -- Parent type is a descendant of a formal type.

   type Derived13 is new Formal_Derived with null record;             -- ERROR:
                            -- Parent type is a descendant of a formal type.

   type Derived14 is new Formal_Package.Parent with null record;      -- OK.

   type Derived15 is new Formal_Package.Pri_Ext with null record;     -- ERROR:
                            -- Parent type is a descendant of a formal type.

   type Derived16 is new Formal_Package.Rec_Ext with null record;     -- ERROR:
                            -- Parent type is a descendant of a formal type.

   type Derived17 is new Formal_Package.Form_Pri with null record;    -- ERROR:
                            -- Parent type is a descendant of a formal type.

   type Derived18 is new Formal_Package.Form_Der with null record;    -- ERROR:
                            -- Parent type is a descendant of a formal type.

end B391002;
