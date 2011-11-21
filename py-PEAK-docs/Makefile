# $NetBSD: Makefile,v 1.6 2011/11/21 19:08:57 absd Exp $
#

DISTNAME=		PEAK-0.5a3
PKGNAME=		py-PEAK-docs-0.5a3
CATEGORIES=		devel
MASTER_SITES=		http://peak.telecommunity.com/dist/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://peak.telecommunity.com/
COMMENT=		Python Enterprise Application Kit

NO_CONFIGURE=		yes
NO_BUILD=		yes
USE_TOOLS+=		pax

HTMLDIR=		share/doc/${PKGNAME}
DOC_SRCDIR=		${WRKSRC}/docs
PLIST_SRC=		${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${DOC_SRCDIR}/html && pax -rw -pe reference ${PREFIX}/${HTMLDIR}
	cd ${DOC_SRCDIR}/core_tutorial && pax -rw -pe tut ${PREFIX}/${HTMLDIR}
	cd ${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
