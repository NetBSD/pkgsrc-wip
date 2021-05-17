

     --===================================================================--


with BC51020_0;
use  BC51020_0;
package BC51020 is


--
-- Formal derived type is not abstract:
--

   generic

      type Formal_Derived is new Ancestor with private;
      -- procedure Set_Comp (P : in out Formal_Derived);

   package Nonabstract_Formal_Derived is

      type Record_Extension is new Formal_Derived with
        null record;                                          -- OK.    {1:7;1}
      -- procedure Set_Comp (P : in out Record_Extension);



      type Abstract_Record_Ext is abstract new Formal_Derived with
        null record;                                          -- OK.    {1:7;1}
      -- procedure Set_Comp (P : in out Abstract_Record_Ext);



      type Private_Extension is new Formal_Derived with private;
      -- procedure Set_Comp (P : in out Private_Extension);



      type Abstract_Private_Ext is abstract new Formal_Derived
        with private;                                         -- OK.    {1:7;1}
      -- procedure Set_Comp (P : in out Abstract_Private_Ext);

   private

      type Private_Extension is new Formal_Derived with
        null record;                                          -- OK.    {1:7;1}
      -- procedure Set_Comp (P : in out Private_Extension);



      type Abstract_Private_Ext is abstract new Formal_Derived
        with null record;                                     -- OK.    {1:7;1}
      -- procedure Set_Comp (P : in out Abstract_Private_Ext);

   end Nonabstract_Formal_Derived;



--
-- Formal derived type is abstract:
--

   generic

      type Formal_Derived is abstract new Ancestor with private;
      -- procedure Set_Comp (P : in out Formal_Derived) is abstract;

   package Abstract_Formal_Derived is

      type Record_Extension is new Formal_Derived with
        null record;                                          -- ERROR: {1:7;1}
                         -- Must be abstract; inherited subprogram is abstract.
      -- procedure Set_Comp (P : in out Record_Extension) is abstract;



      type Record_Ext_Overrides is new Formal_Derived with
        null record;                                          -- OK.    {1:7;1}

      procedure Set_Comp (P : in out Record_Ext_Overrides);     -- Overrides
                                                                -- inherited
                                                                -- procedure.



      type Abstract_Record_Ext is abstract new Formal_Derived with
        null record;                                          -- OK.    {1:7;1}
      -- procedure Set_Comp (P : in out Abstract_Record_Ext) is abstract;



      type Private_Extension is new Formal_Derived
        with private;                         -- POSSIBLE ERROR: [Set1] {1:7;1}

      -- procedure Set_Comp (P : in out Private_Extension);



      type Private_Ext_Overrides is new Formal_Derived
        with private;                                         -- OK.    {1:7;1}
      -- procedure Set_Comp (P : in out Private_Ext_Overrides);



      type Abstract_Private_Ext is abstract new Formal_Derived
        with private;                                         -- OK.    {1:7;1}
      -- procedure Set_Comp (P : in out Abstract_Private_Ext) is abstract;

   private

      type Private_Extension is new Formal_Derived with
        null record;                          -- POSSIBLE ERROR: [Set1] {1:7;1}
                         -- Must be abstract; inherited subprogram is abstract.
      -- procedure Set_Comp (P : in out Private_Extension) is abstract;



      type Private_Ext_Overrides is new Formal_Derived with
        null record;                                          -- OK.    {1:7;1}

      procedure Set_Comp (P : in out Private_Ext_Overrides);    -- Overrides
                                                                -- inherited
                                                                -- procedure.


      type Abstract_Private_Ext is abstract new Formal_Derived
        with null record;                                     -- OK.    {1:7;1}
      -- procedure Set_Comp (P : in out Abstract_Private_Ext) is abstract;

   end Abstract_Formal_Derived;


end BC51020;
