# $NetBSD: buildlink3.mk,v 1.1 2006/04/22 13:13:42 cheusov Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.11.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libnettle?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBNETTLE_BUILDLINK3_MK:=	${LIBNETTLE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libnettle
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibnettle}
BUILDLINK_PACKAGES+=	libnettle

.if !empty(LIBNETTLE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libnettle+=	libnettle>=1.14
BUILDLINK_PKGSRCDIR.libnettle?=	../../wip/libnettle
.endif	# LIBNETTLE_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
