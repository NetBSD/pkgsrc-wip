# $NetBSD: buildlink3.mk,v 1.1 2011/08/02 22:19:13 khorben Exp $

BUILDLINK_TREE+=	libosmocore

.if !defined(LIBOSMOCORE_BUILDLINK3_MK)
LIBOSMOCORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libosmocore+=	libosmocore>=1.0.1
BUILDLINK_PKGSRCDIR.libosmocore?=	../../wip/libosmocore

.include "../../devel/talloc/buildlink3.mk"

.endif	# LIBOSMOCORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libosmocore
