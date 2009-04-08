# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/04/08 09:06:49 jihbed Exp $

BUILDLINK_TREE+=	libgdata

.if !defined(LIBGDATA_BUILDLINK3_MK)
LIBGDATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgdata+=	libgdata>=0.1.1
BUILDLINK_PKGSRCDIR.libgdata?=	../../wip/libgdata


.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"

.endif	# LIBGDATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgdata
