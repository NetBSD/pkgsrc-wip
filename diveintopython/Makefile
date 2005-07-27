# $NetBSD: Makefile,v 1.2 2005/07/27 16:25:09 thomasklausner Exp $
#

DISTNAME=		diveintopython-html-4.4-2
PKGNAME=		${DISTNAME:S/-html//}
WRKSRC=			${WRKDIR}/
CATEGORIES=		misc
MASTER_SITES=		http://diveintopython.org/download/
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://diveintopython.org/download/
COMMENT=		Free book for experienced Python programmers

HTMLDIR=		share/doc/diveintopython
DOC_SRCDIR=		${WRKSRC}
PLIST_SRC=		${WRKDIR}/.PLIST_SRC
NO_BUILD= 		# defined
NO_CONFIGURE=		# defined

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${DOC_SRCDIR} && ${PAX} -rw -pe * ${PREFIX}/${HTMLDIR}
	cd ${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}
	cd ${PREFIX} && ${FIND} -d ${HTMLDIR} -type d -print | \
	${SED} -e "s/^/@dirrm /" >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
