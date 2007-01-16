# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/01/16 17:57:13 netcap Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
DSSI_BUILDLINK3_MK:=	${DSSI_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	dssi
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ndssi}
BUILDLINK_PACKAGES+=	dssi
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}dssi

.if ${DSSI_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.dssi+=	dssi>=0.9.1
BUILDLINK_PKGSRCDIR.dssi?=	../../wip/dssi
BUILDLINK_DEPMETHOD.dssi?=	build
.endif	# DSSI_BUILDLINK3_MK

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

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
