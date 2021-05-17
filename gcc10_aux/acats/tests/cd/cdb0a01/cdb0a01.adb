
------------------------------------------------------------------ CDB0A01

with Report;
with TCTouch;
with FDB0A00.Comparator;
with FDB0A00.Pool1;
with CDB0A01_2;
with CDB0A01_3;

procedure CDB0A01 is

  Banyan : CDB0A01_2.User_Pool_Tree;
  Torrey : CDB0A01_3.System_Pool_Tree;

  use type CDB0A01_2.User_Pool_Tree;
  use type CDB0A01_3.System_Pool_Tree;

  Countess     : constant String := "Ada Augusta Lovelace";
  Cenosstu     : constant String := "  AALaaacdeeglostuuv";
  Insertion    : constant String := "AAAAAAAAAAAAAAAAAAAA";
  Deallocation : constant String := "DDDDDDDDDDDDDDDDDDDD";

begin  -- Main test procedure.

   Report.Test ("CDB0A01", "Check that a storage pool may be " &
                           "user_determined, and that storage is " &
                           "allocated by calling Allocate.  Check that " &
                           "a storage.pool may be specified using " &
                           "'Storage_Pool and that S'Storage_Pool denotes " &
                           "the storage pool of the type S" );

--      Check that S'Storage_Pool denotes the storage pool for the type S.

  TCTouch.Assert(
     FDB0A00.Comparator."="(FDB0A00.Pool1.User_Pool,
                            CDB0A01_2.User_Pool_Tree'Storage_Pool ),
     "'Storage_Pool not correct for CDB0A01_2.User_Pool_Tree");

  TCTouch.Assert_Not(
     FDB0A00.Comparator."="(FDB0A00.Pool1.User_Pool,
                            CDB0A01_3.System_Pool_Tree'Storage_Pool ),
     "'Storage_Pool not correct for CDB0A01_3.System_Pool_Tree");

--      Check that storage is allocated by calling Allocate.

  for Count in Countess'Range loop
    CDB0A01_2.Insert( Countess(Count), Banyan );
  end loop;
  TCTouch.Validate(Insertion, "Allocate calls via CDB0A01_2" ); 

  for Count in Countess'Range loop
    CDB0A01_3.Insert( Countess(Count), Torrey );
  end loop;
  TCTouch.Validate("", "Allocate calls via CDB0A01_3" ); 

  CDB0A01_2.Traverse(Banyan);
  TCTouch.Validate(Cenosstu, "Traversal of Banyan" );

  CDB0A01_3.Traverse(Torrey);
  TCTouch.Validate(Cenosstu, "Traversal of Torrey" );

  CDB0A01_2.Defoliate(Banyan);
  TCTouch.Validate(Deallocation, "Deforestation of Banyan" );
  TCTouch.Assert(Banyan = null, "Banyan Deallocation result not null");

  CDB0A01_3.Defoliate(Torrey);
  TCTouch.Validate("", "Deforestation of Torrey" );
  TCTouch.Assert(Torrey = null, "Torrey Deallocation result not null");

  Report.Result;

end CDB0A01;
