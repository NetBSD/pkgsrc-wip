# $NetBSD: buildlink3.mk,v 1.3 2007/12/02 21:01:02 ondratu Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
POLICYKIT_BUILDLINK3_MK:=	${POLICYKIT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	PolicyKit
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NPolicyKit}
BUILDLINK_PACKAGES+=	PolicyKit
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}PolicyKit

.if ${POLICYKIT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.PolicyKit+=	PolicyKit>=0.6
BUILDLINK_PKGSRCDIR.PolicyKit?=	../../wip/policykit
.endif	# POLICYKIT_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
