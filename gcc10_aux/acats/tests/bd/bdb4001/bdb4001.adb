

with BDB4001_Package; use BDB4001_Package;
with BDB4001_Tracked_Subpools;

procedure BDB4001 is

   Pool_2 : aliased BDB4001_Tracked_Subpools.Tracked_Pool;

   type Acc1 is access Location
      with Storage_Pool => Pool_2;                       -- OK. {1:4;1}

   type Acc2 is access Natural;
   for Acc2'Storage_Pool use Pool_2;                     -- OK. {4;1}

   type Acc_Pool_2 is access BDB4001_Tracked_Subpools.Tracked_Pool;
      -- Not a general access type.

   Indir_Pool_2 : Acc_Pool_2 := new BDB4001_Tracked_Subpools.Tracked_Pool;

   type Acc3 is access Float
      with Storage_Pool => Indir_Pool_2.all;             -- OK. {1:4;1}

   type Acc4 is access String;
   for Acc4'Storage_Pool use Indir_Pool_2.all;           -- OK. {4;1}

   type Acc_Pool_3 is access all BDB4001_Tracked_Subpools.Tracked_Pool;

   Indir_Pool_3 : Acc_Pool_3 := Pool_2'Access;

   procedure Test (A_Pool : in out BDB4001_Tracked_Subpools.Tracked_Pool;
                   A_Rec  : in out Pool_Rec) is

      Pool_4 : aliased BDB4001_Tracked_Subpools.Tracked_Pool;

      type Acc_Pool_4 is access all BDB4001_Tracked_Subpools.Tracked_Pool;

      Indir_Pool_4 : Acc_Pool_4 := Pool_4'Access;
         -- Note: Could have been Pool_1 or Pool_2 as well.

      type Acc_Pool_5 is access all Pool_Rec;

      Indir_Pool_5 : Acc_Pool_5 := Pool_Rec_1'Access;

      type Acc_Pool_6 is access Pool_Rec;
          -- Not a general access type.

      Indir_Pool_6 : Acc_Pool_6 := new Pool_Rec;

      type Acc11 is access Location
         with Storage_Pool => Pool_1;                    -- ERROR: (A) {1:7;1}

      type Acc12 is access Location
         with Storage_Pool => Pool_2;                    -- ERROR: (A) {1:7;1}

      type Acc13 is access Natural
         with Storage_Pool => Pool_4;                    -- OK. {1:7;1}

      type Acc14 is access Float;
      for Acc14'Storage_Pool use Pool_1;                 -- ERROR: (A) {7;1}

      type Acc15 is access String;
      for Acc15'Storage_Pool use Pool_4;                 -- OK. {7;1}

      type Acc16 is access String;
      for Acc16'Storage_Pool use Indir_Pool.all;         -- ERROR: (A) {7;1}

      type Acc17 is access Pool_Rec
          with Storage_Pool => Indir_Pool_2.all;         -- ERROR: (A) {1:7;1}

      type Acc20 is access Pool_Rec;
      for Acc20'Storage_Pool use A_Pool;                 -- ERROR: (B) {7;1}

      type Acc21 is access Natural
         with Storage_Pool => A_Rec.Pool_Comp;           -- ERROR: (B) {1:7;1}

      type Acc30 is access Natural
         with Storage_Pool => Indir_Pool_3.all;          -- ERROR: (C) {1:7;1}

      type Acc31 is access Natural
         with Storage_Pool => Indir_Pool_4.all;          -- ERROR: (C) {1:7;1}

      type Acc32 is access Float
         with Storage_Pool => Indir_Pool_5.Pool_Comp;    -- ERROR: (C) {1:7;1}

      type Acc33 is access Location
         with Storage_Pool => Indir_Pool_6.Pool_Comp;    -- OK. {1:7;1}

      type Acc40 is access all Natural
         with Storage_Pool => Pool_4;                    -- ERROR: (D) {1:7;1}

      type Acc41 is access constant Location;
      for Acc41'Storage_Pool use Pool_4;                 -- ERROR: (D) {1:7;1}

      type Acc42 is access all Float
         with Storage_Pool => Indir_Pool_6.Pool_Comp;    -- ERROR: (D) {1:7;1}

   begin
      null;
   end Test;

begin
    Test (Pool_1, Pool_Rec_1);

end BDB4001;
