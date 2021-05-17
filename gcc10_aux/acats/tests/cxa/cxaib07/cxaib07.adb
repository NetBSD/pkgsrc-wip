
with Report;
with CXAIB07_Data, FXAIB00; use CXAIB07_Data;
with Ada.Containers;
procedure CXAIB07 is
    use type Ada.Containers.Count_Type; -- Make operators visible.
    use type FXAIB00.Location; -- Make operators visible.
begin
   Report.Test ("CXAIB07", "Check that Ada.Containers.Hashed_Maps is " &
                           "preelaborated and that type Map has " &
                           "Preeelaborable_Initialization");

   -- Check that the containers start empty:
   if Static_Locations.Length /= 0 then
      Report.Failed ("Static locations not empty on initialization");
   end if;
   if not Moveable_Locations.Is_Empty then
      Report.Failed ("Moveable locations not empty on initialization");
   end if;

   -- Insert data, saving cursors:
   Static_Locations.Include (Key => "Sheboygan",
                             New_Item => (X => 100, Y => 50));
   Static_Locations.Include (Key => "Madison  ",
                             New_Item => (X => 0, Y => 0));
   Static_Locations.Include (Key => "Wausau   ",
                             New_Item => (X => 0, Y => 150));
   Static_Locations.Include (Key => "Green_Bay",
                            New_Item => (X => 75, Y => 120));

   Moveable_Locations.Include (Key => "Windstar ",
                               New_Item => (Id => <>,
                                            Loc => (X => 100, Y => 50)));
   Moveable_Locations.Include (Key => "Mazda_3  ",
                               New_Item => (Id => <>,
                                            Loc => (X => 0, Y => 0)));
   Moveable_Locations.Include (Key => "Forester ",
                               New_Item => (Id => <>,
                                            Loc => (X => -10, Y => 0)));

   -- Check that the lengths are correct:
   if Static_Locations.Length /= 4 then
      Report.Failed ("Wrong number of static locations after loading");
   end if;
   if Moveable_Locations.Length /= 3 then
      Report.Failed ("Wrong number of moveable locations after loading");
   end if;

   -- Check a few values (using indexed notation):
   if Static_Locations("Sheboygan") /= (X => 100, Y => 50) then
      Report.Failed ("Wrong data - Sheboygan");
   end if;
   if Static_Locations("Green_Bay") /= (X => 75, Y => 120) then
      Report.Failed ("Wrong data - Green Bay");
   end if;
   if Moveable_Locations("Mazda_3  ").Loc /= (X => 0, Y => 0) then
      Report.Failed ("Wrong data - Mazda 3");
   end if;
   if Moveable_Locations("Forester ").Loc /= (X => -10, Y => 0) then
      Report.Failed ("Wrong data - Forester");
   end if;

   -- Move the Mazda 3:
   Moveable_Locations("Mazda_3  ").Loc := (X => 100, Y => 50);

   -- Check that it moved:
   if Moveable_Locations("Mazda_3  ").Loc /= (X => 100, Y => 50) then
      Report.Failed ("Wrong data after moving - Mazda 3");
   end if;

   -- Check that the ids are unique:
   if Moveable_Locations("Mazda_3  ").Id =
                               Moveable_Locations("Forester ").Id or else
      Moveable_Locations("Mazda_3  ").Id =
                               Moveable_Locations("Windstar ").Id or else
      Moveable_Locations("Forester ").Id =
                               Moveable_Locations("Windstar ").Id then
      Report.Failed ("Ids not unique for moveable data");
   end if;

   Report.Result;
end CXAIB07;
