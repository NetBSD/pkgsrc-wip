# $NetBSD: buildlink3.mk,v 1.2 2011/07/25 17:53:17 jakllsch Exp $

BUILDLINK_TREE+=	compat32_lcms2

.if !defined(COMPAT32_LCMS2_BUILDLINK3_MK)
COMPAT32_LCMS2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.compat32_lcms2+=	compat32_lcms2>=2.2
BUILDLINK_PKGSRCDIR.compat32_lcms2?=	../../wip/lcms2-32
BUILDLINK_LIBDIRS.compat32_lcms2=	lib/32

BUILDLINK_TARGETS+=	buildlink-include-compat32_lcms2

.PHONY: buildlink-include-compat32_lcms2
buildlink-include-compat32_lcms2:
.for _h_ in lcms2.h
	${RUN}								\
	if [ ! -f ${BUILDLINK_DIR}/include/lcms2/${_h_} ]; then		\
		${MKDIR} ${BUILDLINK_DIR}/include/lcms2;		\
		${ECHO_BUILDLINK_MSG} "Linking lcms2/${_h_} to ${_h_} in ${BUILDLINK_DIR}/include"; \
		${LN} -s ${BUILDLINK_PREFIX.lcms2}/include/${_h_} ${BUILDLINK_DIR}/include/lcms2/${_h_}; \
	fi
.endfor
.endif # COMPAT32_LCMS2_BUILDLINK3_MK

BUILDLINK_TREE+=	-compat32_lcms2
