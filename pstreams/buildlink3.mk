# $NetBSD: buildlink3.mk,v 1.2 2011/10/29 10:35:55 ryo-on Exp $

BUILDLINK_TREE+=	pstreams

.if !defined(PSTREAMS_BUILDLINK3_MK)
PSTREAMS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.pstreams?=	build

BUILDLINK_API_DEPENDS.pstreams+=	pstreams>=0.7.0
BUILDLINK_PKGSRCDIR.pstreams?=	../../wip/pstreams
.endif	# PSTREAMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-pstreams
