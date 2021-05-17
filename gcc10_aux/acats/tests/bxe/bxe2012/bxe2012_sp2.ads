

---------------------------------------------------------------------------

with Ada.Streams;
package BXE2012_SP2 is
-- This package should compile without error
  pragma Shared_Passive;
  type Good_Private_Type is limited private;

  procedure Write (
     Stream : access Ada.Streams.Root_Stream_Type'Class;
     Item   : in Good_Private_Type);
  for Good_Private_Type'WRITE use Write;

  procedure Read (
     Stream : access Ada.Streams.Root_Stream_Type'Class;
     Item   : out Good_Private_Type);
  for Good_Private_Type'READ use Read;

  type Bad_Private_Type is limited private;
        -- This type does not have
        -- specified READ and WRITE attributes.

private
  type Good_Private_Type is tagged limited
    record
      F : Integer;
    end record;

  type Bad_Private_Type is tagged limited
    record
      F : Integer;
    end record;

end BXE2012_SP2;
