# $NetBSD: buildlink3.mk,v 1.4 2015/04/11 17:51:28 krytarowski Exp $

BUILDLINK_TREE+=	libfm

.if !defined(LIBFM_BUILDLINK3_MK)
LIBFM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfm+=	libfm>=1.2.3
BUILDLINK_PKGSRCDIR.libfm?=	../../wip/libfm

#.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBFM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfm
