

     --==================================================================--


with BC51012_0;
with BC51012_1;
with BC51012_2;
generic
   type Formal_Type is abstract new BC51012_0.Ancestor with private;  -- OK.
   with package Formal_Package is new BC51012_2 (<>);

   Gen_Obj1 : in out Formal_Type;                                     -- OK.

   Gen_Obj2 : Formal_Type;                                            -- ERROR:
                       -- Type of generic formal object of mode in is abstract.

package BC51012 is

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
                                -- Result type is abstract but function is not.

   function Abstract_Function return Formal_Type is abstract;         -- OK.


   package Derived_Actual_Is_Type_1 is new
     BC51012_1 (BC51012_0.Ancestor);                                  -- ERROR:
                                                    -- Actual type is abstract.

   package Derived_Actual_Is_Type_2 is new
     BC51012_1 (BC51012_0.Abstract_Child);                            -- ERROR:
                                                    -- Actual type is abstract.

   package Derived_Actual_Is_Type_3 is new
     BC51012_1 (BC51012_0.Concrete_Child);                            -- OK.


   package Derived_Actual_Is_Formal is new
     BC51012_1 (Formal_Type);                                         -- ERROR:
                                                    -- Actual type is abstract.

   package Derived_Actual_Is_Formal_Package_Formal is new
     BC51012_1 (Formal_Package.A_Formal_Type);                        -- ERROR:
                                                    -- Actual type is abstract.

end BC51012;
