-- C431001.A
--
--                             Grant of Unlimited Rights
--
--     Under contracts F33600-87-D-0337, F33600-84-D-0280, MDA903-79-C-0687,
--     F08630-91-C-0015, and DCA100-97-D-0025, the U.S. Government obtained 
--     unlimited rights in the software and documentation contained herein.
--     Unlimited rights are defined in DFAR 252.227-7013(a)(19).  By making 
--     this public release, the Government intends to confer upon all 
--     recipients unlimited rights  equal to those held by the Government.  
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
-- OBJECTIVE:
--      Check that a record aggregate can be given for a nonprivate,
--      nonlimited record extension and that the tag of the aggregate 
--      values are initialized to the tag of the record extension.
--
-- TEST DESCRIPTION:
--      From an initial parent tagged type, several type extensions
--      are declared. Each type extension adds components onto
--      the existing record structure.
--
--      In the main procedure, aggregates are declared in two ways.
--      In the declarative part, aggregates are used to supply
--      initial values for objects of specific types. In the executable
--      part, aggregates are used directly as actual parameters to
--      a class-wide formal parameter.
--
--      The abstraction is for a catalog of recordings. A recording
--      can be a CD or a record (vinyl). Additionally, a CD may also
--      be a CD-ROM, containing both music and data. This type is declared
--      as an extension to a type extension, to test that the inclusion
--      of record components is transitive across multiple extensions.
--
--      That the aggregate has the correct tag is verify by feeding
--      it to a dispatching operation and confirming that the
--      expected subprogram is called as a result. To accomplish this,
--      an enumeration type is declared with an enumeration literal
--      representing each of the declared types in the hierarchy. A value
--      of this type is passed as a parameter to the dispatching
--      operation which passes it along to the dispatched subprogram.
--      Each dispatched subprogram verifies that it received the
--      expected enumeration literal.
--
--      Not quite fitting the above abstraction are several test cases
--      for null records. These tests verify that the new syntax for
--      null record aggregates, (null record), is supported. A type is
--      declared which extends a null tagged type and adds components.
--      Aggregates of this type should include associations for the
--      components of the type extension only. Finally, a type is
--      declared that adds a null type extension onto a non-null tagged
--      type. The aggregate associations should remain the same.
--
--
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      19 Dec 94   SAIC    Removed RM references from objective text.
--
--!
--
package C431001_0 is

   -- Values of TC_Type_ID are passed through to dispatched subprogram
   -- calls so that it can be verified that the dispatching resulted in
   -- the expected call.
   type TC_Type_ID is (TC_Recording, TC_CD, TC_Vinyl, TC_CD_ROM);

   type Genre is (Classical, Country, Jazz, Rap, Rock, World);

   type Recording is tagged record
      Artist     : String (1..20);
      Category   : Genre;
      Length     : Duration;
      Selections : Positive;
   end record;

   function Summary (R       : in Recording;
                     TC_Type : in TC_Type_ID) return String;

   type Recording_Method is (Audio, Digital);
   type CD is new Recording with record
      Recorded : Recording_Method;
      Mastered : Recording_Method;
   end record;

   function Summary (Disc    : in CD;
                     TC_Type : in TC_Type_ID) return String;

   type Playing_Speed is (LP_33, Single_45, Old_78);
   type Vinyl is new Recording with record
      Speed : Playing_Speed;
   end record;

   function Summary (Album   : in Vinyl;
                     TC_Type : in TC_Type_ID)  return String;
                       

   type CD_ROM is new CD with record
      Storage : Positive;
   end record;

   function Summary (Disk    : in CD_ROM;
                     TC_Type : in TC_Type_ID)  return String;
                       
   function Catalog_Entry (R       : in Recording'Class;
                           TC_Type : in TC_Type_ID) return String;

   procedure Print (S : in String); -- provides somewhere for the
                                    -- results of Catalog_Entry to
                                    -- "go", so they don't get
                                    -- optimized away.

   -- The types and procedures declared below are not a continuation
   -- of the Recording abstraction. These types are intended to test
   -- support for null tagged types and type extensions. TC_Check mirrors
   -- the operation of function Summary, above. Similarly, TC_Dispatch
   -- mirrors the operation of Catalog_Entry.

   type TC_N_Type_ID is
      (TC_Null_Tagged, TC_Null_Extension,
       TC_Extension_Of_Null, TC_Null_Extension_Of_Nonnull);

   type Null_Tagged is tagged null record;
   procedure TC_Check (N       : in Null_Tagged;
                       TC_Type : in TC_N_Type_ID);

   type Null_Extension is new Null_Tagged with null record;
   procedure TC_Check (N       : in Null_Extension;
                       TC_Type : in TC_N_Type_ID);
   
   type Extension_Of_Null is new Null_Tagged with record
      New_Component1 : Boolean;
      New_Component2 : Natural;
   end record;
   procedure TC_Check (N       : in Extension_Of_Null;
                       TC_Type : in TC_N_Type_ID);

   type Null_Extension_Of_Nonnull is new Extension_Of_Null
      with null record;
   procedure TC_Check (N       : in Null_Extension_Of_Nonnull;
                       TC_Type : in TC_N_Type_ID);

   procedure TC_Dispatch (N       : in Null_Tagged'Class;
                          TC_Type : in TC_N_Type_ID);

end C431001_0;
