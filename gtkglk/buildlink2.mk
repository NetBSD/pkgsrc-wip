# $NetBSD: buildlink2.mk,v 1.3 2003/10/21 11:59:17 dillo Exp $
#
# This Makefile fragment is included by packages that use gtkglk.
#

.if !defined(GTKGLK_BUILDLINK2_MK)
GTKGLK_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gtkglk
BUILDLINK_DEPENDS.gtkglk?=		gtkglk>=0.2
BUILDLINK_PKGSRCDIR.gtkglk?=		../../wip/gtkglk

EVAL_PREFIX+=	BUILDLINK_PREFIX.gtkglk=gtkglk
BUILDLINK_PREFIX.gtkglk_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gtkglk+=	include/gtkglk/*
BUILDLINK_FILES.gtkglk+=	lib/libgtkglk.*

BUILDLINK_CPPFLAGS.gtkglk= \
	-I${BUILDLINK_PREFIX.gtkglk}/include/gtkglk

CPPFLAGS+=      ${BUILDLINK_CPPFLAGS.gtkglk}

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

BUILDLINK_TARGETS+=	gtkglk-buildlink
BUILDLINK_TARGETS+=     gtkglk-glk

gtkglk-buildlink: _BUILDLINK_USE

gtkglk-glk:
	${_PKG_SILENT}${_PKG_DEBUG}                                     \
	if [ ! -f ${BUILDLINK_DIR}/include/glk ]; then             \
		${ECHO_BUILDLINK_MSG} "Linking gtkglk to glk in ${BUILDLINK_DIR}."; \
		${LN} -s ${BUILDLINK_DIR}/include/gtkglk ${BUILDLINK_DIR}/include/glk; \
	fi
	if [ ! -f ${BUILDLINK_DIR}/include/glk/Make.glk ]; then             \
		${ECHO_BUILDLINK_MSG} "Linking Make.gtkglk to Make.glk in ${BUILDLINK_DIR}."; \
		${LN} -s ${BUILDLINK_DIR}/include/glk/Make.gtkglk ${BUILDLINK_DIR}/include/glk/Make.glk; \
	fi
	if [ ! -f ${BUILDLINK_DIR}/lib/libglk.so ]; then             \
		${ECHO_BUILDLINK_MSG} "Linking libgtkglk.so to libglk.so in ${BUILDLINK_DIR}."; \
		${LN} -s ${BUILDLINK_DIR}/lib/libgtkglk.so ${BUILDLINK_DIR}/lib/libglk.so; \
	fi


.endif	# GTKGLK_BUILDLINK2_MK
