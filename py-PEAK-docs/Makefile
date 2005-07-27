# $NetBSD: Makefile,v 1.2 2005/07/27 16:27:27 thomasklausner Exp $
#

DISTNAME=		PEAK-0.5a3
PKGNAME=		py-PEAK-docs-0.5a3
CATEGORIES=		devel
MASTER_SITES=		http://peak.telecommunity.com/dist/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://peak.telecommunity.com/
COMMENT=		Python Enterprise Application Kit

NO_CONFIGURE=		# defined
NO_BUILD=		# defined

HTMLDIR=		share/doc/${PKGNAME}
DOC_SRCDIR=		${WRKSRC}/docs
PLIST_SRC=		${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${DOC_SRCDIR}/html && ${PAX} -rw -pe reference ${PREFIX}/${HTMLDIR}
	cd ${DOC_SRCDIR}/core_tutorial && ${PAX} -rw -pe tut ${PREFIX}/${HTMLDIR}
	cd ${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} -d ${HTMLDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
