# $NetBSD: buildlink3.mk,v 1.1 2013/06/02 12:27:25 othyro Exp $

BUILDLINK_TREE+=	rapidxml

.if !defined(RAPIDXML_BUILDLINK3_MK)
RAPIDXML_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.rapidxml?=	build

BUILDLINK_API_DEPENDS.rapidxml+=	rapidxml>=1.13
BUILDLINK_PKGSRCDIR.rapidxml?=		../../wip/rapidxml
.endif	# RAPIDXML_BUILDLINK3_MK

BUILDLINK_TREE+=	-rapidxml
