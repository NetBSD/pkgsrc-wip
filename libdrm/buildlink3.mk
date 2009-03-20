# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:43:44 jsonn Exp $

BUILDLINK_TREE+=	libdrm

.if !defined(LIBDRM_BUILDLINK3_MK)
LIBDRM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdrm+=	libdrm>=2.4.1
BUILDLINK_PKGSRCDIR.libdrm?=	../../wip/libdrm
.endif # LIBDRM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdrm
