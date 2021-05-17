-- REPORT.A
--
--                             Grant of Unlimited Rights
--
--     Under contracts F33600-87-D-0337, F33600-84-D-0280, MDA903-79-C-0687,
--     F08630-91-C-0015, and DCA100-97-D-0025, the U.S. Government obtained
--     unlimited rights in the software and documentation contained herein.
--     Unlimited rights are defined in DFAR 252.227-7013(a)(19).  By making
--     this public release, the Government intends to confer upon all
--     recipients unlimited rights  Equal to those held by the Government.
--     These rights include rights to use, duplicate, release or disclose the
--     released technical data and computer software in whole or in part, in
--     any manner and for any purpose whatsoever, and to have or permit others
--     to do so.
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
-- PURPOSE:
--      This Report package provides the mechanism for reporting the
--      Pass/Fail/Not-Applicable results of executable (Classes A, C,
--      D, E, and L) tests.

--      It also provides the mechanism for guaranteeing that certain
--      values become dynamic (not known at compile-time).

--      This version can write an event trace file in the format required
--      by the ACATS grading tools. Writing the event trace file requires
--      that text files can be created and appended to. If that is not true
--      for your target, set Generate_Event_Trace_File to False.

-- CHANGE HISTORY:
--      DCB 04/27/80
--      JRK 6/10/80
--      JRK 11/12/80
--      JRK 8/6/81
--      JRK 10/27/82
--      JRK 6/1/84
--      JRK 11/18/85  Added pragma Elaborate.
--      PWB 07/29/87  Added Status Action_Required and
--                    procedure Special_Action.
--      TBN 08/20/87  Added function Legal_File_Name.
--      BCB 05/17/90  Modified to allow output to Direct_IO file.
--                    Added Time-Stamp.
--      LDC 05/17/90  Removed output to Direct_IO file.
--      WMC 08/11/92  Updated ACVC version string to "9X BASIC".
--      DTN 07/05/92  Updated ACVC version string to
--                    "ACVC 2.0 JULY 6 1993 DRAFT".
--      WMC 01/24/94  Modified Legal_File_Name to allow five possible
--                    file names (increated range of type file_name to 1..5).
--      WMC 11/06/94  Updated ACVC version string to
--                    "ACVC 2.0 NOVEMBER 6 1994 DRAFT".
--      DTN 12/04/94  Updated ACVC version string to
--                    "ACVC 2.0".
--      KAS 06/19/95  Added function Ident_Wide_Char.
--      KAS 06/19/95  Added function Ident_Wide_Str.
--      DTN 11/21/95  Updated ACVC version string to "ACVC 2.0.1".
--      DTN 12/14/95  Updated ACVC version string to "ACVC 2.1".
--      EDS 12/17/97  Updated ACVC version string to "2.2".
--      RLB  3/16/00  Updated ACATS version string to "2.3".
--                    Changed various strings to read "ACATS".
--      RLB  3/22/01  Updated ACATS version string to "2.4".
--      RLB  3/29/02  Updated ACATS version string to "2.5".
--      RLB  3/06/07  Updated ACATS version string to "2.6".
--      RLB  3/22/07  Updated ACATS version string to "3.0".
--      RLB  1/24/14  Updated ACATS version string to "3.1".
--      RLB  2/28/14  Updated ACATS version string to "4.0".
--      RLB  2/29/16  Added optional .CSV event trace file.
--                    Converted file to modern format, uses Ada 2012 unit
--                    names. Note: The messages were left in all UPPER CASE
--                    in order to avoid breaking existing tools.
--      RLB  3/24/16  Moved the event trace Boolean to the specification
--                    so it can be used by a future CZ test.
--      RLB  4/27/16  Updated ACATS version string to "4.1".
--

package Report is

     subtype File_Num is Integer range 1..5;

  -- The Report routines.

     procedure Test           -- This routine must be invoked at the start of
                              -- a test, before any of the other report
                              -- routines are invoked. It save the test
                              -- name and outputs the name and description.
        ( Name : String;      -- Test Name, e.g., "C23001A-AB".
          Descr : String      -- Brief description og test, e.g.,
                              -- "Upper/lower case equivalence in " &
                              -- "identifiers".
        );

     procedure Failed         -- Output a Failure message. Should be invoked
                              -- separately to report the failure of each
                              -- subtest within a test.
        ( Descr : String      -- Brief description of what failed.
                              -- Should be phrased as:
                              -- "(Failed because) ...reason...".
        );

     procedure Not_Applicable -- Output a Not-Applicable message.
                              -- Should be invoked separately to report the
                              -- non-applicability of each subtest within a
                              -- test.
        ( Descr : String      -- Brief description of what is
                              -- Not-Applicable. Should be phrased as:
                              -- "(Not-Applicable because)...reason...".
        );

     procedure Special_Action -- Output a message describing special actions to
                              -- be taken. Should be invoked separately to give
                              -- each special action.
        ( Descr : String      -- Brief description of action to be taken.
        );

     procedure Comment        -- Output a Comment message.
        ( Descr : String      -- The message.
        );

     procedure Result;        -- This routine must be invoked at the end of a
                              -- test. It outputs a message indicating whether
                              -- the test as a whole has passed, failed, is
                              -- Not-Applicable, or has tentatively passed
                              -- pending special actions.

  -- The dynamic value routines.

     -- Even with static arguments, these functions will have dynamic
     -- results.

     function Ident_Int       -- An identity function for type Integer.
        ( X : Integer         -- The argument.
        ) return Integer;     -- X.

     function Ident_Char      -- An identity function for type
                              -- Character.
        ( X : Character       -- The argument.
        ) return Character;   -- X.

     function Ident_Wide_Char -- An identity function for type
                              -- Wide_Character.
        ( X : Wide_Character  -- The argument.
        ) return Wide_Character; -- X.

     function Ident_Bool      -- An identity function for type Boolean.
        ( X : Boolean         -- The argument.
        ) return Boolean;     -- X.

     function Ident_Str       -- An identity function for type String.
        ( X : String          -- The argument.
        ) return String;      -- X.

     function Ident_Wide_Str  -- An identity function for type Wide_String.
        ( X : Wide_String     -- The argument.
        ) return Wide_String; -- X.

     function Equal           -- A recursive Equality function for type
                              -- Integer.
        ( X, Y : Integer      -- The arguments.
        ) return Boolean;     -- X = Y.

-- Other utility routines.

     function Legal_File_Name -- A function to generate legal external file
                              -- names.
        ( X : File_Num := 1;  -- Determines first character of name.
          Nam : String := ""  -- Determines rest of name.
        ) return String;      -- The generated name.

     function Time_Stamp      -- A function to generate the time and date to
                              -- place in the output of an ACATS test.
          return String;      -- The time and date.

-- Event trace setting.

     Generate_Event_Trace_File :
                          constant Boolean := False;
          --                                  ^^^^^ --- MODIFY HERE AS NEEDED
          -- Set to True to generate an event trace file (use with an
          -- implementation that provides a compilation option to produce
          -- an event trace file), and False to not generate such a file.

end Report;
