# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/06/20 18:20:21 gschwarz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SPEEX-DEVEL_BUILDLINK3_MK:=	${SPEEX-DEVEL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	speex-devel
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nspeex-devel}
BUILDLINK_PACKAGES+=	speex-devel

.if !empty(SPEEX-DEVEL_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.speex-devel+=	speex-devel>=1.1.12
BUILDLINK_PKGSRCDIR.speex-devel?=	../../wip/speex-devel
.endif	# SPEEX-DEVEL_BUILDLINK3_MK

.include "../../multimedia/libogg/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
