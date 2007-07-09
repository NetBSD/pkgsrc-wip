# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/07/09 21:07:06 shindenmorr Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.13.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libdshconfig?=	build

BUILDLINK_DEPMETHOD.libdshconfig?=      build
BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBDSHCONFIG_BUILDLINK3_MK:=	${LIBDSHCONFIG_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libdshconfig
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibdshconfig}
BUILDLINK_PACKAGES+=	libdshconfig
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libdshconfig

.if ${LIBDSHCONFIG_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libdshconfig+=	libdshconfig>=0.20.9
BUILDLINK_PKGSRCDIR.libdshconfig?=	../../wip/libdshconfig
.endif	# LIBDSHCONFIG_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
