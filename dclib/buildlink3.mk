# $NetBSD: buildlink3.mk,v 1.3 2005/02/12 15:44:43 tnn2 Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
DCLIB_BUILDLINK3_MK:=	${DCLIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	dclib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ndclib}
BUILDLINK_PACKAGES+=	dclib

.if !empty(DCLIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.dclib+=	dclib>=0.3.6
BUILDLINK_PKGSRCDIR.dclib?=	../../wip/dclib
.endif	# DCLIB_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
