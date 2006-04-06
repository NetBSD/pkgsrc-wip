# $NetBSD: buildlink3.mk,v 1.2 2006/04/06 07:17:46 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBLINGOTEACH_BUILDLINK3_MK:=	${LIBLINGOTEACH_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	liblingoteach
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nliblingoteach}
BUILDLINK_PACKAGES+=	liblingoteach

.if !empty(LIBLINGOTEACH_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.liblingoteach+=	liblingoteach>=0.2.1
BUILDLINK_PKGSRCDIR.liblingoteach?=	../../wip/liblingoteach
.endif	# LIBLINGOTEACH_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
