# $NetBSD: Makefile,v 1.2 2003/11/23 11:34:33 mpasternak Exp $
#

DISTNAME=	VTKData-${VTK_VERSION}
PKGNAME=	vtk-data-${VTK_VERSION}

WRKSRC=		${WRKDIR}/VTKData-release-${VTK_VERSION:S/./-/}
NO_BUILD=	# defined
NO_CONFIGURE=	# defined
PATCHDIR=	# empty
DISTINFO_FILE=		${.CURDIR}/distinfo

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
