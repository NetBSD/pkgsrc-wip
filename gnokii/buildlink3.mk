# $NetBSD: buildlink3.mk,v 1.1 2007/02/02 13:04:00 koifren Exp $

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
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
