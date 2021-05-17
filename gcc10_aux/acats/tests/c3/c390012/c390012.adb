

with Report, TCTouch;
with C390012_Geometry, C390012_Manager;
with Ada.Tags.Generic_Dispatching_Constructor;

-- We use the following packages only for verification purposes,
-- but even in a real program they have to be
-- withed somewhere so they are included in the program.
with C390012_Geometry.Circles, C390012_Geometry.Squares,
     C390012_Geometry.Triangles, C390012_Geometry.Ghosts;

procedure C390012 is

   function Create_Object is new Ada.Tags.Generic_Dispatching_Constructor
      (C390012_Geometry.Object, Parameters => C390012_Geometry.Params,
       Constructor => C390012_Geometry.Make_Object);

   procedure TC_Check_Object (O : in C390012_Geometry.Object'Class;
                              N : in String;
                              P : in C390012_Geometry.Params;
                              Code : in Character) is
   begin
      if O.X_Coord /= P.X_Coord or else
         O.Y_Coord /= P.Y_Coord then
         Report.Failed ("Coordinates wrong (" & Code & ')');
      end if;
      if O.Size_Param /= P.Size then
         Report.Failed ("Size wrong (" & Code & ')');
      end if;
      if O.Name /= N then
         Report.Failed ("Object name was " & O.Name & "; expected " & N &
                         " (" & Code & ')');
      end if;
   end TC_Check_Object;

