# $NetBSD: buildlink3.mk,v 1.3 2007/04/29 20:22:14 bsadewitz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PTHREAD_STUBS_BUILDLINK3_MK:=	${PTHREAD_STUBS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libpthread-stubs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibpthread-stubs}
BUILDLINK_PACKAGES+=	libpthread-stubs
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libpthread-stubs

.if ${PTHREAD_STUBS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libpthread-stubs+=	libpthread-stubs>=0.1
BUILDLINK_PKGSRCDIR.libpthread-stubs?=	../../wip/libpthread-stubs
BUILDLINK_LDADD.libpthread-stubs=	-lpthread-stubs
BUILDLINK_LIBS.libpthread-stubs=	${BUILDLINK_LDADD.libpthread-stubs}
.endif	# PTHREAD_STUBS_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
