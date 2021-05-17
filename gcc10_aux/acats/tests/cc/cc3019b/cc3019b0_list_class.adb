     
PACKAGE BODY CC3019B0_LIST_CLASS IS
     
     PROCEDURE ADD    (THIS_ELEMENT        : IN OUT ELEMENT ;
                       TO_THIS_LIST        : IN OUT LIST) IS
                           
     BEGIN  -- ADD
          
          IF TO_THIS_LIST.LENGTH >= 10 THEN
               RAISE OVERFLOW ;
          ELSE
               TO_THIS_LIST.LENGTH := TO_THIS_LIST.LENGTH + 1 ;
               ASSIGN (
                    SOURCE      => THIS_ELEMENT,
                    DESTINATION =>
                        TO_THIS_LIST.ACTUAL_LIST (TO_THIS_LIST.LENGTH));
          END IF ;
          
     END ADD ;
                            
     PROCEDURE DELETE (THIS_ELEMENT      : IN OUT ELEMENT ;
                       FROM_THIS_LIST    : IN OUT LIST) IS
                               
     BEGIN  -- DELETE
          
          IF FROM_THIS_LIST.LENGTH <= 0 THEN
               RAISE UNDERFLOW ;
          ELSE
               ASSIGN (
                    SOURCE      => 
                      FROM_THIS_LIST.ACTUAL_LIST(FROM_THIS_LIST.LENGTH),
                    DESTINATION => THIS_ELEMENT) ;
               FROM_THIS_LIST.LENGTH := FROM_THIS_LIST.LENGTH - 1 ;
          END IF ;
          
     END DELETE ;
                            
     PROCEDURE COPY   (THIS_LIST           : IN OUT LIST ;
                           TO_THIS_LIST        : IN OUT LIST) IS
                               
     BEGIN  -- COPY
          
          TO_THIS_LIST.LENGTH := THIS_LIST.LENGTH ;
          FOR INDEX IN TO_THIS_LIST.ACTUAL_LIST'RANGE LOOP
               ASSIGN (
                    SOURCE      => THIS_LIST.ACTUAL_LIST (INDEX),
                    DESTINATION => TO_THIS_LIST.ACTUAL_LIST (INDEX)) ;
          END LOOP ;
               
     END COPY ;
     
     PROCEDURE CLEAR  (THIS_LIST          : IN OUT LIST) IS
     
     BEGIN  -- CLEAR
     
          THIS_LIST.LENGTH := 0 ;
          
     END CLEAR ;
                               
     PROCEDURE ITERATE (OVER_THIS_LIST    : IN LIST) IS
          
          CONTINUE : BOOLEAN := TRUE ;
          FINISHED : NATURAL := 0 ;
               
     BEGIN  -- ITERATE
          
          WHILE (CONTINUE = TRUE) AND (FINISHED < OVER_THIS_LIST.LENGTH)
               LOOP
                    FINISHED := FINISHED + 1 ;
                    PROCESS (THIS_ELEMENT =>
                                 OVER_THIS_LIST.ACTUAL_LIST (FINISHED),
                              CONTINUE     => CONTINUE) ;
               END LOOP ;
                    
     END ITERATE ;
               
     FUNCTION NUMBER_OF_ELEMENTS (IN_THIS_LIST : IN LIST)
          RETURN NATURAL IS
          
     BEGIN  -- NUMBER_OF_ELEMENTS
          
          RETURN IN_THIS_LIST.LENGTH ;
               
     END NUMBER_OF_ELEMENTS ;
          
     FUNCTION "=" (LEFT  : IN LIST ;
                   RIGHT : IN LIST) RETURN BOOLEAN IS
                      
          RESULT : BOOLEAN := TRUE ;
          INDEX  : NATURAL := 0 ;
          
     BEGIN  -- "="
     
          IF LEFT.LENGTH /= RIGHT.LENGTH THEN
               RESULT := FALSE ;
          ELSE
               WHILE (INDEX < LEFT.LENGTH) AND RESULT LOOP
                    INDEX := INDEX + 1 ;
                    IF LEFT.ACTUAL_LIST (INDEX) /=
                       RIGHT.ACTUAL_LIST (INDEX) THEN
                         RESULT := FALSE ;
                    END IF ;
               END LOOP ;
          END IF ;
          
          RETURN RESULT ;
          
     END "=" ;
               
END CC3019B0_LIST_CLASS ;          
