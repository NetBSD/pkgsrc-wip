# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/07/22 10:46:04 krub1 Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
HAL_BUILDLINK3_MK:=	${HAL_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	hal
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nhal}
BUILDLINK_PACKAGES+=	hal
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}hal

.if ${HAL_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.hal+=	hal>=07222007
BUILDLINK_PKGSRCDIR.hal?=	../../wip/hal-dev
.endif	# HAL_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../wip/libvolumeid/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
