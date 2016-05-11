# $NetBSD$

BUILDLINK_TREE+=	udunits

.if !defined(UDUNITS_BUILDLINK3_MK)
UDUNITS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.udunits+=	udunits>=2.2.19
BUILDLINK_PKGSRCDIR.udunits?=	../../wip/udunits2

.include "../../textproc/expat/buildlink3.mk"
.endif	# UDUNITS_BUILDLINK3_MK

BUILDLINK_TREE+=	-udunits
