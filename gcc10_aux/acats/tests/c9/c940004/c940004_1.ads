
--============================--
-- no body for C940004_0
--=============================--

with C940004_0; -- Resource_Pkg

-- This generic package implements a semaphore to control a single resource

generic

  type Generic_Record_Type is new C940004_0.User_Descriptor_Type
                                                         with private;

package C940004_1 is
-- Generic_Semaphore_Pkg
                -- generic package extends the tagged formal generic
                -- type with some implementation relevant details, and
                -- it provides a semaphore with operations that work
                -- on that type
   type User_Rec_Type is new Generic_Record_Type with private;

   protected type Semaphore_Type is
      function  TC_Count return Integer;
      entry     Request (R : in out User_Rec_Type);
      procedure Release (R : in out User_Rec_Type);
   private
      In_Use : Boolean := false;
   end Semaphore_Type;

   function Has_Access (R : User_Rec_Type) return Boolean;

private

   type User_Rec_Type is new Generic_Record_Type with record
      Access_To_Resource : boolean := false;
   end record;

end C940004_1;        -- Generic_Semaphore_Pkg
