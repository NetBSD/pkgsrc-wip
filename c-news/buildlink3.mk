# $NetBSD: buildlink3.mk,v 1.6 2009/03/20 19:43:39 jsonn Exp $

BUILDLINK_TREE+=	c-news-CR

.if !defined(C_NEWS_CR_BUILDLINK3_MK)
C_NEWS_CR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.c-news-CR+=	c-news-CR>=7
BUILDLINK_DEPMETHOD.c-news-CR?=		build
BUILDLINK_PKGSRCDIR.c-news-CR?=		../../wip/c-news
.endif # C_NEWS_CR_BUILDLINK3_MK

BUILDLINK_TREE+=	-c-news-CR
