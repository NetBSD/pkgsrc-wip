# $NetBSD: buildlink3.mk,v 1.2 2005/03/02 17:10:00 dillo Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GLKTERM_BUILDLINK3_MK:=	${GLKTERM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	glkterm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nglkterm}
BUILDLINK_PACKAGES+=	glkterm

.if !empty(GLKTERM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.glkterm+=	glkterm>=0.7.8
BUILDLINK_PKGSRCDIR.glkterm?=	../../wip/glkterm
#BUILDLINK_DEPMETHOD.glkterm?=	build

BUILDLINK_TRANSFORM+=	l:glk:glkterm
BUILDLINK_TARGETS+=	buildlink-glkterm-hook

buildlink-glkterm-hook:
	${LN} -s glkterm ${BUILDLINK_DIR}/include/glk
	${LN} -s Make.glkterm ${BUILDLINK_DIR}/include/glk/Make.glk
.endif	# GLKTERM_BUILDLINK3_MK

# uses halfkey (present since 1.6M)
INCOMPAT_CURSES+=       NetBSD-1.4[Y-Z]* NetBSD-1.5* NetBSD-1.6-* NetBSD-1.6.*
INCOMPAT_CURSES+=       NetBSD-1.6[A-L]*

.include "../../devel/ncurses/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
