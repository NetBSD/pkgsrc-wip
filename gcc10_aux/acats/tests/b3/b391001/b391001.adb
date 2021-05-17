
with B391001_0;
procedure B391001 is
  package B391001_1 is

    type Unlimited_Tagged_Type is tagged record
      Simple_Component : Boolean;
    end record;

    type Limited_Type is limited private;

  private
    type Limited_Type is new Integer;
  end B391001_1;

  type Tagged_Default_Discriminant( Bad : Boolean := True )   -- ERROR:
    is tagged null record;                       -- Default not allowed

  type Illegal_Private_Extension is new B391001_1.Unlimited_Tagged_Type
    with private;                                              -- ERROR:
                          -- Illegal private extension in subprog. decl.

  type Illegal_Limited_Extension is new B391001_1.Unlimited_Tagged_Type
    with record
      Illegal_Component : B391001_1.Limited_Type;              -- ERROR:
    end record;                           -- Illegal use of limited type

  type Illegal_Extension is new B391001_1.Unlimited_Tagged_Type
    with record
      Simple_Component : Boolean;                              -- ERROR:
    end record;                   -- Illegal use of identical identifier

  package Herons is -- nested package
    type Nested_Hidden_Declaration is
      new B391001_0.Unlimited_Tagged_Type                      -- OK
        with record
          Another_Component: Boolean;
    end record;
  end Herons;

  generic
    type Endangered is tagged private;
  package Terns is -- nested generic
    type Another_Hidden_Illegal_Declaration is
      new Endangered                                               -- OK
	with record
	  Least_Component : Boolean;
    end record;
  end Terns;

begin  -- Main test procedure.

   null;

end B391001;
