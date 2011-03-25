# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/03/25 18:11:59 jihbed Exp $

BUILDLINK_TREE+=	maloc

.if !defined(MALOC_BUILDLINK3_MK)
MALOC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.maloc+=	maloc>=1.4
BUILDLINK_PKGSRCDIR.maloc?=	../../wip/maloc

.endif	# MALOC_BUILDLINK3_MK

BUILDLINK_TREE+=	-maloc
