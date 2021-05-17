-- CXA9002.A
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
--      Check that the operations defined in the generic package 
--      Ada.Storage_IO provide the ability to store and retrieve objects 
--      of tagged types from in-memory buffers.
--
-- TEST DESCRIPTION:
--      The following scenario demonstrates how objects of a tagged type, 
--      extended types, and twice extended types can be written/read
--      to/from Direct_IO files. The Storage_IO subprograms, Read and Write, 
--      demonstrated in this scenario, perform tag "fixing" prior to/following
--      transfer to the Direct_IO files.
--      This method is especially important for those implementations that 
--      represent tags as pointers, or for cases where the tagged objects
--      are read in by a program other than the one that wrote them.  
--
--      In this small example, we have attempted to simulate the situation 
--      where two independent programs are using a series of Direct_IO files,
--      one writing data to the files, and the second program reading the 
--      data from those files.  Two procedures are defined, the first
--      simulating the program responsible for writing, the second simulating 
--      a separate program opening and reading the data from the files.  
--      
--      The hierarchy of types used in this test can be displayed as follows:
--      
--                                Account_Type
--                                 /       \
--                                /         \
--                               /           \
--                  Cash_Account_Type       Investment_Account_Type
--                     /         \
--                    /           \
--                   /             \
--      Checking_Account_Type    Savings_Account_Type
--      
-- APPLICABILITY CRITERIA: 
--      Applicable to implementations capable of supporting external
--      Direct_IO files.
--
--       
-- CHANGE HISTORY:
--      06 Dec 94   SAIC    ACVC 2.0
--      08 Nov 95   SAIC    Corrected incorrect prefix of 'Tag for ACVC 2.0.1,
--                          and mode of files in Procedure Read_Data.
--                          Added verification of objects reconstructed from
--                          files.
--      27 Feb 97   PWB.CTA Allowed for non-support of some IO operations
--!

package CXA9002_0 is

   type Investment_Type is (Stocks, Bonds, Mutual_Funds);
   type Savings_Type    is (Standard, Business, Impound);

   type Account_Type is tagged 
      record
         Num : String (1..3);
      end record;

   type Cash_Account_Type is new Account_Type with
      record
         Years_As_Customer : Natural := 1;
      end record;

   type Investment_Account_Type is new Account_Type with
      record
         Investment_Vehicle : Investment_Type := Stocks;
      end record;

   type Checking_Account_Type is new Cash_Account_Type with
      record
         Checks_Per_Year  : Positive := 200;
         Interest_Bearing : Boolean  := False;
      end record;

   type Savings_Account_Type is new Cash_Account_Type with
      record
         Kind : Savings_Type := Standard;
      end record;

end CXA9002_0;
