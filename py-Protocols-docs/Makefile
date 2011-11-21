# $NetBSD: Makefile,v 1.7 2011/11/21 19:08:57 absd Exp $
#

DISTNAME=		PyProtocols-0.9.2
PKGNAME=		py-Protocols-docs-0.9.2
CATEGORIES=		devel
MASTER_SITES=		http://peak.telecommunity.com/dist/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://peak.telecommunity.com/PyProtocols.html
COMMENT=		HTML docs for devel/py-Protocols

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_TOOLS+=	pax

HTMLDIR=	share/doc/py-Protocols-0.9.2
DOC_SRCDIR=	${WRKSRC}/docs/html/reference/
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	${CAT} ${PKGDIR}/PLIST.pre >${PLIST_SRC}
	cd ${DOC_SRCDIR} && pax -rw -pe * ${PREFIX}/${HTMLDIR}
	cd ${DOC_SRCDIR}/../../ref/ && pax -rw -pe ref ${PREFIX}/${HTMLDIR}
	cd ${PREFIX} && ${FIND} ${HTMLDIR} -type f -print >>${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
