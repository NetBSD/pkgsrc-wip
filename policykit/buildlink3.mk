# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/03/09 08:23:57 ondratu Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
POLICYKIT_BUILDLINK3_MK:=	${POLICYKIT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	PolicyKit
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NPolicyKit}
BUILDLINK_PACKAGES+=	PolicyKit
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}PolicyKit

.if ${POLICYKIT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.PolicyKit+=	PolicyKit>=20060821
BUILDLINK_PKGSRCDIR.PolicyKit?=	../../wip/policykit.import
.endif	# POLICYKIT_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
