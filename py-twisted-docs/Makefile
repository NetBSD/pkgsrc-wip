# $NetBSD: Makefile,v 1.1.1.1 2003/11/23 00:27:30 mpasternak Exp $
#

PKGNAME=	py-twisted-docs-${TWISTED_VERSION}

NO_CONFIGURE=	# defined
NO_BUILD=	# defined

HTMLDIR=	share/doc/py-twisted-docs-${TWISTED_VERSION}
DOC_SRCDIR=	${WRKSRC}/doc
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${DOC_SRCDIR} && ${PAX} -rw -pe * ${PREFIX}/${HTMLDIR}
	cd ${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} -d ${HTMLDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}

.include "../../wip/py-twisted/Makefile.common"
.include "../../mk/bsd.pkg.mk"
