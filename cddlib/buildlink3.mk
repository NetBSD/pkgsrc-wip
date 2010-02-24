# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/02/24 10:05:59 jihbed Exp $

BUILDLINK_TREE+=	cddlib

.if !defined(CDDLIB_BUILDLINK3_MK)
CDDLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cddlib+=	cddlib>=0.94
BUILDLINK_PKGSRCDIR.cddlib?=	../../wip/cddlib


.include "../../devel/gmp/buildlink3.mk"
.endif	# CDDLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-cddlib
