
     --==================================================================--

with CA11015_0.CA11015_1;              -- Generic map operation,
                                       -- implicitly withs parent, basic map
                                       -- application.
with Report;

procedure CA11015 is

begin 

   Report.Test ("CA11015", "Check that an instantiation of a child package " &
                           "of a non-generic package can use its parent's "  &
                           "declarations and operations");

-- An application creates a population map using an integer type.

           Population_Map_Subtest:
           declare
              type Population_Type is range 0 .. 10_000;         

              -- Declare instance of the child generic map package for one 
              -- particular integer type.            

              package Population is new CA11015_0.CA11015_1 (Population_Type);

              Population_Map_Latitude   : CA11015_0.Latitude := 1;  
                                                   -- parent's type
              Population_Map_Longitude : CA11015_0.Longitude := 5;
                                                   -- parent's type
              Pop_Map                   : Population.Feature_Map;
              Pop                       : Population_Type := 1000;

           begin
              Population.Set_Feature_Val (Population_Map_Latitude, 
                                          Population_Map_Longitude,
                                          Pop, 
                                          Pop_Map);

              If not ( (Population.Get_Feature_Val (Population_Map_Latitude, 
                Population_Map_Longitude, Pop_Map) = Pop) or  
                  (Population.Check_Page (Pop_Map, 1)) ) then
                    Report.Failed ("Population map contains incorrect values");
              end if;

           end Population_Map_Subtest;

-- An application creates a weather map using an enumeration type.

           Weather_Map_Subtest:
           declare
              type Weather_Type is (Hot, Cold, Mild);                    

              -- Declare instance of the child generic map package for one 
              -- particular enumeration type.            

              package Weather_Pkg is new CA11015_0.CA11015_1 (Weather_Type);

              Weather_Map_Latitude   : CA11015_0.Latitude := 2;
                                                   -- parent's type
              Weather_Map_Longitude : CA11015_0.Longitude := 6;
                                                   -- parent's type
              Weather_Map            : Weather_Pkg.Feature_Map;
              Weather                : Weather_Type := Mild;

           begin
              Weather_Pkg.Set_Feature_Val (Weather_Map_Latitude, 
                                           Weather_Map_Longitude,
                                           Weather, 
                                           Weather_Map);

              if ( (Weather_Pkg.Get_Feature_Val (Weather_Map_Latitude, 
                    Weather_Map_Longitude, Weather_Map) /= Weather) or
                not (Weather_Pkg.Check_Page (Weather_Map, 2)) )
              then
                 Report.Failed ("Weather map contains incorrect values");
              end if;

           end Weather_Map_Subtest;

-- During processing, the application may erroneously attempts to create 
-- a density map on an unexplored area.  This would result in the raising 
-- of an exception.

           Density_Map_Subtest:
           declare
              type Density_Type is (High, Medium, Low);

              -- Declare instance of the child generic map package for one 
              -- particular enumeration type.            

              package Density_Pkg is new CA11015_0.CA11015_1 (Density_Type);

              Density_Map_Latitude   : CA11015_0.Latitude := 7;
                                                   -- parent's type
              Density_Map_Longitude : CA11015_0.Longitude := 2;
                                                   -- parent's type
              Density                : Density_Type := Low;
              Density_Map            : Density_Pkg.Feature_Map;

           begin
              Density_Pkg.Set_Feature_Val (Density_Map_Latitude, 
                                           Density_Map_Longitude,
                                           Density, 
                                           Density_Map);

              Report.Failed ("Exception not raised in child generic package");

           exception

              when CA11015_0.Terra_Incognita =>   -- parent's exception,
                  null;                           -- raised in child.

              when others          =>         
                  Report.Failed ("Others exception is raised");

           end Density_Map_Subtest;

   Report.Result;

end CA11015;
