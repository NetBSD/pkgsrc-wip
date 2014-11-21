# $NetBSD: buildlink3.mk,v 1.1 2014/11/21 14:53:29 outpaddling Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.ganglia-web?=	build

BUILDLINK_TREE+=	ganglia-web

.if !defined(GANGLIA_WEB_BUILDLINK3_MK)
GANGLIA_WEB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ganglia-web+=	ganglia-web>=3.6.2
BUILDLINK_PKGSRCDIR.ganglia-web?=	../../wip/ganglia-web
.endif	# GANGLIA_WEB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ganglia-web
