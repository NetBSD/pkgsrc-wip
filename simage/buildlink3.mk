# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 05:24:22 bjan2 Exp $
#
# This Makefile fragment is included by packages that use simage.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SIMAGE_BUILDLINK3_MK:=	${SIMAGE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	simage
.endif

.if !empty(SIMAGE_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			simage
BUILDLINK_DEPENDS.simage+=		simage>=1.6.0
BUILDLINK_PKGSRCDIR.simage?=		../../wip/simage

.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"

.endif # SIMAGE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
