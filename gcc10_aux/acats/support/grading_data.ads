-- GRD_DATA.A
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
--     DISCLOSED ARE AS IS. THE ACAA MAKES NO EXPRESS OR IMPLIED
--     WARRANTY AS TO ANY MATTER WHATSOEVER, INCLUDING THE CONDITIONS OF THE
--     SOFTWARE, DOCUMENTATION OR OTHER INFORMATION RELEASED, MADE AVAILABLE
--     OR DISCLOSED, OR THE OWNERSHIP, MERCHANTABILITY, OR FITNESS FOR A
--     PARTICULAR PURPOSE OF SAID MATERIAL.
--
--                                     Notice
--
--     The ACAA has created and maintains the Ada Conformity Assessment Test
--     Suite for the purpose of conformity assessments conducted in accordance
--     with the International Standard ISO/IEC 18009 - Ada: Conformity
--     assessment of a language processor. This test suite should not be used
--     to make claims of conformance unless used in accordance with
--     ISO/IEC 18009 and any applicable ACAA procedures.
--
--*
--
-- PURPOSE:
--      This package contains the event trace and test summary for
--      an execution of the test grading tool, including the code to
--      read those from files. (See GRADE.A for details of the tool.)
--
-- CHANGE HISTORY:
--      7 Mar 2016   RLB  Created package.
--     16 May 2016   RLB  Added Annex C Requirement.
--                        Added Manual_Grading_List.
--     30 Mar 2017   RLB  Increased the maximum values as they were not quite
--                        enough for the entire ACATS.
--     28 May 2019   RLB  Added code to make reading of the manual grading
--                        file more resilient to extra white space.
--     30 Dec 2019   RLB  Increased the maximum summary value as the ACATS
--                        has grown to exceed it.

with Trace, Test_Summary;
package Grading_Data is

   MAX_EVENTS : constant := 60_000;
      -- We have to use a constant as there is no reasonable way to find
      -- out how many records are in an event trace file short of reading
      -- the entire file an extra time.
   type Event_Count is range 0 .. MAX_EVENTS;
   subtype Event_Index is Event_Count range 1 .. MAX_EVENTS;

   type Event_Trace_Array is array (Event_Index range <>) of
      Trace.Event_Record;

   Event_Trace : Event_Trace_Array(Event_Index);
   Last_Event : Event_Count := 0;

   MAX_SUMMARY_ITEMS : constant := 40_000;
      -- We have to use a constant as there is no reasonable way to find
      -- out how many records are in a test summary file short of reading
      -- the entire file an extra time. This value is approximately enough
      -- to hold the entire ACATS.
   type Summary_Item_Count is range 0 .. MAX_SUMMARY_ITEMS;
   subtype Summary_Item_Index is Summary_Item_Count range
                                                      1 .. MAX_SUMMARY_ITEMS;

   type Summary_Item_Array is array (Summary_Item_Index range <>) of
      Test_Summary.Info_Record;

   Summary_of_Tests : Summary_Item_Array(Summary_Item_Index);
   Last_Summary_Item : Summary_Item_Count := 0;

   subtype Test_Range is Integer range 1 .. 7;
      -- The slice of a test name that reflects the name of the test.

   Format_Error : exception; -- Some problem with one of the files. See
      -- the exception message for details.

   procedure Put_Event_Line (Event : Event_Count);
      -- Write a line containing the event information for the given
      -- event index.

   procedure Read_Event_Trace (Trace_File_Name : in String);
      -- Read the event trace from the file named Trace_File_Name, putting
      -- the result into Event_Trace, with Last_Event set to the last event
      -- in the data.
      -- Propagates any I/O exceptions, as well as Format_Error if the
      -- data is malformatted.

   procedure Put_Summary_Item_Line (Item : Summary_Item_Count);
      -- Write a line containing the summary item information for the given
      -- summary item index.

   procedure Read_Summary_of_Tests (Summary_Item_Name : in String);
      -- Read the summary of tests to grade from the file named
      -- Summary_Item_Name, putting the result into Summary_of_Tests, with
      -- Last_Summary_Item set to the last summary item in the data.
      -- Propagates any I/O exceptions, as well as Format_Error if the
      -- data is malformatted.


   MAX_MANUAL_GRADING : constant := 5_000;
      -- We have to use a constant as there is no reasonable way to find
      -- out how many records are in a manual grading file short of reading
      -- the entire file an extra time.
   type Manual_Grading_Count is range 0 .. MAX_MANUAL_GRADING;
   subtype Manual_Grading_Index is Manual_Grading_Count range
                                                      1 .. MAX_MANUAL_GRADING;

   type Manual_Grading_Array is array (Manual_Grading_Index range <>) of
      Trace.Name_Subtype;

   Manual_Grading_List : Manual_Grading_Array(Manual_Grading_Index);
   Last_Manual_Grading : Manual_Grading_Count := 0;
      -- A list of tests that may require manual grading. Note that if the
      -- test passes the automatic grading, it will not be marked as needing
      -- manual grading even if it is on this list.

   procedure Read_Manual_Grading_List (Manual_Grading_Name : in String);
      -- Read the list of tests that may require manual grading from the file
      -- named Manual_Grading_Name, putting the result into Manual_Grading_List
      -- with Last_Manual_Grading set to the last manual grading item in the
      -- data. Propagates any I/O exceptions, as well as Format_Error if the
      -- data is malformatted.
      --
      -- The file is just a list of test names (7 characters each), with
      -- optional Ada comments and blank lines. Anything else is rejected.

   function Manual_Grading_Requested_for_Test
               (Source_Name : Trace.Name_Subtype) return Boolean;
      -- Returns True if the test in the source file Source_Name is
      -- included on the potentially manually graded tests list, and
      -- returns False otherwise.


      -- Notes: We considered using Ada.Containers.Vectors instead
      -- of a fixed array for each of these items, but doing that without
      -- depending on Ada 2012 features would make the code be hard to read.
      -- Additionally, we'd ideally, we'd like these tools to be compilable
      -- by an Ada95 ompiler. We won't quite reach that (we use the child
      -- packages of Ada.Calendar, Ada.Containers.Generic_Array_Sort, and the
      -- raise with string), but it still would be
      -- relatively easy to replace those with portable implementations
      -- of the packages and calls of Raise_Exception. (We didn't do that
      -- as reinventing the wheel and cutting readability didn't seem
      -- sensible, especially as these tools will be provided only for
      -- ACATS 4.1 and later.)

end Grading_Data;
