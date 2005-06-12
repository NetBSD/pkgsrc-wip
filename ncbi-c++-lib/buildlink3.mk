# $NetBSD: buildlink3.mk,v 1.2 2005/06/12 23:51:24 kristerw Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.8.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.ncbi_cxx-lib?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
NCBI_CXX_LIB_BUILDLINK3_MK:=	${NCBI_CXX_LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ncbi_cxx-lib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nncbi_cxx-lib}
BUILDLINK_PACKAGES+=	ncbi_cxx-lib

.if !empty(NCBI_CXX_LIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.ncbi_cxx-lib+=	ncbi_cxx-lib>=20041130
BUILDLINK_PKGSRCDIR.ncbi_cxx-lib?=	../../wip/ncbi-c++-lib
.endif	# NCBI_CXX_LIB_BUILDLINK3_MK

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../x11/gtk/buildlink3.mk"
#.include "../../wip/ncbi-lib/buildlink3.mk"
#.include "../../x11/fltk/buildlink3.mk"
#.include "../../x11/wxGTK/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
