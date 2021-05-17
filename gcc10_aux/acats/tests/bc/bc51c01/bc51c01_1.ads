

     --===================================================================--


with FC51C00;
package BC51C01_1 is

-- Check that a type derived from an abstract formal derived type may be
-- either abstract or non-abstract.


-- Within each generic below, a non-abstract type is derived from the
-- formal type. Each abstract primitive subprogram inherited by the derived
-- type from the *ancestor* type is overridden. Thus, each generic is legal.
--
-- However, when each generic is instantiated with an abstract descendant of
-- the ancestor, each of the abstract primitive subprograms of the
-- *actual type* must be overridden for the derived type, or else the
-- instantiation must be rejected.
--
-- Each of the generics below will be instantiated with the abstract type
-- FC51C00.Abstract_Child. Each generic overrides some set of the abstract
-- primitive subprograms of this actual type:
--
--     (1) *_Overrides_Inherited only overrides the non-abstract function
--         of the ancestor which becomes abstract when inherited.
--     (2) *_Overrides_All overrides all the abstract subprograms inherited
--         as abstract from the ancestor as well as the abstract subprograms
--         that are unique to the actual type (i.e., not abstract subprograms
--         of the ancestor).
--
-- For this test, the only generics for which an instantiation with the
-- abstract type FC51C00.Abstract_Child is legal are those in category (2).


--
-- Type derived from formal type is a record extension:
--

   generic
      type Formal_Derived is abstract new FC51C00.Concrete_Root with private;
   package RecExt_Overrides_Inherited is

      type Concrete_Derived is new Formal_Derived with null record;

   -- Inherited Func is abstract and must be overridden:
      function Func (P: Concrete_Derived) return Concrete_Derived;

   end RecExt_Overrides_Inherited;


   generic
      type Formal_Derived is abstract new FC51C00.Concrete_Root with private;
   package RecExt_Overrides_All is

      type Concrete_Derived is new Formal_Derived with null record;

   -- Inherited Func is abstract and must be overridden:
      function Func (P: Concrete_Derived) return Concrete_Derived;

      procedure Proc (P: in out Concrete_Derived);

      procedure New_Proc (P: out Concrete_Derived);

   end RecExt_Overrides_All;


--
-- Type derived from formal type is a private extension:
--

   generic
      type Formal_Derived is abstract new FC51C00.Concrete_Root with private;
   package PriExt_Overrides_Inherited is

      type Concrete_Derived is new Formal_Derived with private;

   private

      type Concrete_Derived is new Formal_Derived with null record;

   -- Inherited Func is abstract and must be overridden:
      function Func (P: Concrete_Derived) return Concrete_Derived;

   -- Proc and New_Proc below are declared in the private part. Hence, in an
   -- instance, they will not override a corresponding implicit Proc and
   -- New_Proc inherited by Concrete_Derived from the actual, because they do
   -- do not override a corresponding Proc and New_Proc in the generic:
      procedure Proc (P: in out Concrete_Derived);

      procedure New_Proc (P: out Concrete_Derived);

   end PriExt_Overrides_Inherited;


   generic
      type Formal_Derived is abstract new FC51C00.Concrete_Root with private;
   package PriExt_Overrides_All is

      type Concrete_Derived is new Formal_Derived with private;

   -- Proc and New_Proc below are declared in the visible part. Hence, unlike
   -- in PriExt_Overrides_Inherited above, in an instance they will override
   -- a corresponding implicit Proc and New_Proc inherited by Concrete_Derived
   -- from the actual, because they override a corresponding Proc and New_Proc
   -- in the generic:

      procedure Proc (P: in out Concrete_Derived);

      procedure New_Proc (P: out Concrete_Derived);

   private

      type Concrete_Derived is new Formal_Derived with null record;

   -- Inherited Func is abstract and must be overridden:
      function Func (P: Concrete_Derived) return Concrete_Derived;

   end PriExt_Overrides_All;


end BC51C01_1;
