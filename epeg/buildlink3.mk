# $NetBSD: buildlink3.mk,v 1.2 2004/10/15 14:53:20 tvierling Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EPEG_BUILDLINK3_MK:=	${EPEG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	epeg
.endif

BUILDLINK_PACKAGES+=	epeg

.if !empty(EPEG_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.epeg+=	epeg>=0.9.0
BUILDLINK_PKGSRCDIR.epeg?=	../../wip/epeg
.endif	# EPEG_BUILDLINK3_MK

.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
