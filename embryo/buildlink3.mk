# $NetBSD: buildlink3.mk,v 1.2 2004/10/15 14:53:20 tvierling Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
EMBRYO_BUILDLINK3_MK:=	${EMBRYO_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	embryo
.endif

BUILDLINK_PACKAGES+=	embryo

.if !empty(EMBRYO_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.embryo+=	embryo>=0.9.0
BUILDLINK_PKGSRCDIR.embryo?=	../../wip/embryo
.endif	# EMBRYO_BUILDLINK3_MK

.include "../../devel/libltdl/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
