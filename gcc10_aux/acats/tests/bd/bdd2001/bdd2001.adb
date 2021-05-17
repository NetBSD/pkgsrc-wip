
   --======================================================================--

with Ada.Streams.Stream_IO;
with BDD2001_0;

procedure BDD2001 is

   type Non_Limited_Type is range 1 .. 10;

   task type Task_Type is
      entry The_Entry;
   end Task_Type;

   task body Task_Type is
   begin
      accept The_Entry;
   end Task_Type;

   type Derived_Limited_Type is new BDD2001_0.Limited_Type;

   type Non_Lim_Comp_Type is
      record
         Non_Limited_Component_Field : Integer := 0;
      end record;

   type Comp_With_Lim_Type is
      record
         Limited_Component_Field : BDD2001_0.Limited_Type;
      end record;

   type Comp_With_Lim_Disc (Disc : access Non_Limited_Type) is limited
      record
         Non_Lim_Field : Non_Limited_Type;
      end record;

   type Comp_With_Der_Lim_Type is
      record
         Derived_Limited_Component_Field : Derived_Limited_Type;
      end record;

   type Composite_With_Task_Type is
      record
         Task_Component_Field : Task_Type;
      end record;

   protected type Protected_Type is
         entry Obtain;
         procedure Return_Result;
      private
         In_Use : Boolean := False;
   end Protected_Type;

   protected body Protected_Type is

      entry Obtain when not In_Use is
      begin
         In_Use := True;
      end Obtain;

      procedure Return_Result is
      begin
         In_Use := False;
      end Return_Result;

   end Protected_Type;


   Limited_Object             : BDD2001_0.Limited_Type;
   Root_Object                : BDD2001_0.Root_Type;
   Extended_Object            : BDD2001_0.Extended_Type;
   Root_With_LComp_Object     : BDD2001_0.Root_With_Limited_Comp_Type;
   Extended_With_LComp_Object : BDD2001_0.Extended_With_Limited_Comp_Type;
   New_Root_Object            : BDD2001_0.New_Root_Type;
   Non_Limited_Object         : Non_Limited_Type;
   Task_Object                : Task_Type;
   Derived_Limited_Object     : Derived_Limited_Type;
   Non_Lim_Comp_Object        : Non_Lim_Comp_Type;
   Composite_Object1          : Comp_With_Lim_Type;
   Composite_Object3          : Composite_With_Task_Type;
   A_Protected_Object         : Protected_Type;

   Stream_File_Object         : Ada.Streams.Stream_IO.File_Type;
   Str_Access                 : Ada.Streams.Stream_IO.Stream_Access;

   No_Opt                     : Integer := 25;

   procedure Dummy1 (In_Param : BDD2001_0.Limited_Type) is
   begin
      No_Opt := No_Opt - 17;
   end Dummy1;

   procedure Dummy2 (In_Param : Comp_With_Der_Lim_Type) is
   begin
      No_Opt := No_Opt - 21;
   end Dummy2;

   procedure Dummy3 (In_Param : Comp_With_Lim_Disc) is
   begin
      No_Opt := No_Opt - 2;
   end Dummy3;

   procedure Dummy4 (In_Param : BDD2001_0.New_Root_Type) is
   begin
      No_Opt := No_Opt - 17;
   end Dummy4;



begin

   Ada.Streams.Stream_IO.Create (Stream_File_Object,
                                 Ada.Streams.Stream_IO.Out_File,
                                 "AFile");

   Str_Access := Ada.Streams.Stream_IO.Stream (Stream_File_Object);


   -- Ensure that an attempt at writing data to a stream using the 'Output
   -- attribute for a task type, limited type, or composite type containing
   -- a limited type is rejected.

   Non_Limited_Type'Output (Str_Access, Non_Limited_Object);         -- OK

   Task_Type'Output (Str_Access,  Task_Object);                      -- ERROR:
                                                 -- Task_Type is limited.

   Derived_Limited_Type'Output (Str_Access, Derived_Limited_Object); -- ERROR:
                                                 -- Derived limited type is
                                                 -- limited.

   Comp_With_Lim_Type'Output (Str_Access, Composite_Object1);        -- ERROR:
                                                 -- Type contains a component
                                                 -- of a limited type.

   Composite_With_Task_Type'Output (Str_Access, Composite_Object3);  -- ERROR:
                                                 -- Type contains a component
                                                 -- of a task type.

   Protected_Type'Output (Str_Access, A_Protected_Object);           -- ERROR:
                                                 -- Protected_Type is limited.




   -- Ensure that an attempt at reading from a stream using the 'Input
   -- attribute for a task type, limited type, or composite type containing
   -- a limited type is rejected.

   Non_Limited_Object := Non_Limited_Type'Input (Str_Access);        -- OK

   Dummy1 (BDD2001_0.Limited_Type'Input (Str_Access));               -- ERROR:
                                                 -- Limited type is limited.

   Non_Lim_Comp_Object := Non_Lim_Comp_Type'Input (Str_Access);      -- OK

   Dummy2 (Comp_With_Der_Lim_Type'Input (Str_Access));               -- ERROR:
                                                 -- Type contains a component
                                                 -- of a type derived from a
                                                 -- limited type.

   Dummy3 (Comp_With_Lim_Disc'Input (Str_Access));                   -- ERROR:
                                                 -- Type has access discrim.





   -- Ensure that an attempt at writing to a stream using the 'Class'Output
   -- attribute for specific limited types within a class is rejected.

   BDD2001_0.Root_Type'Class'Output (Str_Access, Root_Object);       -- ERROR:
                                                 -- Root type is limited.

   BDD2001_0.Extended_Type'Class'Output                              -- ERROR:
     (Str_Access, Extended_Object);              -- Type extended from a
                                                 -- limited type.

   BDD2001_0.Root_With_Limited_Comp_Type'Class'Output                -- ERROR:
     (Str_Access, Root_With_LComp_Object);
                                                 -- Type has component of
                                                 -- limited type.

end BDD2001;
