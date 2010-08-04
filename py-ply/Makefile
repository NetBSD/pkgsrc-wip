# $NetBSD: Makefile,v 1.1.1.1 2010/08/04 16:15:27 ura Exp $
#

PYMODULENAME=		ply
PYMODULEVER=		3.3
DISTNAME=		${PYMODULENAME}-${PYMODULEVER}
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://www.dabeaz.com/ply/

MAINTAINER=		ura@jp.NetBSD.org
HOMEPAGE=		http://www.dabeaz.com/ply/
COMMENT=		Lex an yacc parsing tools for Python
LICENSE=		gnu-lgpl-v2.1

USE_TOOLS+=		pax
PKG_DESTDIR_SUPPORT=	user-destdir

DOCDIR=			${DESTDIR}${PREFIX}/share/doc/py-${PYMODULENAME}
EGDIR=			${DESTDIR}${PREFIX}/share/examples/py-${PYMODULENAME}

INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCDIR}
	cd ${WRKSRC}/example && \
	    ${PAX} -wr . ${EGDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
