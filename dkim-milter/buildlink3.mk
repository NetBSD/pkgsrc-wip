# $NetBSD: buildlink3.mk,v 1.1 2008/11/30 20:49:41 pettai Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
DKIM_MILTER_BUILDLINK3_MK:=	${DKIM_MILTER_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	dkim-milter
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ndkim-milter}
BUILDLINK_PACKAGES+=	dkim-milter
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}dkim-milter

.if ${DKIM_MILTER_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.dkim-milter+=	dkim-milter>=2.7.2
BUILDLINK_PKGSRCDIR.dkim-milter?=	../../wip/dkim-milter
BUILDLINK_DEPMETHOD.dkim-milter?=	build
.endif	# DKIM_MILTER_BUILDLINK3_MK

.include "../../security/openssl/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
