-- CDD2001.A
--
--                             Grant of Unlimited Rights
--
--     The Ada Conformity Assessment Authority (ACAA) holds unlimited
--     rights in the software and documentation contained herein. Unlimited
--     rights are the same as those granted by the U.S. Government for older
--     parts of the Ada Conformity Assessment Test Suite, and are defined
--     in DFAR 252.227-7013(a)(19). By making this public release, the ACAA
--     intends to confer upon all recipients unlimited rights equal to those
--     held by the ACAA. These rights include rights to use, duplicate,
--     release or disclose the released technical data and computer software
--     in whole or in part, in any manner and for any purpose whatsoever, and
--     to have or permit others to do so.
--
--                                    DISCLAIMER
--
--     ALL MATERIALS OR INFORMATION HEREIN RELEASED, MADE AVAILABLE OR
--     DISCLOSED ARE AS IS.  THE GOVERNMENT MAKES NO EXPRESS OR IMPLIED
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--*
--
-- OBJECTIVE:
--    Check that the default implementation of Read and Input raise End_Error
--    if the end of stream is reached before the reading of a value is
--    completed.  (Defect Report 8652/0045,
--    Technical Corrigendum 13.13.2(35.1/1)).
--
-- CHANGE HISTORY:
--    12 FEB 2001   PHL   Initial version.
--    29 JUN 2001   RLB   Reformatted for ACATS.
--
--!

with Ada.Streams;
use Ada.Streams;
package CDD2001_0 is

    type My_Stream (Size : Stream_Element_Count) is new Root_Stream_Type with
	record
	    First : Stream_Element_Offset := 1;
	    Last : Stream_Element_Offset := 0;
	    Contents : Stream_Element_Array (1 .. Size);
	end record;

    procedure Clear (Stream : in out My_Stream);

    procedure Read (Stream : in out My_Stream;
		    Item : out Stream_Element_Array;
		    Last : out Stream_Element_Offset);

    procedure Write (Stream : in out My_Stream; Item : in Stream_Element_Array);

end CDD2001_0;
