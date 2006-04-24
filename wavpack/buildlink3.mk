# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/04/24 13:58:14 tnn2 Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
WAVPACK_BUILDLINK3_MK:=	${WAVPACK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	wavpack
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nwavpack}
BUILDLINK_PACKAGES+=	wavpack

.if !empty(WAVPACK_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.wavpack+=	wavpack>=wavpack-4.32
BUILDLINK_ABI_DEPENDS.wavpack+=	wavpack>=wavpack-4.32
BUILDLINK_PKGSRCDIR.wavpack?=	../../wip/wavpack
.endif	# WAVPACK_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
