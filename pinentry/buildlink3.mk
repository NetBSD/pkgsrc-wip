# $NetBSD: buildlink3.mk,v 1.1 2004/10/15 17:15:17 johnrshannon Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PINENTRY_BUILDLINK3_MK:=	${PINENTRY_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pinentry
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npinentry}
BUILDLINK_PACKAGES+=	pinentry

.if !empty(PINENTRY_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pinentry+=	pinentry>=0.7.1
BUILDLINK_PKGSRCDIR.pinentry?=	../../wip/pinentry
.endif	# PINENTRY_BUILDLINK3_MK

.include "../../security/libksba/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
