


with Ada.Streams.Stream_IO;                                          -- OK.
with Ada.Stream_Support;                                             -- ERROR:
                                         -- Package not in Predefined Library.

procedure BXAC005 is
begin
   null;
end BXAC005;
