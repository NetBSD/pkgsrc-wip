# $NetBSD: buildlink3.mk,v 1.1 2007/04/25 07:07:58 bsadewitz Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.13.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.beryl-settings-bindings?=	build

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
BERYL_SETTINGS_BINDINGS_BUILDLINK3_MK:=	${BERYL_SETTINGS_BINDINGS_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	beryl-settings-bindings
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nberyl-settings-bindings}
BUILDLINK_PACKAGES+=	beryl-settings-bindings
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}beryl-settings-bindings

.if ${BERYL_SETTINGS_BINDINGS_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.beryl-settings-bindings+=	beryl-settings-bindings>=0.2.1
BUILDLINK_PKGSRCDIR.beryl-settings-bindings?=	../../wip/beryl-settings-bindings
.endif	# BERYL_SETTINGS_BINDINGS_BUILDLINK3_MK

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
