

     --===================================================================--


with BC51019_0;
use  BC51019_0;
package BC51019 is


--
-- Formal derived type is not abstract:
--

   generic

      type Formal_Derived is new Ancestor with private;
      -- function True_Field return Formal_Derived;

   package Nonabstract_Formal_Derived is

      type Record_Extension is new Formal_Derived with
        record
          B : Boolean;
        end record;                                           -- ERROR: {3:7;1}
                   -- Type has primitive subprograms that require overriding.
      -- function True_Field return Record_Extension requires overriding.



      type Record_Ext_Overrides is new Formal_Derived with
        record
          B : Boolean;
        end record;                                           -- OK.    {3:7;1}

      function True_Field return Record_Ext_Overrides;  -- Overrides inherited
                                                        -- function.



      type Abstract_Record_Ext is abstract new Formal_Derived with
        record
          B : Boolean;
        end record;                                           -- OK.    {3:7;1}
      -- function True_Field return Abstract_Record_Ext is abstract;



      type Private_Extension is new Formal_Derived with private;
      -- function True_Field return Private_Extension;



      type Private_Ext_Overrides is new Formal_Derived
        with private;                                         -- OK.    {1:7;1}
      -- function True_Field return Private_Ext_Overrides;



      type Abstract_Private_Ext is abstract new Formal_Derived
        with private;                                         -- OK.    {1:7;1}
      -- function True_Field return Abstract_Private_Ext is abstract;

   private

      type Private_Extension is new Formal_Derived with
        record
          B : Boolean;
        end record;                                           -- ERROR: {3:7;1}
                   -- Type has primitive subprograms that require overriding.
      -- function True_Field return Private_Extension requires overriding.



      type Private_Ext_Overrides is new Formal_Derived with
        record
          B : Boolean;
        end record;                                           -- OK.    {3:7;1}

      function True_Field return Private_Ext_Overrides; -- Overrides inherited
                                                        -- function.



      type Abstract_Private_Ext is abstract new Formal_Derived with
        record
          B : Boolean;
        end record;                                           -- OK.    {3:7;1}
      -- function True_Field return Abstract_Private_Ext is abstract;

   end Nonabstract_Formal_Derived;



--
-- Formal derived type is abstract:
--

   generic

      type Formal_Derived is abstract new Ancestor with private;
      -- function True_Field return Formal_Derived is abstract;

   package Abstract_Formal_Derived is

      type Record_Extension is new Formal_Derived with
        record
          B : Boolean;
        end record;                                           -- ERROR: {3:7;1}
                   -- Type has primitive subprograms that require overriding.
      -- function True_Field return Record_Extension requires overriding.



      type Record_Ext_Overrides is new Formal_Derived with
        record
          B : Boolean;
        end record;                                           -- OK.    {3:7;1}

      function True_Field return Record_Ext_Overrides;  -- Overrides inherited
                                                        -- function.



      type Abstract_Record_Ext is abstract new Formal_Derived with
        record
          B : Boolean;
        end record;                                           -- OK.    {3:7;1}
      -- function True_Field return Abstract_Record_Ext is abstract;



      type Private_Extension is new Formal_Derived with private;
      -- function True_Field return Private_Extension;



      type Private_Ext_Overrides is new Formal_Derived
        with private;                                         -- OK.    {1:7;1}
      -- function True_Field return Private_Ext_Overrides;



      type Abstract_Private_Ext is abstract new Formal_Derived
        with private;                                         -- OK.    {1:7;1}
      -- function True_Field return Abstract_Private_Ext is abstract;

   private

      type Private_Extension is new Formal_Derived with
        record
          B : Boolean;
        end record;                                           -- ERROR: {3:7;1}
                   -- Type has primitive subprograms that require overriding.
      -- function True_Field return Private_Extension requires overriding.



      type Private_Ext_Overrides is new Formal_Derived with
        record
          B : Boolean;
        end record;                                           -- OK.    {3:7;1}

      function True_Field return Private_Ext_Overrides; -- Overrides inherited
                                                        -- function.



      type Abstract_Private_Ext is abstract new Formal_Derived with
        record
          B : Boolean;
        end record;                                           -- OK.    {3:7;1}
      -- function True_Field return Abstract_Private_Ext is abstract;

   end Abstract_Formal_Derived;


end BC51019;
