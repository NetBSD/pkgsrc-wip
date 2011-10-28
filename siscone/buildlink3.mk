# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/10/28 20:18:17 jihbed Exp $

BUILDLINK_TREE+=	siscone

.if !defined(SISCONE_BUILDLINK3_MK)
SISCONE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.siscone+=	siscone>=2.0.1
BUILDLINK_PKGSRCDIR.siscone?=	../../wip/siscone
.endif	# SISCONE_BUILDLINK3_MK

BUILDLINK_TREE+=	-siscone
