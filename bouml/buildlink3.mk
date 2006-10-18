# $NetBSD: buildlink3.mk,v 1.0 2006/10/18 17:16:08 kcf Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.12.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.bouml?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
BOUML_BUILDLINK3_MK:=	${BOUML_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	bouml
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nbouml}
BUILDLINK_PACKAGES+=	bouml

.if ${BOUML_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.bouml+=	bouml>=2.17.2
BUILDLINK_PKGSRCDIR.bouml?=	../../devel/bouml
.endif	# BOUML_BUILDLINK3_MK

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../x11/qt3-tools/buildlink3.mk"
#.include "../../x11/qt3-libs/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
