# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/10/14 22:45:20 johnrshannon Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBRFUNCS_BUILDLINK3_MK:=	${LIBRFUNCS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	librfuncs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibrfuncs}
BUILDLINK_PACKAGES+=	librfuncs

.if !empty(LIBRFUNCS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.librfuncs+=	librfuncs>=1.0
BUILDLINK_PKGSRCDIR.librfuncs?=	../../wip/librfuncs
.endif	# LIBRFUNCS_BUILDLINK3_MK

.include "../../mk/pthread.buildlink3.mk"
LIBS+=	${BUILDLINK_LDADD.pthread}
LDFLAGS+=	-lrfuncs
LDFLAGS+=	${BUILDLINK_LDADD.pthread}

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
