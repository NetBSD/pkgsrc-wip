# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/10/28 17:37:04 jihbed Exp $

BUILDLINK_TREE+=	libecc

.if !defined(LIBECC_BUILDLINK3_MK)
LIBECC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libecc+=	libecc>=0.14.0
BUILDLINK_PKGSRCDIR.libecc?=	../../wip/libecc

.include "../../devel/gmp/buildlink3.mk"
.endif	# LIBECC_BUILDLINK3_MK

BUILDLINK_TREE+=	-libecc
