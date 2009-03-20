# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:40 jsonn Exp $

BUILDLINK_TREE+=	crfpp

.if !defined(CRFPP_BUILDLINK3_MK)
CRFPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.crfpp+=	crfpp>=0.50
BUILDLINK_PKGSRCDIR.crfpp?=	../../wip/crfpp
.endif # CRFPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-crfpp
