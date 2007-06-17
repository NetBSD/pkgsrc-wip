# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/06/17 21:45:46 kheinz Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.13.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libpurple?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBPURPLE_BUILDLINK3_MK:=	${LIBPURPLE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	libpurple
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibpurple}
BUILDLINK_PACKAGES+=	libpurple
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libpurple

.if ${LIBPURPLE_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.libpurple+=	libpurple>=0.0.1
BUILDLINK_PKGSRCDIR.libpurple?=	../../wip/libpurple
.endif	# LIBPURPLE_BUILDLINK3_MK

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../converters/libiconv/buildlink3.mk"
#.include "../../devel/glib2/buildlink3.mk"
#.include "../../textproc/libxml2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
