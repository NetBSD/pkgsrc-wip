# $NetBSD: buildlink3.mk,v 1.1 2005/01/13 13:04:10 hfath Exp $

# XXX Packages that only install static libraries or headers should
# XXX include the following line:

BUILDLINK_DEPMETHOD.c-news-CR?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
C_NEWS_CR_BUILDLINK3_MK:=	${C_NEWS_CR_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	c-news-CR
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nc-news-CR}
BUILDLINK_PACKAGES+=	c-news-CR

.if !empty(C_NEWS_CR_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.c-news-CR+=	c-news-CR>=7
BUILDLINK_PKGSRCDIR.c-news-CR?=	../../wip/c-news
.endif	# C_NEWS_CR_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
