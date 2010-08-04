# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/08/04 00:07:36 jihbed Exp $

BUILDLINK_TREE+=	lucene

.if !defined(LUCENE_BUILDLINK3_MK)
LUCENE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lucene+=	lucene>=3.0.2
BUILDLINK_PKGSRCDIR.lucene?=	../../wip/lucene
.endif	# LUCENE_BUILDLINK3_MK

BUILDLINK_TREE+=	-lucene
