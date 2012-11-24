# $NetBSD: buildlink3.mk,v 1.3 2012/11/24 02:25:05 jeremy-c-reed Exp $

BUILDLINK_TREE+=	libfm

.if !defined(LIBFM_BUILDLINK3_MK)
LIBFM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfm+=	libfm>=0.1.15
BUILDLINK_PKGSRCDIR.libfm?=	../../wip/libfm

#.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_TARGETS+=	buildlink-include-libfm

.PHONY: buildlink-include-libfm
buildlink-include-libfm:
	${LN} -s ${BUILDLINK_PREFIX.libfm}/include/libfm-1.0 ${BUILDLINK_DIR}/include/libfm

.endif	# LIBFM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfm
