# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:44 jsonn Exp $

BUILDLINK_TREE+=	libdbi

.if !defined(LIBDBI_BUILDLINK3_MK)
LIBDBI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdbi+=	libdbi>=0.8.3
BUILDLINK_PKGSRCDIR.libdbi?=	../../wip/libdbi
.endif # LIBDBI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdbi
