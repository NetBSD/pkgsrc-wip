     
PACKAGE BODY CC3019B1_STACK_CLASS IS
     
     PROCEDURE PUSH (THIS_ELEMENT        : IN OUT ELEMENT ;
                     ON_TO_THIS_STACK    : IN OUT STACK) IS
                            
     BEGIN  -- PUSH
          
          NEW_LIST_CLASS.ADD (
               THIS_ELEMENT    => THIS_ELEMENT,
               TO_THIS_LIST    =>
                    NEW_LIST_CLASS.LIST (ON_TO_THIS_STACK)) ;
                                    
     EXCEPTION
     
          WHEN NEW_LIST_CLASS.OVERFLOW => RAISE OVERFLOW ;
                                    
     END PUSH ;
                            
     PROCEDURE POP  (THIS_ELEMENT        : IN OUT ELEMENT ;
                     OFF_THIS_STACK      : IN OUT STACK) IS
                            
     BEGIN  -- POP
          
          NEW_LIST_CLASS.DELETE (
               THIS_ELEMENT      => THIS_ELEMENT,
               FROM_THIS_LIST    =>
                         NEW_LIST_CLASS.LIST (OFF_THIS_STACK)) ;
                                       
     EXCEPTION
     
          WHEN NEW_LIST_CLASS.UNDERFLOW => RAISE UNDERFLOW ;
                                    
     END POP ;
                            
     PROCEDURE COPY  (THIS_STACK       : IN OUT STACK ;
                      TO_THIS_STACK    : IN OUT STACK) IS
                             
     BEGIN  -- COPY
          
          NEW_LIST_CLASS.COPY (
               THIS_LIST    => NEW_LIST_CLASS.LIST (THIS_STACK),
               TO_THIS_LIST => NEW_LIST_CLASS.LIST (TO_THIS_STACK)) ;
               
     END COPY ;
     
     PROCEDURE CLEAR (THIS_STACK        : IN OUT STACK) IS
     
     BEGIN  -- CLEAR
     
          NEW_LIST_CLASS.CLEAR (NEW_LIST_CLASS.LIST (THIS_STACK)) ;
          
     END CLEAR ;
     
     PROCEDURE ITERATE (OVER_THIS_STACK    : IN STACK) IS
     
          PROCEDURE STACK_ITERATE IS NEW NEW_LIST_CLASS.ITERATE
               (PROCESS => PROCESS) ;
               
     BEGIN  -- ITERATE
     
          STACK_ITERATE (NEW_LIST_CLASS.LIST (OVER_THIS_STACK)) ;
          
     END ITERATE ;

     FUNCTION NUMBER_OF_ELEMENTS (ON_THIS_STACK    : IN STACK)
          RETURN NATURAL IS
               
     BEGIN  -- NUMBER_OF_ELEMENTS
          
          RETURN NEW_LIST_CLASS.NUMBER_OF_ELEMENTS
               (IN_THIS_LIST => NEW_LIST_CLASS.LIST (ON_THIS_STACK)) ;
                    
     END NUMBER_OF_ELEMENTS ;
          
     FUNCTION "=" (LEFT  : IN STACK ;
                   RIGHT : IN STACK) RETURN BOOLEAN IS
     
     BEGIN  -- "="
     
          RETURN NEW_LIST_CLASS."=" (
               LEFT  => NEW_LIST_CLASS.LIST (LEFT),
               RIGHT => NEW_LIST_CLASS.LIST (RIGHT)) ;
                                       
     END "=" ;
               
END CC3019B1_STACK_CLASS ;
