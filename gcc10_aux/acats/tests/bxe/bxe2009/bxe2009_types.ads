-- BXE2009.A
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
--      Check that a declared Remote_Call_Interface library unit may not
--      contain:
--      variable declarations, task type declarations, protected type
--      declarations, nested generic declarations, limited types,
--      subprogram declarations to which a pragma inline applies,
--      non-preelaborable constant declarations,
--      a subprogram declaration with a formal parameter
--      of an access type, or a subprogram declaration with a formal
--      parameter of a type that does not support external streaming.
--
--      Check that a Remote_Call_Interface library unit may not depend
--      upon a normal package.
--
--      Check that a declared Remote_Call_Interface library unit may
--      contain:
--      subprogram declaration with a formal parameter of a limited type
--      with available READ and WRITE attributes.
--
--      Check that pragma Asynchronous can only be applied to RCI procedures
--      containing only mode in parameters.
--
-- TEST DESCRIPTION:
--      This test consists of three package specifications. The first two
--      packages are support packages providing declarations to the
--      third package. The third package is the package containing the
--      Remote_Call_Interface pragma. This package specification contains
--      declarations of one of each of the items that should not be
--      allowed and one of each of the specific items that should be
--      allowed.
--
-- APPLICABILITY CRITERIA:
--      This test applies only to implementations supporting the
--      Distribution Annex and the Remote_Call_Interface pragma.
--
--
-- CHANGE HISTORY:
--     11 MAR 95   SAIC    Initial version
--     20 DEC 95   SAIC    Added additional checks for E.2.3(8)
--     02 MAY 96   SAIC    Incorporated Reviewer comments.
--     02 DEC 97   EDS     Item parameter for write must be of a base subtype
--                         (13.3.2:36).
--     05 MAR 07   RLB     Corrected "normal" package, because the one
--                         chosen was changed to Remote_Types by Corrigendum 1.
--     21 MAR 08   RLB     Corrected Is_Limited_with_Attrs to actually have
--                         available stream attributes, and revised comments
--                         to reflect the current rules.
--
--!

with Ada.Streams;
package BXE2009_Types is
  pragma Remote_Types;
  -- this package should compile without error
  type Ok_Parameter_Type is private;
              -- This type will have access type components. 'read and
              -- 'write are provided for that access type so that this
              -- type can be used as the type of a parameter for a
              -- remote procedure call.
  type Is_Limited is limited private;
              -- This type does not have available 'read and 'write
              -- attributes.

  type Is_Limited_With_Attrs is limited private;
              -- This type does have available 'read and 'write attributes.

  procedure Write1 (
     Stream : access Ada.Streams.Root_Stream_Type'Class;
     Item   : in Is_Limited_With_Attrs);
  for Is_Limited_With_Attrs'WRITE use Write1;

  procedure Read1 (
     Stream : access Ada.Streams.Root_Stream_Type'Class;
     Item   : out Is_Limited_With_Attrs);
  for Is_Limited_With_Attrs'READ use Read1;

  function Non_Static_Function return Integer;
              -- Used where we need a value to be non-preelaborable.

private
  -- note that Is_Limited does not have 'Read and 'Write attributes
  type Is_Limited is range 5..7;

  type Is_Limited_With_Attrs is range 9..13;

  type Non_Remote_Access_Type_with_Attributes is access Integer;
  -- This access type has specified 'READ and 'WRITE attributes,
  -- so it supports external streaming.

  procedure Write (
     Stream : access Ada.Streams.Root_Stream_Type'Class;
     Item   : in Non_Remote_Access_Type_with_Attributes);
  for Non_Remote_Access_Type_with_Attributes'WRITE use Write;

  procedure Read (
     Stream : access Ada.Streams.Root_Stream_Type'Class;
     Item   : out Non_Remote_Access_Type_with_Attributes);
  for Non_Remote_Access_Type_with_Attributes'READ use Read;

  type Ok_Parameter_Type is
    record
      Component : Non_Remote_Access_Type_with_Attributes;
    end record;

end BXE2009_Types;
