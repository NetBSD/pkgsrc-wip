

     --===================================================================--


package BC51C02_1 is

-- Check that a type derived from an abstract formal private type may be
-- either abstract or non-abstract.


-- Within each generic below, a non-abstract type is derived from the
-- formal type.
--
-- When each generic is instantiated with an abstract actual type, each of
-- the abstract primitive subprograms of the actual type must be overridden
-- for the derived type, or else the instantiation must be rejected.
-- Similarly, all functions with controlled results must be overridden
-- for the derived type.
--
-- Each of the generics below will be instantiated with the abstract type
-- FC51C00.Abstract_Child. Each generic overrides some set of the abstract
-- primitive subprograms of this actual type:
--
--     (1) *_No_Overrides does not override any of the primitive subprograms
--         of the actual.
--     (2) *_Overrides_Explicit only overrides the procedures which are
--         explicitly declared as abstract for the actual type; it does
--         not override the function with a controlling result.
--     (3) *_Overrides_All overrides all the abstract procedures inherited
--         as abstract from the actual, as well as the non-abstract function
--         which requires overriding when it is inherited from the actual.
--
-- For this test, the only generics for which an instantiation with the
-- abstract type FC51C00.Abstract_Child is legal are those in category (3).


--
-- Type derived from formal type is a record extension:
--

   generic
      type Formal_Private is abstract tagged private;
   package RecExt_No_Overrides is

      type Concrete_Derived is new Formal_Private with
        record
          B : Boolean;
        end record;

   end RecExt_No_Overrides;


   generic
      type Formal_Private is abstract tagged private;
   package RecExt_Overrides_Explicit is

      type Concrete_Derived is new Formal_Private with
        record
          B : Boolean;
        end record;

      procedure Proc (P: in out Concrete_Derived);
      procedure New_Proc (P: out Concrete_Derived);

   end RecExt_Overrides_Explicit;


   generic
      type Formal_Private is abstract tagged private;
   package RecExt_Overrides_All is

      type Concrete_Derived is new Formal_Private with
        record
          B : Boolean;
        end record;

      procedure Proc (P: in out Concrete_Derived);
      procedure New_Proc (P: out Concrete_Derived);

      function Func (P: Concrete_Derived) return Concrete_Derived;

   end RecExt_Overrides_All;


--
-- Type derived from formal type is a private extension:
--

   generic
      type Formal_Private is abstract tagged private;
   package PriExt_No_Overrides is

      type Concrete_Derived is new Formal_Private with private;

   private

      type Concrete_Derived is new Formal_Private with
        record
          B : Boolean;
        end record;

   end PriExt_No_Overrides;


   generic
      type Formal_Private is abstract tagged private;
   package PriExt_Overrides_Explicit is

      type Concrete_Derived is new Formal_Private with private;

      procedure Proc (P: in out Concrete_Derived);
      procedure New_Proc (P: out Concrete_Derived);

   private

      type Concrete_Derived is new Formal_Private with
        record
          B : Boolean;
        end record;

   end PriExt_Overrides_Explicit;


   generic
      type Formal_Private is abstract tagged private;
   package PriExt_Overrides_All is

      type Concrete_Derived is new Formal_Private with private;

      procedure Proc (P: in out Concrete_Derived);
      procedure New_Proc (P: out Concrete_Derived);

      function Func (P: Concrete_Derived) return Concrete_Derived;

   private

      type Concrete_Derived is new Formal_Private with
        record
          B : Boolean;
        end record;

   end PriExt_Overrides_All;


end BC51C02_1;
