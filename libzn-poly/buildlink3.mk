# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/01/24 09:21:57 jihbed Exp $

BUILDLINK_TREE+=	libzn-poly

.if !defined(LIBZN_POLY_BUILDLINK3_MK)
LIBZN_POLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libzn-poly+=	libzn-poly>=0.9
BUILDLINK_PKGSRCDIR.libzn-poly?=	../../wip/libzn-poly


.include "../../devel/gmp/buildlink3.mk"
.endif	# LIBZN_POLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libzn-poly
