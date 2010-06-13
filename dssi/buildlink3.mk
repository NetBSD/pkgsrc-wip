# $NetBSD: buildlink3.mk,v 1.4 2010/06/13 22:46:59 thomasklausner Exp $

BUILDLINK_TREE+=	dssi

.if !defined(DSSI_BUILDLINK3_MK)
DSSI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dssi+=	dssi>=0.9.1
BUILDLINK_ABI_DEPENDS.dssi?=	dssi>=0.9.1nb3
BUILDLINK_PKGSRCDIR.dssi?=	../../wip/dssi
BUILDLINK_DEPMETHOD.dssi?=	build

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../audio/libsamplerate/buildlink3.mk"
#.include "../../audio/libsndfile/buildlink3.mk"
#.include "../../audio/jack/buildlink3.mk"
#.include "../../audio/ladspa/buildlink3.mk"
#.include "../../wip/libdssialsacompat/buildlink3.mk"
#.include "../../wip/liblo/buildlink3.mk"
#.include "../../x11/qt3-libs/buildlink3.mk"
.endif # DSSI_BUILDLINK3_MK

BUILDLINK_TREE+=	-dssi
