# $NetBSD: buildlink3.mk,v 1.7 2009/03/22 17:13:05 jsonn Exp $

BUILDLINK_TREE+=	clhep

.if !defined(CLHEP_BUILDLINK3_MK)
CLHEP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clhep+=	clhep>=1.9.3.0
BUILDLINK_PKGSRCDIR.clhep?=	../../wip/clhep
BUILDLINK_DEPMETHOD.clhep?=	build
.endif # CLHEP_BUILDLINK3_MK

BUILDLINK_TREE+=	-clhep
