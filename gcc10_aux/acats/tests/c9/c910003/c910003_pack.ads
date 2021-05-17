-- C910003.A
--
--                             Grant of Unlimited Rights
--
--     Under contracts F33600-87-D-0337, F33600-84-D-0280, MDA903-79-C-0687 and
--     F08630-91-C-0015, the U.S. Government obtained unlimited rights in the
--     software and documentation contained herein.  Unlimited rights are
--     defined in DFAR 252.227-7013(a)(19).  By making this public release,
--     the Government intends to confer upon all recipients unlimited rights
--     equal to those held by the Government.  These rights include rights to
--     use, duplicate, release or disclose the released technical data and
--     computer software in whole or in part, in any manner and for any purpose
--     whatsoever, and to have or permit others to do so.
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
--      Check that task discriminants that have an access subtype may be
--      dereferenced.
--
--      Note that discriminants in Ada 83 never can be dereferenced with
--      selection or indexing, as they cannot have an access type.
--
-- TEST DESCRIPTION:
--      A protected object is defined to create a simple buffer.
--      Two task types are defined, one to put values into the buffer,
--      and one to remove them. The tasks are passed a buffer object as
--      a discriminant with an access subtype. The producer task type includes
--      a discriminant to determine the values to product. The consumer task
--      type includes a value to save the results.
--      Two producer and one consumer tasks are declared, and the results
--      are checked.
--
-- CHANGE HISTORY:
--      10 Mar 99   RLB    Created test.
--
--!

package C910003_Pack is

    type Item_Type is range 1 .. 100; -- In a real application, this probably
                                      -- would be a record type.

    type Item_Array is array (Positive range <>) of Item_Type;

    protected type Buffer is
       entry Put (Item  : in Item_Type);
       entry Get (Item  : out Item_Type);
       function TC_Items_Buffered return Item_Array;
    private
       Saved_Item : Item_Type;
       Empty : Boolean := True;
       TC_Items : Item_Array (1 .. 10);
       TC_Last  : Natural := 0;
    end Buffer;

    type Buffer_Access_Type is access Buffer;

    PRODUCE_COUNT : constant := 2; -- Number of items to produce.

    task type Producer (Buffer_Access : Buffer_Access_Type;
                        Start_At : Item_Type);
        -- Produces PRODUCE_COUNT items. Starts when activated.

    type TC_Item_Array_Access_Type is access Item_Array (1 .. PRODUCE_COUNT*2);

    task type Consumer (Buffer_Access : Buffer_Access_Type;
                        Results : TC_Item_Array_Access_Type) is
        -- Stores PRODUCE_COUNT*2 items consumed in Results. Starts when
        -- activated.
        entry Wait_until_Done;
    end Consumer;

end C910003_Pack;
