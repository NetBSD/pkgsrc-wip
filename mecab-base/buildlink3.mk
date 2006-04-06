# $NetBSD: buildlink3.mk,v 1.3 2006/04/06 07:18:04 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
MECAB_BASE_BUILDLINK3_MK:=	${MECAB_BASE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	mecab-base
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmecab-base}
BUILDLINK_PACKAGES+=	mecab-base

.if !empty(MECAB_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.mecab-base+=		mecab-base>=0.90
BUILDLINK_PKGSRCDIR.mecab-base?=	../../wip/mecab-base
BUILDLINK_FILES.mecab-base+=		include/mecab.h
BUILDLINK_FILES.mecab-base+=		lib/libmecab.*
.endif	# MECAB_BASE_BUILDLINK3_MK

.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
