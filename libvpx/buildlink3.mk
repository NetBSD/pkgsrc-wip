# $NetBSD: buildlink3.mk,v 1.1 2010/10/12 18:18:34 rxg Exp $

BUILDLINK_TREE+=	libvpx

.if !defined(LIBVPX_BUILDLINK3_MK)
LIBVPX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvpx+=	libvpx>=0.9.2
BUILDLINK_ABI_DEPENDS.libvpx+=	libvpx>=0.9.2
BUILDLINK_PKGSRCDIR.libvpx?=	../../wip/libvpx

.include "../../mk/pthread.buildlink3.mk"
.endif # LIBVPX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvpx
