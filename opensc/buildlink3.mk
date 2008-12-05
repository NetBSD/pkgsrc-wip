# $NetBSD: buildlink3.mk,v 1.4 2008/12/05 10:06:39 htepper Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OPENSC_BUILDLINK3_MK:=	${OPENSC_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	opensc
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nopensc}
BUILDLINK_PACKAGES+=	opensc
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}opensc

.if !empty(OPENSC_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.opensc+=	opensc>=0.11.5
BUILDLINK_PKGSRCDIR.opensc?=	../../wip/opensc
pkgbase := opensc
.include "../../mk/pkg-build-options.mk"
.endif	# OPENSC_BUILDLINK3_MK

.if !empty(PKG_BUILD_OPTIONS.opensc:Mopenct)
.include "../../wip/openct/buildlink3.mk"
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
