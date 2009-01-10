# $NetBSD: buildlink3.mk,v 1.1 2009/01/10 09:32:40 mwdavies Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.13.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.kdebindings4-python?=	build

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
KDEBINDINGS4_PYTHON_BUILDLINK3_MK:=	${KDEBINDINGS4_PYTHON_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	kdebindings4-python
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nkdebindings4-python}
BUILDLINK_PACKAGES+=	kdebindings4-python
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}kdebindings4-python

.if ${KDEBINDINGS4_PYTHON_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.kdebindings4-python+=	kdebindings4-python>=4.1.85
BUILDLINK_PKGSRCDIR.kdebindings4-python?=	../../wip/kdebindings4-python
.endif	# KDEBINDINGS4_PYTHON_BUILDLINK3_MK

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../wip/kdelibs4/buildlink3.mk"
#.include "../../wip/kdepimlibs4/buildlink3.mk"
#.include "../../x11/py-sip/buildlink3.mk"
#.include "../../x11/py-qt4/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
