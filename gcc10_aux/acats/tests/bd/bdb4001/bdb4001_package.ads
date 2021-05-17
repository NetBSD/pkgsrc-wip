
with BDB4001_Tracked_Subpools;
package BDB4001_Package is

   Pool_1 : aliased BDB4001_Tracked_Subpools.Tracked_Pool;

   type Location is record
      X, Y : Natural;
   end record;

   type Acc1 is access Natural
      with Storage_Pool => Pool_1;                       -- OK. {1:4;1}

   type Acc2 is access Float;
   for Acc2'Storage_Pool use Pool_1;                     -- OK. {4;1}

   type Acc_Pool is access all BDB4001_Tracked_Subpools.Tracked_Pool;

   Indir_Pool : Acc_Pool := Pool_1'Access;               -- OK. {4;1}

   type Acc3 is access Location
      with Storage_Pool => Indir_Pool.all;               -- OK. {1:4;1}

   type Acc4 is access String;
   for Acc4'Storage_Pool use Indir_Pool.all;             -- OK. {4;1}

   type Pool_Rec is record
       Pool_Comp : BDB4001_Tracked_Subpools.Tracked_Pool;
       Count     : Natural;
   end record;

   Pool_Rec_1 : aliased Pool_Rec := (Pool_Comp => <>, Count => 12);

end BDB4001_Package;
