# $NetBSD: Makefile,v 1.1.1.1 2003/11/23 11:28:52 mpasternak Exp $
#

DISTNAME=	VTKData-${VTK_VERSION}
PKGNAME=	vtk-data-${VTK_VERSION}

WRKSRC=		${WRKDIR}/VTKData-release-${VTK_VERSION:S/./-/}
PATCHDIR=	# defined # ${.CURDIR}/../vtk/patches
NO_BUILD=	# defined
NO_CONFIGURE=	# defined
NO_PATCHING=	# defined

EXAMPLES_DIR=	share/vtk/
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${EXAMPLES_DIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${WRKSRC} && ${PAX} -rw -pe * ${PREFIX}/${EXAMPLES_DIR}
	cd ${PREFIX} && ${FIND} ${EXAMPLES_DIR} -type f -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} -d ${EXAMPLES_DIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}

.include "../../wip/vtk/Makefile.common"
.include "../../mk/bsd.pkg.mk"
