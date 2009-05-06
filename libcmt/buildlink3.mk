# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/05/06 10:32:00 jihbed Exp $

BUILDLINK_TREE+=	libcmt

.if !defined(LIBCMT_BUILDLINK3_MK)
LIBCMT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcmt+=	libcmt>=0.1.0
BUILDLINK_PKGSRCDIR.libcmt?=	../../wip/libcmt

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBCMT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcmt
