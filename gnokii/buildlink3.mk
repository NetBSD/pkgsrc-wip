# $NetBSD: buildlink3.mk,v 1.2 2007/12/08 16:13:11 shattered Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GNOKII_BUILDLINK3_MK:=	${GNOKII_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	gnokii
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngnokii}
BUILDLINK_PACKAGES+=	gnokii
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gnokii

.if ${GNOKII_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.gnokii+=	gnokii>=0.6.14
BUILDLINK_PKGSRCDIR.gnokii?=	../../wip/gnokii
.endif	# GNOKII_BUILDLINK3_MK

.include "../../devel/libusb/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
