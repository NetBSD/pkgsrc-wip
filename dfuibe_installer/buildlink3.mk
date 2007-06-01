# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/06/01 20:00:05 hoka_adam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
DFUIBE_INSTALLER_BUILDLINK3_MK:=	${DFUIBE_INSTALLER_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	dfuibe_installer
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ndfuibe_installer}
BUILDLINK_PACKAGES+=	dfuibe_installer
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}dfuibe_installer

.if ${DFUIBE_INSTALLER_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.dfuibe_installer+=	dfuibe_installer>=1.1.7
BUILDLINK_PKGSRCDIR.dfuibe_installer?=	../../wip/dfuibe_installer.import
.endif	# DFUIBE_INSTALLER_BUILDLINK3_MK

.include "../../wip/libinstaller/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
