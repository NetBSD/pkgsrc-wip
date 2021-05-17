

     --==================================================================--


with BC51013_0;
with BC51013_1;
with BC51013_2;
generic
   type Formal_Type is abstract tagged private;                       -- OK.
   with package Formal_Package is new BC51013_2 (<>);

   Gen_Obj1 : in out Formal_Type;                                     -- OK.

   Gen_Obj2 : Formal_Type;                                            -- ERROR:
                       -- Type of generic formal object of mode in is abstract.

package BC51013 is

   type Abstract_Type is abstract tagged record       -- Abstract type.
      Field : String (1 .. 5);
   end record;

   type Abstract_Access is access Formal_Type;

   Object1 : Formal_Type;                                             -- ERROR:
                                                 -- Type of object is abstract.
   Object2 : aliased Formal_Type;                                     -- ERROR:
                                                 -- Type of object is abstract.

   Abs_Ptr : Abstract_Access := new Formal_Type;                      -- ERROR:
                                       -- Type of allocated object is abstract.

   type Rec is record
      Component : Formal_Type;                                        -- ERROR:
   end record;                                -- Type of component is abstract.

   type Arr is array (1 .. 5) of Formal_Type;                         -- ERROR:
                                              -- Type of component is abstract.

   Abs_Arr : array (1 .. 5) of Formal_Type;                           -- ERROR:
                                              -- Type of component is abstract.
                                   

   function Non_Abstract_Function return Formal_Type;                 -- ERROR:
                       -- Function is not abstract but result type is abstract.

   function Abstract_Function return Formal_Type is abstract;         -- OK.


   package Tagged_Private_Actual_Is_Type is new
     BC51013_0 (Abstract_Type);                                       -- ERROR:
                                                    -- Actual type is abstract.

   package Private_Actual_Is_Type is new
     BC51013_1 (Abstract_Type);                                       -- ERROR:
                                                    -- Actual type is abstract.

   package Tagged_Private_Actual_Is_Formal is new 
     BC51013_0 (Formal_Type);                                         -- ERROR:
                                                    -- Actual type is abstract.

   package Private_Actual_Is_Formal is new
     BC51013_1 (Formal_Type);                                         -- ERROR:
                                                    -- Actual type is abstract.

   package Tagged_Private_Actual_Is_Formal_Package_Formal is new
     BC51013_0 (Formal_Package.A_Formal_Type);                        -- ERROR:
                                                    -- Actual type is abstract.

   package Private_Actual_Is_Formal_Package_Formal is new
     BC51013_1 (Formal_Package.A_Formal_Type);                        -- ERROR:
                                                    -- Actual type is abstract.
end BC51013;
