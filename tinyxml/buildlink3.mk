# $NetBSD: buildlink3.mk,v 1.1 2013/12/04 20:26:22 thomasklausner Exp $

BUILDLINK_TREE+=	tinyxml

.if !defined(TINYXML_BUILDLINK3_MK)
TINYXML_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tinyxml+=	tinyxml>=2.6.2
BUILDLINK_PKGSRCDIR.tinyxml?=	../../wip/tinyxml
.endif	# TINYXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-tinyxml
