# $NetBSD: buildlink2.mk,v 1.2 2003/12/30 22:59:09 cjep Exp $
#
# This Makefile fragment is included by packages that use glkterm.
#

.if !defined(GLKTERM_BUILDLINK2_MK)
GLKTERM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			glkterm
BUILDLINK_DEPENDS.glkterm?=		glkterm>=0.7.8
BUILDLINK_PKGSRCDIR.glkterm?=		../../wip/glkterm

EVAL_PREFIX+=	BUILDLINK_PREFIX.glkterm=glkterm
BUILDLINK_PREFIX.glkterm_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.glkterm+=	include/glkterm/*
BUILDLINK_FILES.glkterm+=	lib/libglkterm.*

BUILDLINK_CPPFLAGS.glkterm= \
	-I${BUILDLINK_PREFIX.glkterm}/include/glkterm

CPPFLAGS+=      ${BUILDLINK_CPPFLAGS.glkterm}

# uses halfkey (present since 1.6M)
INCOMPAT_CURSES+=	NetBSD-1.4[Y-Z]* NetBSD-1.5* NetBSD-1.6-* NetBSD-1.6.*
INCOMPAT_CURSES+=	NetBSD-1.6[A-L]*

.include "../../devel/ncurses/buildlink2.mk"

BUILDLINK_TARGETS+=	glkterm-buildlink
BUILDLINK_TARGETS+=     glkterm-glk

glkterm-buildlink: _BUILDLINK_USE

glkterm-glk:
	${_PKG_SILENT}${_PKG_DEBUG}                                     \
	if [ ! -f ${BUILDLINK_DIR}/include/glk ]; then             \
		${ECHO_BUILDLINK_MSG} "Linking glkterm to glk in ${BUILDLINK_DIR}."; \
		${LN} -s ${BUILDLINK_DIR}/include/glkterm ${BUILDLINK_DIR}/include/glk; \
	fi
	if [ ! -f ${BUILDLINK_DIR}/include/glk/Make.glk ]; then             \
		${ECHO_BUILDLINK_MSG} "Linking Make.glkterm to Make.glk in ${BUILDLINK_DIR}."; \
		${LN} -s ${BUILDLINK_DIR}/include/glk/Make.glkterm ${BUILDLINK_DIR}/include/glk/Make.glk; \
	fi
	if [ ! -f ${BUILDLINK_DIR}/lib/libglk.so ]; then             \
		${ECHO_BUILDLINK_MSG} "Linking libglkterm.a to libglk.so in ${BUILDLINK_DIR}."; \
		${LN} -s ${BUILDLINK_DIR}/lib/libglkterm.a ${BUILDLINK_DIR}/lib/libglk.so; \
	fi

.endif	# GLKTERM_BUILDLINK2_MK
