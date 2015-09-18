# $NetBSD: buildlink3.mk,v 1.1 2015/09/18 13:44:08 outpaddling Exp $

BUILDLINK_TREE+=	cd-hit

.if !defined(CD_HIT_BUILDLINK3_MK)
CD_HIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cd-hit+=	cd-hit>=4.6.1
BUILDLINK_PKGSRCDIR.cd-hit?=	../../wip/cd-hit
.endif	# CD_HIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-cd-hit
