# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/10/28 17:51:07 jihbed Exp $

BUILDLINK_TREE+=	circe2

.if !defined(CIRCE2_BUILDLINK3_MK)
CIRCE2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.circe2+=	circe2>=2.0.5
BUILDLINK_PKGSRCDIR.circe2?=	../../wip/circe2

#.include "../../lang/ocaml/buildlink3.mk"
.endif	# CIRCE2_BUILDLINK3_MK

BUILDLINK_TREE+=	-circe2
