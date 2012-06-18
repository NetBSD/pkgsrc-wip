(DEFSYSTEM "cffi-grovel"
    :DEPENDS-ON (:CFFI :ALEXANDRIA)
    :CLASS ASDF::PREBUILT-SYSTEM
    :LIB "SYS:cffi-grovel"
    :COMPONENTS ((:COMPILED-FILE "cffi-grovel" :PATHNAME #P"SYS:cffi-grovel.fas")))
