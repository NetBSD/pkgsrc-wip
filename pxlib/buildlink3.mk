# $NetBSD: buildlink3.mk,v 1.1 2004/04/12 01:37:13 blef Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PXLIB_BUILDLINK3_MK:=	${PXLIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pxlib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npxlib}
BUILDLINK_PACKAGES+=	pxlib

.if !empty(PXLIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pxlib+=	pxlib>=0.2.0
BUILDLINK_PKGSRCDIR.pxlib?=	../../wip/pxlib
.endif	# PXLIB_BUILDLINK3_MK

.include "../../converters/libiconv/buildlink3.mk"
.include "../../converters/recode/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
