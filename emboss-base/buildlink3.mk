# $NetBSD: buildlink3.mk,v 1.5 2009/05/06 09:35:22 cheusov Exp $

BUILDLINK_TREE+=	emboss-base

.if !defined(EMBOSS_BASE_BUILDLINK3_MK)
EMBOSS_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.emboss-base+=	emboss-base>=2.7.1
BUILDLINK_PKGSRCDIR.emboss-base?=	../../wip/emboss-base
.endif # EMBOSS_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-emboss-base
