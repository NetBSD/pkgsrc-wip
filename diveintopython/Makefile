# $NetBSD: Makefile,v 1.9 2011/11/21 19:08:56 absd Exp $
#

DISTNAME=		diveintopython-html-5.4
PKGNAME=		${DISTNAME:S/-html//}
WRKSRC=			${WRKDIR}/
CATEGORIES=		misc
MASTER_SITES=		http://diveintopython.org/download/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://diveintopython.org/
COMMENT=		Free book for experienced Python programmers

HTMLDIR=		share/doc/diveintopython
DOC_SRCDIR=		${WRKSRC}
PLIST_SRC=		${WRKDIR}/.PLIST_SRC
NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_TOOLS+=		pax

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${DOC_SRCDIR} && pax -rw -pp * ${PREFIX}/${HTMLDIR}
	cd ${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
