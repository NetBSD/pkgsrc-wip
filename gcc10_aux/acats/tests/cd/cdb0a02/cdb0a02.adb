
------------------------------------------------------------------ CDB0A02

with Report;
with TCTouch;
with System.Storage_Elements;
with CDB0A02_2;
with CDB0A02_3;
with FDB0A00;

procedure CDB0A02 is

  Banyan : CDB0A02_2.Small_Tree;
  Torrey : CDB0A02_3.Large_Tree;

  use type CDB0A02_2.Small_Tree;
  use type CDB0A02_3.Large_Tree;

  Countess1    : constant String := "Ada ";
  Countess2    : constant String := "Augusta ";
  Countess3    : constant String := "Lovelace";
  Cenosstu     : constant String := "  AALaaacdeeglostuuv";
  Insertion    : constant String := "AAAAAAAAAAAAAAAAAAAA"
                                  & "AAAAAAAAAAAAAAAAAAAA";
  Deallocation : constant String := "DDDDDDDDDDDDDDDDDDDD";

begin  -- Main test procedure.

   Report.Test ("CDB0A02", "Check that several access types can share " &
                           "the same pool.  Check that any exception " &
                           "propagated by Allocate is propagated by the " &
                           "allocator.  Check that for an access type S, " &
                           "S'Max_Size_In_Storage_Elements denotes the " &
                           "maximum values for Size_In_Storage_Elements " &
                           "that will be requested via Allocate" );

  -- Check that access types can share the same pool.

  for Count in Countess1'Range loop
    CDB0A02_2.Insert( Countess1(Count), Banyan );
  end loop;

  for Count in Countess1'Range loop
    CDB0A02_3.Insert( Countess1(Count), Torrey );
  end loop;

  for Count in Countess2'Range loop
    CDB0A02_2.Insert( Countess2(Count), Banyan );
  end loop;

  for Count in Countess2'Range loop
    CDB0A02_3.Insert( Countess2(Count), Torrey );
  end loop;

  for Count in Countess3'Range loop
    CDB0A02_2.Insert( Countess3(Count), Banyan );
  end loop;

  for Count in Countess3'Range loop
    CDB0A02_3.Insert( Countess3(Count), Torrey );
  end loop;

  TCTouch.Validate(Insertion, "Allocate calls via CDB0A02_2" );


  CDB0A02_2.Traverse(Banyan);
  TCTouch.Validate(Cenosstu, "Traversal of Banyan" );

  CDB0A02_3.Traverse(Torrey);
  TCTouch.Validate(Cenosstu, "Traversal of Torrey" );

  CDB0A02_2.Defoliate(Banyan);
  TCTouch.Validate(Deallocation, "Deforestation of Banyan" );
  TCTouch.Assert(Banyan = null, "Banyan Deallocation result not null");

  CDB0A02_3.Defoliate(Torrey);
  TCTouch.Validate(Deallocation, "Deforestation of Torrey" );
  TCTouch.Assert(Torrey = null, "Torrey Deallocation result not null");

  -- Check that for an access type S, S'Max_Size_In_Storage_Elements
  -- denotes the maximum values for Size_In_Storage_Elements that will
  -- be requested via Allocate. (Of course, all we can do is check that
  -- whatever was requested of Allocate did not exceed the values of the
  -- attributes.)

  TCTouch.Assert( FDB0A00.TC_Largest_Request in 1 ..
                  System.Storage_Elements.Storage_Count'Max (
                    CDB0A02_2.Small_Cell'Max_Size_In_Storage_Elements,
                    CDB0A02_3.Large_Cell'Max_Size_In_Storage_Elements),
                  "An object of excessive size was allocated.  Size: "
   & System.Storage_Elements.Storage_Count'Image(FDB0A00.TC_Largest_Request));

  -- Check that an exception raised in Allocate is propagated by the allocator.

  CDB0A02_2.TC_Exceed_Pool;

  Report.Result;

end CDB0A02;
