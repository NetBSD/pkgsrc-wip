# $NetBSD: buildlink3.mk,v 1.7 2020/10/25 12:43:45 nia Exp $

BUILDLINK_TREE+=	libvpx

.if !defined(LIBVPX_BUILDLINK3_MK)
LIBVPX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvpx+=	libvpx>=0.0.0
BUILDLINK_ABI_DEPENDS.libvpx+=	libvpx>=0.0.0
BUILDLINK_PKGSRCDIR.libvpx?=	../../wip/libvpx-git

GCC_REQD+=	4.8

.include "../../mk/pthread.buildlink3.mk"
.endif # LIBVPX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvpx
