
PACKAGE BODY CC3019C1_NESTED_GENERICS IS

     PROCEDURE COPY (SOURCE        : IN OUT NESTED_GENERICS_TYPE ;
                     DESTINATION   : IN OUT NESTED_GENERICS_TYPE) IS

     BEGIN  -- COPY

          ASSIGN (SOURCE        => SOURCE.FIRST,
                  DESTINATION   => DESTINATION.FIRST) ;

          DESTINATION.SECOND := SOURCE.SECOND ;

     END COPY ;

     PROCEDURE SET_ELEMENT
          (FOR_THIS_NGT_OBJECT : IN OUT NESTED_GENERICS_TYPE ;
          TO_THIS_ELEMENT     : IN OUT ELEMENT) IS

     BEGIN  -- SET_ELEMENT

          ASSIGN (SOURCE        => TO_THIS_ELEMENT,
                  DESTINATION   => FOR_THIS_NGT_OBJECT.FIRST) ;

     END SET_ELEMENT ;

     PROCEDURE SET_NUMBER
          (FOR_THIS_NGT_OBJECT : IN OUT NESTED_GENERICS_TYPE ;
          TO_THIS_NUMBER      : IN NATURAL) IS

     BEGIN  -- SET_NUMBER

          FOR_THIS_NGT_OBJECT.SECOND := TO_THIS_NUMBER ;

     END SET_NUMBER ;

     FUNCTION "=" (LEFT  : IN NESTED_GENERICS_TYPE ;
                   RIGHT : IN NESTED_GENERICS_TYPE) RETURN BOOLEAN IS

     BEGIN  -- "="

          IF (LEFT.FIRST = RIGHT.FIRST) AND
             (LEFT.SECOND = RIGHT.SECOND) THEN
                       RETURN TRUE ;
          ELSE
                    RETURN FALSE ;
          END IF ;

     END "=" ;

     FUNCTION ELEMENT_OF (THIS_NGT_OBJECT    : IN NESTED_GENERICS_TYPE)
          RETURN ELEMENT IS

     BEGIN  -- ELEMENT_OF

          RETURN THIS_NGT_OBJECT.FIRST ;

     END ELEMENT_OF ;

     FUNCTION NUMBER_OF (THIS_NGT_OBJECT    : IN NESTED_GENERICS_TYPE)
          RETURN NATURAL IS

     BEGIN  -- NUMBER_OF

          RETURN THIS_NGT_OBJECT.SECOND ;

     END NUMBER_OF ;

     PACKAGE BODY GENERIC_TASK IS

          TASK BODY PROTECTED_AREA IS

               LOCAL_STORE : ELEMENT ;

          BEGIN  -- PROTECTED_AREA

               LOOP
                    SELECT
                         ACCEPT STORE (ITEM    : IN OUT ELEMENT) DO
                              ASSIGN (SOURCE        => ITEM,
                                      DESTINATION   => LOCAL_STORE) ;
                         END STORE ;
                    OR
                         ACCEPT GET   (ITEM    : IN OUT ELEMENT) DO
                              ASSIGN (SOURCE        => LOCAL_STORE,
                                      DESTINATION   => ITEM) ;
                         END GET ;
                    OR
                         TERMINATE ;
                    END SELECT ;
               END LOOP ;

          END PROTECTED_AREA ;

     END GENERIC_TASK ;

     PACKAGE BODY STACK_CLASS IS

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
                    THIS_ELEMENT     => THIS_ELEMENT,
                    FROM_THIS_LIST   =>
                        NEW_LIST_CLASS.LIST (OFF_THIS_STACK)) ;

          EXCEPTION

                    WHEN NEW_LIST_CLASS.UNDERFLOW => RAISE UNDERFLOW ;

          END POP ;

          PROCEDURE COPY  (THIS_STACK       : IN OUT STACK ;
                           TO_THIS_STACK    : IN OUT STACK) IS

          BEGIN  -- COPY

              NEW_LIST_CLASS.COPY (
                    THIS_LIST    => NEW_LIST_CLASS.LIST (THIS_STACK),
                    TO_THIS_LIST =>
                         NEW_LIST_CLASS.LIST (TO_THIS_STACK)) ;

          END COPY ;

          PROCEDURE CLEAR (THIS_STACK        : IN OUT STACK) IS

          BEGIN  -- CLEAR

               NEW_LIST_CLASS.CLEAR (NEW_LIST_CLASS.LIST (THIS_STACK)) ;

          END CLEAR ;

          PROCEDURE ITERATE (OVER_THIS_STACK  : IN STACK) IS

               PROCEDURE STACK_ITERATE IS NEW NEW_LIST_CLASS.ITERATE
                                        (PROCESS => PROCESS) ;

          BEGIN  -- ITERATE

               STACK_ITERATE (NEW_LIST_CLASS.LIST (OVER_THIS_STACK)) ;

          END ITERATE ;

          FUNCTION NUMBER_OF_ELEMENTS (ON_THIS_STACK    : IN STACK)
                    RETURN NATURAL IS

          BEGIN  -- NUMBER_OF_ELEMENTS

               RETURN NEW_LIST_CLASS.NUMBER_OF_ELEMENTS
                    (IN_THIS_LIST =>
                         NEW_LIST_CLASS.LIST (ON_THIS_STACK)) ;

          END NUMBER_OF_ELEMENTS ;

          FUNCTION "=" (LEFT  : IN STACK ;
                        RIGHT : IN STACK) RETURN BOOLEAN IS

          BEGIN  -- "="

               RETURN NEW_LIST_CLASS."=" (
                    LEFT  => NEW_LIST_CLASS.LIST (LEFT),
                   RIGHT => NEW_LIST_CLASS.LIST (RIGHT)) ;

          END "=" ;

     END STACK_CLASS ;

END CC3019C1_NESTED_GENERICS ;
