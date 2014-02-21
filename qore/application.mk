# $NetBSD: application.mk,v 1.1 2014/02/21 20:38:00 nros Exp $
#
# Replace the #! interpreter for Qore scripts.
#
# This mk fragment should be included in all Qore packages that
# install executable Qore scripts.
#
# Package-settable variables:
#
# REPLACE_QORE
#	A list of Qore scripts to be installed, relative to ${WRKSRC}.
#
#
# Keywords: python
#

.if defined(REPLACE_QORE)
REPLACE_INTERPRETER+=	qore
REPLACE.qore.old=	.*qore[^ ]*
REPLACE.qore.new=	${PREFIX}/bin/qore
REPLACE_FILES.qore=	 ${REPLACE_QORE}
.endif
