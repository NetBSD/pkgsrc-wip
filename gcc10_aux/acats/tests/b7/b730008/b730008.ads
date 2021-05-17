
with B730008A;
package B730008 is

   type Priv01 is abstract new B730008A.Iface with private;

   type Priv02 is abstract new B730008A.Iface with private;

   type Priv03 is abstract new B730008A.Iface with private;

   type Priv04 is abstract new B730008A.Iface with private;

   type Priv05 is abstract new B730008A.Iface with private;

   type Priv10 is new B730008A.Parent_1 with private;

   type Priv11 is new B730008A.Parent_1 with private;

   type Priv20 is new B730008A.Parent_1 and B730008A.Iface with private;

   type Priv21 is new B730008A.Parent_1 and B730008A.Iface with private;

   type Priv22 is new B730008A.Parent_1 and B730008A.Iface with private;

   type Priv23 is new B730008A.Parent_1 and B730008A.Iface with private;

   type Priv24 is new B730008A.Parent_1 and B730008A.Iface with private;

   type Priv30 is new B730008A.L_Iface and B730008A.Iface with private;

   type Priv31 is new B730008A.L_Iface and B730008A.Iface with private;

   type Priv40 is tagged private;

   type Priv41 is tagged private;

   type Priv42 is tagged private;

   type Priv43 is abstract tagged private;

   type Priv50 is private;

   type Priv51 is private;

   type Priv52 is private;

   type Priv60 is synchronized new B730008A.S_Iface with private;

   type Priv61 is synchronized new B730008A.S_Iface with private;

   type Priv62 is synchronized new B730008A.S_Iface with private;

   type Priv63 is synchronized new B730008A.S_Iface with private;

   type Priv64 is synchronized new B730008A.S_Iface with private;

   type Priv65 is synchronized new B730008A.S_Iface with private;

   type Priv66 is synchronized new B730008A.S_Iface with private;

   type Priv67 is synchronized new B730008A.S_Iface with private;

   type Priv70 is synchronized new B730008A.S_Iface and
                  B730008A.L_Iface with private;

   type Priv71 is synchronized new B730008A.S_Iface and
                  B730008A.L_Iface with private;

   type Priv80 is abstract synchronized new B730008A.S_Iface with private;

private
   type Priv01 is abstract new B730008A.Iface
                     with null record;                       -- OK.

   -- Different interface:
   type Priv02 is abstract new B730008A.L_Iface
                     with null record;                       -- ERROR:

   -- Partial view isn't descended from the interface defined by Priv03
   -- (see AARM 7.3(7.cc/2)):
   type Priv03 is interface and B730008A.Iface;              -- ERROR:

   type Priv04 is new B730008A.Parent_2 with null record;    -- OK.

   -- Partial view doesn't have L_IFace:
   type Priv05 is new B730008A.Parent_3 with null record;    -- ERROR:

   -- Partial view doesn't have IFace:
   type Priv10 is new B730008A.Parent_1 and
                      B730008A.Iface with null record;       -- ERROR:
   procedure Foo (X : Priv10) is null;

   -- Partial view doesn't have IFace:
   type Priv11 is new B730008A.Parent_2 with null record;    -- ERROR:


   type Priv20 is new B730008A.Parent_2 with null record;    -- OK.

   type Priv21 is new B730008A.Parent_1 and
                      B730008A.Iface with null record;       -- OK.
   procedure Foo (X : Priv21) is null;

   -- Different interface:
   type Priv22 is new B730008A.Parent_1 and
                      B730008A.L_Iface with null record;     -- ERROR:

   -- Different interface:
   type Priv23 is new B730008A.Parent_3 with null record;    -- ERROR:

   -- Missing interface:
   type Priv24 is new B730008A.Parent_1 with null record;    -- ERROR:

   type Priv30 is new B730008A.Parent_2 and
                      B730008A.L_Iface with null record;     -- OK.

   -- Missing interface:
   type Priv31 is new B730008A.Parent_1 and
                      B730008A.L_Iface with null record;     -- ERROR:

   -- Partial view doesn't have IFace:
   type Priv40 is new B730008A.Iface with null record;       -- ERROR:
   procedure Foo (X : Priv40) is null;

   -- Partial view doesn't have IFace:
   type Priv41 is new B730008A.Parent_2 with null record;    -- ERROR:

   type Priv42 is new B730008A.Parent_1 with null record;    -- OK.

   -- Partial view isn't descended from the interface defined by Priv42:
   type Priv43 is interface;                                 -- ERROR:

   -- Partial view is not tagged:
   type Priv50 is new B730008A.Iface with null record;       -- OK.
   procedure Foo (X : Priv50) is null;

   -- Partial view is not tagged:
   type Priv51 is new B730008A.Parent_2 with null record;    -- OK.

   -- Partial view is not tagged:
   type Priv52 is new B730008A.Parent_1 with null record;    -- OK.

   -- Missing interface:
   protected type Priv60 is                                  -- ERROR:
   private
      Foo : Natural;
   end Priv60;

   -- Wrong interface:
   protected type Priv61 is new B730008A.L_Iface with        -- ERROR:
   private
      Foo : Natural;
   end Priv61;

   protected type Priv62 is new B730008A.S_Iface with        -- OK.
   private
      Foo : Natural;
   end Priv62;

   -- Partial view doesn't have L_IFace:
   protected type Priv63 is new B730008A.S_Iface and
                                B730008A.L_Iface with        -- ERROR:
   private
      Foo : Natural;
   end Priv63;

   -- Missing interface:
   task type Priv64 is                                       -- ERROR:
   end Priv64;

   -- Wrong interface:
   task type Priv65 is new B730008A.L_Iface with             -- ERROR:
   end Priv65;

   task type Priv66 is new B730008A.S_Iface with             -- OK.
   end Priv66;

   -- Partial view doesn't have L_IFace:
   task type Priv67 is new B730008A.L_Iface and
                           B730008A.S_Iface with             -- ERROR:
   end Priv67;

   -- Missing interface:
   protected type Priv70 is new B730008A.S_Iface with        -- ERROR:
   private
      Foo : Natural;
   end Priv70;

   -- Missing interface:
   task type Priv71 is new B730008A.L_Iface with             -- ERROR:
   end Priv71;

   -- Partial view isn't descended from the interface defined by Priv42:
   type Priv80 is synchronized interface and
                           B730008A.S_Iface;                 -- ERROR:

end B730008;