begin
   Report.Test ("C390012", "Check that an instance of " &
                           "Generic_Dispatching_Constructor calls the " &
                           "correct functions and creates objects of the " &
                           "correct type");

   -- Check that the types got registered:
   TCTouch.Validate_One_Of (Expected_1 => "rCrSrT",
                            Expected_2 => "rCrTrS",
                            Expected_3 => "rSrCrT",
                            Expected_4 => "rSrTrC",
                            Expected_5 => "rTrCrS",
                            Expected_6 => "rTrSrC",
                            Message => "Type registration incorrect (A)");
      -- Note: Order of elaboration is unspecified, so
      -- we allow all six possible orders.

   -- Try a class-wide object declaration:
   declare
      P : aliased C390012_Geometry.Params := (X_Coord => 3.0,
                                              Y_Coord => 4.0,
                                              Size    => 2.0);
      O : C390012_Geometry.Object'Class := Create_Object (
          C390012_Manager.Decode ('C'), P'access);
   begin
      TCTouch.Validate (Expected => "MC",
                        Message =>  "Incorrect construction (B)");

      TC_Check_Object (O, "Circle", P, 'B');
      if O.Distance /= 5.0 then
         Report.Failed ("Distance wrong (B)");
      end if;
   end;

   -- Try directly passing as a class-wide parameter:
   declare
      P : aliased C390012_Geometry.Params := (X_Coord => 1.0,
                                              Y_Coord => 1.0,
                                              Size    => 3.0);
      procedure Use_It (O : in C390012_Geometry.Object'Class) is
      begin
         TC_Check_Object (O, "Square", P, 'C');
         if O.Area /= 9.0 then
            Report.Failed ("Area wrong (C)");
         end if;
      end Use_It;
   begin
      Use_It (Create_Object (C390012_Manager.Decode ('S'), P'access));

      TCTouch.Validate (Expected => "MSAS",
                        Message =>  "Incorrect construction (C)");
   end;

   -- Try using as an initialized allocator:
   declare
      P : aliased C390012_Geometry.Params := (X_Coord => 1.0,
                                              Y_Coord => 3.0,
                                              Size    => 1.5);
      type Node is access C390012_Geometry.Object'Class;
      Head : Node;
   begin
      Head := new C390012_Geometry.Object'Class'(
                 Create_Object (C390012_Manager.Decode ('T'), P'access));

      TC_Check_Object (Head.all, "Triangle", P, 'D');
      if Head.Area /= 1.125 then
         Report.Failed ("Area wrong (D)");
      end if;
      TCTouch.Validate (Expected => "MTAT",
                        Message =>  "Incorrect construction (D)");
   end;

   -- Check that attempting to create a Ghost (an abstract type) causes
   -- Tag_Error to be raised:
   begin
      C390012_Geometry.Ghosts.Register;
      TCTouch.Validate (Expected => "rG",
                        Message =>  "Ghost not registered properly (E)");

      declare
         P : aliased C390012_Geometry.Params := (X_Coord => 1.0,
                                                 Y_Coord => 2.5,
                                                 Size    => 0.75);
         O : C390012_Geometry.Object'Class := Create_Object (
             C390012_Manager.Decode ('G'), P'access);
      begin
          Report.Failed ("Creation of Ghost did not raise Tag_Error (E)");
          TC_Check_Object (O, "Ghost", P, 'E');
      end;
   exception
      when Ada.Tags.Tag_Error =>
         Report.Comment ("Tag_Error raised as expected from attempt to " &
                         "create abstract object (E)");
   end;

   -- Check that an unused code (which will return No_Tag) causes Tag_Error
   -- to be raised:
   begin
      declare
         P : aliased C390012_Geometry.Params := (X_Coord => 1.5,
                                                 Y_Coord => 2.0,
                                                 Size    => 0.5);
         O : C390012_Geometry.Object'Class := Create_Object (
             C390012_Manager.Decode ('Z'), P'access);
      begin
          Report.Failed ("Creation of unknown code did not raise " &
                         "Tag_Error (F)");
          TC_Check_Object (O, "Zowie", P, 'F');
      end;
   exception
      when Ada.Tags.Tag_Error =>
         Report.Comment ("Tag_Error raised as expected from attempt to " &
                         "create object from No_Tag (F)");
   end;

   -- Check that calling Create_Object with the tag of a type that is not
   -- descended from Object causes Tag_Error to be raised:
   begin
      declare
         P : aliased C390012_Geometry.Params := (X_Coord => 8.0,
                                                 Y_Coord => 1.0,
                                                 Size    => 0.5);
         O : C390012_Geometry.Object'Class := Create_Object (
             C390012_Manager.Dummy'Tag, P'access);
      begin
          Report.Failed ("Creation of Dummy object code did not raise " &
                         "Tag_Error (G)");
          TC_Check_Object (O, "Dummy", P, 'G');
      end;
   exception
      when Ada.Tags.Tag_Error =>
         null; -- OK, Tag_Error expected.
         Report.Comment ("Tag_Error raised as expected from attempt to " &
                         "create object from an unrelated type (G)");
   end;

   -- Check that attempting to create a EQ (a type more nested than the
   -- instance of Ada.Tags.Generic_Dispatching_Constructor) causes
   -- Tag_Error to be raised:
   declare

      procedure Nested_Subtest (Size : in Float) is
         package EQs is

            type EQ is new C390012_Geometry.Object with private;
                -- EQ = Equilateral Triangle.
            -- Concrete versions of abstract routines:
            function Make_Object (P : not null access C390012_Geometry.Params)
                return EQ;
               -- For a EQ, the size is that of one side.
            function Area (E : in EQ) return Float;
            function Name (E : in EQ) return String;
            function Size_Param (E : in EQ) return Float;

         private

            type EQ is new C390012_Geometry.Object with
               record
                  Side: Float;
               end record;

         end EQs;

         package body EQs is

            function Make_Object (P : not null access C390012_Geometry.Params)
                return EQ is
            begin
               TCTouch.Touch ('M'); TCTouch.Touch ('E'); --------------- "ME"
               return EQ'(C390012_Geometry.Object with Side => P.Size);
                   -- Careful: This isn't usable if this routine actually
                   -- gets called (the coordinates are undefined).
            end Make_Object;

            function Area (E : in EQ) return Float is
            begin
               TCTouch.Touch ('A'); TCTouch.Touch ('C'); --------------- "AE"
               return Size**2; -- Not right, but this ought to never be called.
            end Area;

            function Name (E : in EQ) return String is
            begin
               return "EQ";
            end Name;

            function Size_Param (E : in EQ) return Float is
            begin
               return E.Side;
            end Size_Param;

         begin
            C390012_Manager.Register (EQ'Tag, 'E'); -- Register the EQ type.
         end EQs;

      begin
         TCTouch.Validate (Expected => "rE",
                           Message =>  "EQ not registered properly (H)");
         declare
            P : aliased C390012_Geometry.Params := (X_Coord => 3.5,
                                                    Y_Coord => 1.0,
                                                    Size    => 1.5);
            O : C390012_Geometry.Object'Class := Create_Object (
                C390012_Manager.Decode ('E'), P'access);
         begin
             Report.Failed ("Creation of EQ did not raise Tag_Error (H)");
             TC_Check_Object (O, "EQ", P, 'H');
         end;
      exception
         when Ada.Tags.Tag_Error =>
            Report.Comment ("Tag_Error raised as expected from attempt to " &
                            "create an object of a more nested type (H)");
      end Nested_Subtest;

   begin
      Nested_Subtest (10.0);
   end;

   Report.Result;
end C390012;

