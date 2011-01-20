# $NetBSD: buildlink3.mk,v 1.7 2011/01/20 08:20:23 obache Exp $

BUILDLINK_TREE+=	libupnp

.if !defined(LIBUPNP_BUILDLINK3_MK)
LIBUPNP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libupnp+=	libupnp>=1.4.6
BUILDLINK_ABI_DEPENDS.libupnp+=	libupnp>=1.6.10
BUILDLINK_PKGSRCDIR.libupnp?=	../../wip/libupnp
.endif # LIBUPNP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libupnp
