# $NetBSD: hacks.mk,v 1.1 2013/04/21 14:53:36 makoto Exp $

.include "../../mk/bsd.prefs.mk"

# Workaround for PR 45266
.if ${OPSYS} == "NetBSD"
BUILDLINK_INCDIRS.heimdal=	# empty
.endif
