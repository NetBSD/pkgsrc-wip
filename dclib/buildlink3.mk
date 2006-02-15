# $NetBSD: buildlink3.mk,v 1.5 2006/02/15 16:08:07 tnn2 Exp $

.include "../../wip/valknut/Makefile.version"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
DCLIB_BUILDLINK3_MK:=	${DCLIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	dclib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ndclib}
BUILDLINK_PACKAGES+=	dclib

.if !empty(DCLIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.dclib+=	dclib>=${VALKNUT_PKG_VERSION}
BUILDLINK_PKGSRCDIR.dclib?=	../../wip/dclib
.endif	# DCLIB_BUILDLINK3_MK

.include "../../wip/libootool/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
