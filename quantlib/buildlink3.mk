# $NetBSD: buildlink3.mk,v 1.1 2012/02/28 18:57:25 slitvinov Exp $

BUILDLINK_TREE+=	QuantLib

.if !defined(QUANTLIB_BUILDLINK3_MK)
QUANTLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.QuantLib+=	QuantLib>=1.1
BUILDLINK_PKGSRCDIR.QuantLib?=		../../wip/quantlib

.include "../../devel/boost-headers/buildlink3.mk"
.endif	# QUANTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-QuantLib
