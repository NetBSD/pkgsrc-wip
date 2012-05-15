# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/05/15 03:20:47 jeremy-c-reed Exp $

BUILDLINK_TREE+=	libfm

.if !defined(LIBFM_BUILDLINK3_MK)
LIBFM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfm+=	libfm>=0.1.15
BUILDLINK_PKGSRCDIR.libfm?=	../../new/libfm

#.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBFM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfm
