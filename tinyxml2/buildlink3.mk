# $NetBSD: buildlink3.mk,v 1.1 2014/06/30 18:43:03 nros Exp $
#

BUILDLINK_TREE+=	tinyxml2

.if !defined(TINYXML2_BUILDLINK3_MK)
TINYXML2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tinyxml2+=	tinyxml2>=2.1.0
BUILDLINK_PKGSRCDIR.tinyxml2?=	../../wip/tinyxml2
.endif	# TINYXML2_BUILDLINK3_MK

BUILDLINK_TREE+=	-tinyxml2
