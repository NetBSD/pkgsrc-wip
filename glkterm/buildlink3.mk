# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:43:41 jsonn Exp $

BUILDLINK_TREE+=	glkterm

BUILDLINK_API_DEPENDS.glkterm+=	glkterm>=0.7.8
BUILDLINK_PKGSRCDIR.glkterm?=	../../wip/glkterm
#BUILDLINK_DEPMETHOD.glkterm?=	build

BUILDLINK_TRANSFORM+=	l:glk:glkterm
BUILDLINK_TARGETS+=	buildlink-glkterm-hook

buildlink-glkterm-hook:
	${LN} -s glkterm ${BUILDLINK_DIR}/include/glk
	${LN} -s Make.glkterm ${BUILDLINK_DIR}/include/glk/Make.glk

# uses halfkey (present since 1.6M)
INCOMPAT_CURSES+=       NetBSD-1.4[Y-Z]* NetBSD-1.5* NetBSD-1.6-* NetBSD-1.6.*
INCOMPAT_CURSES+=       NetBSD-1.6[A-L]*

.include "../../devel/ncurses/buildlink3.mk"
.endif # GLKTERM_BUILDLINK3_MK

BUILDLINK_TREE+=	-glkterm
