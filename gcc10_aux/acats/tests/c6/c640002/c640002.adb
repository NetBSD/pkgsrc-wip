

with Report;
with C640002P;
procedure C640002 is

   package Pack is
      type Unit is new Float;
      function "*"       (L, R : Unit)         return Unit is abstract; -- (1)
      function Image     (L    : Unit)         return String;
      function Ext_Image (L    : Unit)         return String;

      type Unit_Squared is new Unit;
      function "*"       (L, R : Unit)         return Unit_Squared;     -- (2)
      function Ext_Image (L    : Unit_Squared) return String;
      --function Image (L : Unit_Squared) return String; -- Inherited here
   end Pack;

   package body Pack is
      function Image (L : Unit) return String is
      begin
         return Float'Image (Float (L)) (1 .. 4) & " (Unit)";
      end Image;

      function Ext_Image (L : Unit) return String is
      begin
         return Float'Image (Float (L)) (1 .. 4) & " (Ext Unit)";
      end Ext_Image;

      function "*" (L, R : Unit) return Unit_Squared is    -- (2)
      begin
         return Unit_Squared (Float (L) * Float (R));
      end "*";

      function Ext_Image (L : Unit_Squared) return String is
      begin
         return Float'Image (Float (L)) (1 .. 4) & " (Ext Unit_Squared)";
      end Ext_Image;
   end Pack;

begin
   Report.Test ("C640002", "Check that an abstract nondispatching operator " &
                           "provides a way to eliminate an unwanted " &
                           "predefined operator");

   --  Type of X * X is Unit_Squared because the function that returns the
   --  type 'Unit' is abstract

   declare
      use Pack;
      X : Pack.Unit := 2.0;
   begin
      --Report.Comment ("Local Package tests");

      if Image (X * X) /= " 4.0 (Unit)" then
         Report.Failed ("Wrong value at Image (X * X) [local]");
      end if;

      if Ext_Image (X * X) /= " 4.0 (Ext Unit_Squared)" then
         Report.Failed ("Wrong value at Ext_Image (X * X) [local]");
      end if;
   end;

   declare
      use C640002P;
      X : C640002P.Unit := 3.0;
   begin
      --Report.Comment ("External package tests");

      if Image (X * X) /= " 9.0 (Unit_Squared)" then
         Report.Failed ("Wrong value at Image (X * X) [extern]");
      end if;

      if Image (X + X) /= " 6.0 (Unit)" then
         Report.Failed ("Wrong value at Image (X + X) [extern]");
      end if;

      if Image (X + 4.0) /= " 7.0 (Unit)" then
         Report.Failed ("Wrong value at Image (X + 4.0) [extern]");
      end if;

      if Image (X * 2.0) /= " 6.0 (Unit_Squared)" then
         Report.Failed ("Wrong value at Image (X * 2.0) [extern]");
      end if;

      if Image ((X * X) - 4.0) /= " 5.0 (Unit_Squared)" then
         Report.Failed ("Wrong value at Image (X * X - 4.0) [extern]");
      end if;

   end;

   Report.Result;
end C640002;

