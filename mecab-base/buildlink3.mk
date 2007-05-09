# $NetBSD: buildlink3.mk,v 1.4 2007/05/09 13:21:10 obache Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
MECAB_BASE_BUILDLINK3_MK:=	${MECAB_BASE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	mecab-base
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmecab-base}
BUILDLINK_PACKAGES+=	mecab-base
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}mecab-base

.if ${MECAB_BASE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.mecab-base+=	mecab-base>=0.90
BUILDLINK_PKGSRCDIR.mecab-base?=	../../wip/mecab-base
BUILDLINK_FILES.mecab-base+=		include/mecab.h
BUILDLINK_FILES.mecab-base+=		lib/libmecab.*
.endif	# MECAB_BASE_BUILDLINK3_MK

.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
