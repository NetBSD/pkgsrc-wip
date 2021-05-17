
----------------------------------------------------------------------------

with BXE4001_Pure;
package BXE4001_Types is
  pragma Remote_Types;

  type Ptr_1 is access all BXE4001_Pure.Tagged_Type_1'Class;
  pragma Asynchronous (Ptr_1);                                     -- OK.

  type Ptr_2 is access all BXE4001_Pure.Tagged_Type_2'Class;
  pragma Asynchronous (Ptr_2);                                     -- OK.
     -- A warning would be appropriate here since none of the primitive
     -- operations can be called asynchronously.

private

  type Ptr_X is access all Integer;
  pragma Asynchronous (Ptr_X);                                     -- ERROR:
                                   -- not a remote access-to-class-wide type

  subtype Second_Subtype is Ptr_1;
  pragma Asynchronous (Second_Subtype);                            -- ERROR:
                        -- pragma Asynchronous only allowed on first subtype
end BXE4001_Types;
