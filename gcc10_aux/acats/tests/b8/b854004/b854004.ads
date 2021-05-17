
with B854004A;
package B854004 is

   type NT is new B854004A.Root with null record;

   -- Inherits here:
   --procedure Proc (Obj : in out NT); -- Requires overriding.
   --function Func (Obj : in NT) return Boolean; -- Requires overriding.
   --function Count (Obj : in NT) return Natural;
   --procedure Sink (Obj : in NT);

   procedure RenP1 (Obj : in out NT) renames Proc;       -- ERROR: {4;1}
   function RenF1 (Obj : in NT) return Boolean
                                   renames Func;         -- ERROR: {1:4;1}
   function RenC1 (Obj : in NT) return Natural
                                   renames Count;        -- OK. {1:4;1}
   procedure RenS1 (Obj : in NT) renames Sink;           -- OK. {4;1}

   type NT2 is new B854004A.Root2 with null record;

   -- Inherits here:
   --function Empty_1 return NT2;
   --function Empty_2 return access NT2; -- Requires overriding.

   function RenE11 return NT2 renames Empty_1;           -- OK. {4;1}
   function RenE21 return access NT2 renames Empty_2;    -- ERROR: {4;1}

   type NT3 is new B854004A.Root2 with record
      C : Character := 'R';
   end record;

   -- Inherits here:
   --function Empty_1 return NT3; -- Requires overriding.
   --function Empty_2 return access NT3; -- Requires overriding.

   function RenE13 return NT3 renames Empty_1;           -- ERROR: {4;1}
   function RenE23 return access NT3 renames Empty_2;    -- ERROR: {4;1}


private
   -- Required overridings:
   overriding
   procedure Proc (Obj : in out NT);
   overriding
   function Func (Obj : in NT) return Boolean;
   overriding
   function Empty_2 return access NT2;
   overriding
   function Empty_1 return NT3;
   overriding
   function Empty_2 return access NT3;

   procedure RenP2 (Obj : in out NT) renames Proc;       -- OK. {4;1}
   function RenF2 (Obj : in NT) return Boolean
                                   renames Func;         -- OK. {1:4;1}
   function RenC2 (Obj : in NT) return Natural
                                   renames Count;        -- OK. {1:4;1}
   procedure RenS2 (Obj : in NT) renames Sink;           -- OK. {4;1}

   package Cant_be_Primitive is
      function RenE12 return NT2 renames Empty_1;        -- OK. {7;1}
      function RenE22 return access NT2 renames Empty_2; -- OK. {7;1}

      function RenE14 return NT3 renames Empty_1;        -- OK. {7;1}
      function RenE24 return access NT3 renames Empty_2; -- OK. {7;1}
   end Cant_be_Primitive;

end B854004;

