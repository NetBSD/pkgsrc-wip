(DEFPACKAGE :trivial-gray-streams-system (:use :cl :asdf))
(IN-PACKAGE :trivial-gray-streams-system)

(DEFSYSTEM "trivial-gray-streams"
    :CLASS ASDF::PREBUILT-SYSTEM
    :LIB "SYS:trivial-gray-streams"
    :COMPONENTS ((:COMPILED-FILE "trivial-gray-streams")))
