
with B393009_0; use B393009_0;
procedure B393009 is

   type Interface_Ptr is access Syn_Interface;

   Object1 : Lim_Interface;                                           -- ERROR:
                                                 -- Type of object is abstract.
   Object2 : aliased Syn_Interface;                                   -- ERROR:
                                                 -- Type of object is abstract.
   Abs_Ptr : Interface_Ptr := new Syn_Interface;                      -- ERROR:
                                       -- Type of allocated object is abstract.

   type Rec1 is record
      Component : Lim_Interface;                                      -- ERROR:
   end record;                                -- Type of component is abstract.

   type Rec2 is record
      Component : Interface_Ptr := new Syn_Interface;                 -- ERROR:
   end record;                        -- Trying to allocate an abstract object.

   type Rec3 is abstract tagged limited record
      Component : Task_Interface;                                     -- ERROR:
   end record;                                -- Type of component is abstract.

   type Arr1 is array (1 .. 5) of Prot_Interface;                     -- ERROR:
                                              -- Type of component is abstract.

   type Arr2 is array (1 .. 5) of Interface_Ptr;                      -- OK.

   Object3 : Arr2 := (others => new Syn_Interface);                   -- ERROR:
                                      -- Trying to allocate an abstract object.

   function Non_Abstract_Func1 return Task_Interface;                 -- ERROR:
                       -- Function is not abstract but result type is abstract.

   function Non_Abstract_Func2 (Left, Right : Integer)
     return Prot_Interface;                                           -- ERROR:
                       -- Function is not abstract but result type is abstract.

   function Non_Abstract_Func3 (Count : Integer)
     return Non_Lim_Interface'Class;                                  -- OK.

   function Non_Abstract_Func3 (Count : Integer)
     return Non_Lim_Interface'Class is
     Object4 : Concrete;
   begin
     return Object4;
   end Non_Abstract_Func3;

   function Abstract_Func1 return Lim_Interface is abstract;          -- OK.

   Object5 : Concrete;
   Object6 : Concrete;

   procedure Assign (Target : in out Non_Lim_Interface'Class;
                     Source : in     Non_Lim_Interface'Class) is
   begin
       Non_Lim_Interface(Target) := Non_Lim_Interface(Source);        -- ERROR:
                      -- Target of an assignment operation may not be abstract.
   end Assign;

begin
   Assign (Object5, Object6);                                         -- OK.
   Assign (Object6, Non_Lim_Interface'(others => <>));                -- ERROR:
                      -- Aggregate may not have an abstract type.
   Assign (Object5, Non_Lim_Interface'(null record));                 -- ERROR:
                      -- Aggregate may not have an abstract type.
end B393009;
