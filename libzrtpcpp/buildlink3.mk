# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/10/06 02:17:31 othyro Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBZRTPCPP_BUILDLINK3_MK:=	${LIBZRTPCPP_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libzrtpcpp
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibzrtpcpp}
BUILDLINK_PACKAGES+=	libzrtpcpp
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libzrtpcpp

.if ${LIBZRTPCPP_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libzrtpcpp+=	libzrtpcpp>=0.9.0
BUILDLINK_PKGSRCDIR.libzrtpcpp?=	../../wip/libzrtpcpp
.endif	# LIBZRTPCPP_BUILDLINK3_MK

.include "../../wip/ccrtp/buildlink3.mk"
.include "../../wip/commoncpp2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
