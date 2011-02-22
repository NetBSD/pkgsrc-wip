(DEFSYSTEM "cl-unicode"
    :DEPENDS-ON (:cl-ppcre :flexi-streams)
    :CLASS ASDF::PREBUILT-SYSTEM
    :LIB "SYS:cl-unicode"
    :COMPONENTS ((:COMPILED-FILE "cl-unicode")))
