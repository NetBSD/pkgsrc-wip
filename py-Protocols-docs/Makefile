# $NetBSD: Makefile,v 1.3 2005/07/27 16:27:28 thomasklausner Exp $
#

DISTNAME=		PyProtocols-0.9.2
PKGNAME=		py-Protocols-docs-0.9.2
CATEGORIES=		devel
MASTER_SITES=		http://peak.telecommunity.com/dist/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://peak.telecommunity.com/PyProtocols.html
COMMENT=		HTML docs for devel/py-Protocols

NO_CONFIGURE=	# defined
NO_BUILD=	# defined

HTMLDIR=	share/doc/py-Protocols-0.9.2
DOC_SRCDIR=	${WRKSRC}/docs/html/reference/
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${DOC_SRCDIR} && ${PAX} -rw -pe * ${PREFIX}/${HTMLDIR}
	cd ${DOC_SRCDIR}/../../ref/ && ${PAX} -rw -pe ref ${PREFIX}/${HTMLDIR}
	cd ${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} -d ${HTMLDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
