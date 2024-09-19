# $NetBSD: buildlink3.mk,v 1.1 2014/11/22 12:22:53 jihbed Exp $

BUILDLINK_TREE+=	geners

.if !defined(GENERS_BUILDLINK3_MK)
GENERS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.geners+=	geners>=1.5.0
BUILDLINK_PKGSRCDIR.geners?=	../../wip/geners
.endif	# GENERS_BUILDLINK3_MK

BUILDLINK_TREE+=	-geners
