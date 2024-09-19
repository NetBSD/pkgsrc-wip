# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/03/22 13:27:55 jihbed Exp $

BUILDLINK_TREE+=	partonevolution

.if !defined(PARTONEVOLUTION_BUILDLINK3_MK)
PARTONEVOLUTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.partonevolution+=	partonevolution>=1.1.2
BUILDLINK_PKGSRCDIR.partonevolution?=	../../wip/partonevolution
.endif	# PARTONEVOLUTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-partonevolution
