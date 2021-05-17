
--=================================================================--

package body C940001_0 is
  protected body  Token_Mgr_Prot_Unit is
    entry Take (T : out Token_Type) when Token = true is
      begin                   -- Calling task will Take the token, so
        T := Token;           -- check first that token_mgr owns the
        Token := false;       -- token to give, then give it to caller
      end Take;

    entry Give (T : in out Token_Type)  when Token = false is
      begin                   -- Calling task will Give the token back,
        if T = true then      -- so first check that token_mgr does not
          Token := T;         -- own the token, then check that the task has
          T := false;         -- the token to give, then take it from the
        end if;               -- task
                              -- if caller does not own the token, then
      end Give;               -- it falls out of the entry body with no
  end Token_Mgr_Prot_Unit;    -- action

  function Init_Token return Token_Type is
    begin
      return false;
    end Init_Token;

  function Token_Value (T : Token_Type) return Boolean is
    begin
      return Boolean (T);
    end Token_Value;

end C940001_0;
