# $NetBSD: buildlink3.mk,v 1.1 2013/08/14 01:13:50 outpaddling Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.webbrowser?=	build

BUILDLINK_TREE+=	webbrowser

.if !defined(WEBBROWSER_BUILDLINK3_MK)
WEBBROWSER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.webbrowser+=	webbrowser>=0.3
BUILDLINK_PKGSRCDIR.webbrowser?=	../../jb-wip/webbrowser
.endif	# WEBBROWSER_BUILDLINK3_MK

BUILDLINK_TREE+=	-webbrowser
