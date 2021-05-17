

     --==================================================================--


with Ada.Characters.Handling;

package body ImpDef is

   -- NOTE: These are example bodies.  It is expected that implementors
   --       will write their own versions of these routines.

--=====-=====-=====-=====-=====-=====-=====-=====-=====-=====-=====-=====--

   -- The time required to execute this procedure must be greater than the
   -- time slice unit on implementations which use time slicing.  For
   -- implementations which do not use time slicing the body can be null.

   procedure Exceed_Time_Slice is
      T : Integer := 0;
      Loop_Max : constant Integer := 4_000;
   begin
      for I in 1..Loop_Max loop
         T := Report.Ident_Int (1) * Report.Ident_Int (2);
      end loop;
   end Exceed_Time_Slice;

--=====-=====-=====-=====-=====-=====-=====-=====-=====-=====-=====-=====--

   -- The following function returns true if Left and Right file names
   -- represent the same file or directory on the target system.
   --
   -- For many systems, directly comparing the file names will be sufficient.
   -- However, if the target supports alternative forms of file names, a
   -- more complex function may be required. For instance, on a case
   -- insensitive or case preserving target, the case of the file names
   -- may vary without changing the meaning of the file name. In that case,
   -- this function should take that into account.
   --
   -- This does not need to be a perfect file name comparison for the
   -- target system; the file names to be compared will come from
   -- Ada language-defined packages like Ada.Text_IO (from the Name
   -- function) and Ada.Directories, as well as from Report.Legal_File_Name.
   -- For instance, on Windows, the Ada runtime will probably use either
   -- '/' or '\', but probably not both, so it isn't necessary to implement
   -- that equivalence in this function.

   function Equivalent_File_Names (Left, Right : String) return Boolean is
      use Ada.Characters.Handling;
   begin
       return To_Lower (Left) = To_Lower (Right);
   end Equivalent_File_Names;

--=====-=====-=====-=====-=====-=====-=====-=====-=====-=====-=====-=====--

end ImpDef;
