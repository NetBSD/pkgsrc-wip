# $NetBSD: buildlink3.mk,v 1.1 2013/09/17 23:37:03 szptvlfn Exp $

BUILDLINK_TREE+=	hs-data-default-class

.if !defined(HS_DATA_DEFAULT_CLASS_BUILDLINK3_MK)
HS_DATA_DEFAULT_CLASS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-data-default-class+=	hs-data-default-class>=0.0.1
BUILDLINK_PKGSRCDIR.hs-data-default-class?=	../../wip/hs-data-default-class
.endif	# HS_DATA_DEFAULT_CLASS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-data-default-class
