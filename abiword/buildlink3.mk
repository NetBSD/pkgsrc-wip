# $NetBSD: buildlink3.mk,v 1.2 2015/07/16 14:09:37 thomasklausner Exp $

BUILDLINK_TREE+=	abiword

.if !defined(ABIWORD_BUILDLINK3_MK)
ABIWORD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.abiword+=	abiword>=3.0.1
BUILDLINK_PKGSRCDIR.abiword?=	../../wip/abiword

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../converters/fribidi/buildlink3.mk"
#.include "../../converters/wv/buildlink3.mk"
#.include "../../devel/boost-headers/buildlink3.mk"
#.include "../../devel/glib2/buildlink3.mk"
#.include "../../graphics/librsvg/buildlink3.mk"
#.include "../../graphics/png/buildlink3.mk"
#.include "../../textproc/enchant/buildlink3.mk"
#.include "../../textproc/libxslt/buildlink3.mk"
#.include "../../time/libical/buildlink3.mk"
.endif	# ABIWORD_BUILDLINK3_MK

BUILDLINK_TREE+=	-abiword
