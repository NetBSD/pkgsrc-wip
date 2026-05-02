# $NetBSD: buildlink3.mk,v 1.5 2025/10/23 20:38:50 wiz Exp $

BUILDLINK_TREE+=	libslirp

.if !defined(LIBSLIRP_BUILDLINK3_MK)
LIBSLIRP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libslirp+=	libslirp>=4.3.1 # needs update?
BUILDLINK_ABI_DEPENDS.libslirp?=	libslirp>=4.9.1
BUILDLINK_PKGSRCDIR.libslirp?=		../../wip/libslirp491

.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBSLIRP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libslirp
