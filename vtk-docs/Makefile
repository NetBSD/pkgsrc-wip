# $NetBSD: Makefile,v 1.1.1.1 2003/11/23 12:15:33 mpasternak Exp $
#

DISTNAME=	VTKDocHtml-${VTK_VERSION}
PKGNAME=	vtk-docs-${VTK_VERSION}

WRKSRC=		${WRKDIR}/html/
NO_BUILD=	# defined
NO_CONFIGURE=	# defined
PATCHDIR=	# empty
DISTINFO_FILE=	${.CURDIR}/distinfo

HTML_DIR=	share/doc/${PKGNAME}/
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTML_DIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${WRKSRC} && ${PAX} -rw -pe * ${PREFIX}/${HTML_DIR}
	cd ${PREFIX} && ${FIND} ${HTML_DIR} -type f -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} -d ${HTML_DIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}

.include "../../wip/vtk/Makefile.common"
.include "../../mk/bsd.pkg.mk"
