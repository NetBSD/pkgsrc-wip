# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/06/27 09:45:59 adrian_p Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBMILTER_BUILDLINK3_MK:=	${LIBMILTER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libmilter
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibmilter}
BUILDLINK_PACKAGES+=	libmilter

.if !empty(LIBMILTER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libmilter+=	libmilter>=8.13.0
BUILDLINK_PKGSRCDIR.libmilter?=	../../wip/libmilter813
BUILDLINK_DEPMETHOD.libmilter?=	build

PTHREAD_OPTS+=		require
.endif	# LIBMILTER_BUILDLINK3_MK

.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
