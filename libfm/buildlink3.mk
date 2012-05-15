# $NetBSD: buildlink3.mk,v 1.2 2012/05/15 03:23:27 jeremy-c-reed Exp $

BUILDLINK_TREE+=	libfm

.if !defined(LIBFM_BUILDLINK3_MK)
LIBFM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfm+=	libfm>=0.1.15
BUILDLINK_PKGSRCDIR.libfm?=	../../wip/libfm

#.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBFM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfm
