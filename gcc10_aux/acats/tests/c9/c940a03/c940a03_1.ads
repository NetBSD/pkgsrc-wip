  --Resource_Pkg

--======================================--
-- no body for C940A3_0
--======================================--

with F940A00;     -- Interlock_Foundation
with C940A03_0;   -- Resource_Pkg;

package C940A03_1 is
     -- Semaphores

  -- Models a counting semaphore that will allow up to a specific 
  -- number of logins
  -- Users (tasks) request a login slot by calling the Request_Login
  -- entry and logout by calling the Release_Login procedure

  Max_Logins : constant Integer := 2;
  

  type Key_Type is range 0..100;
                                      -- When a user requests a login, an
                                      -- identifying key will be returned
  Init_Key : constant Key_Type := 0;

  type Login_Record_Type is new C940A03_0.Resource_Type with record
    Key  : Key_Type := Init_Key;
  end record;


  protected type Login_Semaphore_Type (Resources_Available : Integer :=1) is

    entry     Request_Login   (Resource_Key : in out Login_Record_Type);
    procedure Release_Login;
    function  Available return Integer;  -- how many logins are available?
  private
    Logins_Avail : Integer  := Resources_Available;
    Next_Key     : Key_Type := Init_Key;

  end Login_Semaphore_Type;

  Login_Semaphore      : Login_Semaphore_Type (Max_Logins);

  --====== machinery for the test, not the model =====--
  TC_Control_Message : F940A00.Interlock_Type;    
  function TC_Key_Val (Login_Rec : Login_Record_Type) return Integer;


end C940A03_1;
