# $NetBSD$

BUILDLINK_TREE+=	vte

.if !defined(VTE_BUILDLINK3_MK)
VTE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vte+=	vte>=0.42.1
BUILDLINK_PKGSRCDIR.vte?=	../../wip/vte

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/gperf/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
#.include "../../lang/vala/buildlink3.mk"
#.include "../../devel/gobject-introspection/buildlink3.mk"
#.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/pango/buildlink3.mk"
#.include "../../fonts/fontconfig/buildlink3.mk"
#.include "../../graphics/freetype2/buildlink3.mk"
#.include "../../x11/libSM/buildlink3.mk"
#.include "../../x11/libX11/buildlink3.mk"
#.include "../../x11/libXft/buildlink3.mk"
#.include "../../x11/libXt/buildlink3.mk"
.endif	# VTE_BUILDLINK3_MK

BUILDLINK_TREE+=	-vte
