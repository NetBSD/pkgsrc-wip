# $NetBSD: buildlink3.mk,v 1.1 2004/05/02 22:41:29 blef Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBXMLXX_BUILDLINK3_MK:=	${LIBXMLXX_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libxmlxx
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibxmlxx}
BUILDLINK_PACKAGES+=	libxmlxx

.if !empty(LIBXMLXX_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libxmlxx+=	libxml++>=0.27.0nb1
BUILDLINK_PKGSRCDIR.libxmlxx?=	../../wip/libxml++
.endif	# LIBXMLXX_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
