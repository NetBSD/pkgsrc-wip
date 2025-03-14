# $NetBSD: interpreter.mk,v 1.1 2025/03/08 11:49:48 scole Exp $
#
# Package-settable variables:
#
# REPLACE_WISH
#	THe list of files whose interpreter will be corrected.
#
# See also:
#	replace-interpreter

.if !defined(TK_INTERPRETER_MK)
TK_INTERPRETER_MK=	# defined

REPLACE_INTERPRETER+=	wish
REPLACE.wish.old=	.*/wish
# xxx
#REPLACE.wish.new=	${LOCALBASE}/bin/wish
REPLACE.wish.new=	${PREFIX}/bin/wish
REPLACE_FILES.wish=	${REPLACE_WISH}

.endif
