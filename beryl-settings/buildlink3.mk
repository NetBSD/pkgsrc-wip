# $NetBSD: buildlink3.mk,v 1.2 2007/05/27 06:51:50 bsadewitz Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.13.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.beryl-settings?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
BERYL_SETTINGS_BUILDLINK3_MK:=	${BERYL_SETTINGS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	beryl-settings
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nberyl-settings}
BUILDLINK_PACKAGES+=	beryl-settings
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}beryl-settings

.if ${BERYL_SETTINGS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.beryl-settings+=	beryl-settings>=0.2.1
BUILDLINK_PKGSRCDIR.beryl-settings?=	../../wip/beryl-settings
.endif	# BERYL_SETTINGS_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
