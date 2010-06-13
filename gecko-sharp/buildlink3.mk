# $NetBSD: buildlink3.mk,v 1.4 2010/06/13 22:47:04 thomasklausner Exp $

BUILDLINK_TREE+=	gecko-sharp-2.0

.if !defined(GECKO_SHARP_2.0_BUILDLINK3_MK)
GECKO_SHARP_2.0_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gecko-sharp-2.0+=	gecko-sharp-2.0>=0.13
BUILDLINK_ABI_DEPENDS.gecko-sharp-2.0?=	gecko-sharp-2.0>=0.13nb2
BUILDLINK_PKGSRCDIR.gecko-sharp-2.0?=	../../wip/gecko-sharp

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/glib2/buildlink3.mk"
#.include "../../lang/mono/buildlink3.mk"
#.include "../../x11/gtk2/buildlink3.mk"
#.include "../../x11/gtk-sharp/buildlink3.mk"
.endif	# GECKO_SHARP_2.0_BUILDLINK3_MK

BUILDLINK_TREE+=	-gecko-sharp-2.0
