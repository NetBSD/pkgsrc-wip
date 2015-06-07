# $NetBSD: buildlink3.mk,v 1.2 2015/06/07 14:24:49 yrmt Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.webkit-gtk3?=	build

BUILDLINK_TREE+=	webkit-gtk3

.if !defined(WEBKIT_GTK3_BUILDLINK3_MK)
WEBKIT_GTK3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.webkit-gtk3+=	webkit-gtk3>=2.4.8
BUILDLINK_PKGSRCDIR.webkit-gtk3?=	../../wip/webkit-gtk3

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../x11/gtk3/buildlink3.mk"
#.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/gobject-introspection/buildlink3.mk"
#.include "../../devel/zlib/buildlink3.mk"
#.include "../../databases/sqlite3/buildlink3.mk"
#.include "../../devel/flex/buildlink3.mk"
#.include "../../devel/gperf/buildlink3.mk"
#.include "../../graphics/freetype2/buildlink3.mk"
#.include "../../graphics/libwebp/buildlink3.mk"
#.include "../../graphics/png/buildlink3.mk"
#.include "../../multimedia/gstreamer1/buildlink3.mk"
#.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
#.include "../../security/libsecret/buildlink3.mk"
#.include "../../textproc/icu/buildlink3.mk"
#.include "../../textproc/libxslt/buildlink3.mk"
#.include "../../x11/libXdamage/buildlink3.mk"
#.include "../../x11/libXt/buildlink3.mk"
.endif	# WEBKIT_GTK3_BUILDLINK3_MK

BUILDLINK_TREE+=	-webkit-gtk3
