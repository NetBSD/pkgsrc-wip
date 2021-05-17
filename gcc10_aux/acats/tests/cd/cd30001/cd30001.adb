
------------------------------------------------------------------- CD30001

with Report;
with CD30001_0;
procedure CD30001 is

begin  -- Main test procedure.

  Report.Test ("CD30001",
               "Check that X'Address produces a useful result when X is " &
               "an aliased object, or an entity whose Address has been " &
               "specified" );
   
--      Check that X'Address produces a useful result when X is an aliased
--      object.
--
--      Check that aliased objects and subcomponents are allocated on storage
--      element boundaries.  Check that objects and subcomponents of by
--      reference types are allocated on storage element boundaries.

  CD30001_0.TC_Check_Aliased_Addresses;

--      Check that X'Address produces a useful result when X is an entity
--      whose Address has been specified.

  CD30001_0.TC_Check_Specific_Addresses;

--      Check that X'Address produces a useful result when X is an object of
--      a by-reference type.

  CD30001_0.TC_Check_By_Reference_Types;

  Report.Result;

end CD30001;
