# $NetBSD: Makefile,v 1.1.1.1 2010/08/04 16:22:26 ura Exp $
#

PYMODULENAME=		figleaf
PYMODULEVER=		0.6.1
DISTNAME=		${PYMODULENAME}-${PYMODULEVER}
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://darcs.idyll.org/~t/projects/

MAINTAINER=		ura@jp.NetBSD.org
HOMEPAGE=		http://darcs.idyll.org/~t/projects/figleaf/doc/
COMMENT=		Figleaf is a Python code coverrage analysis tool
#LICENSE=		bsd

PKG_DESTDIR_SUPPORT=	user-destdir

DOCDIR=			${DESTDIR}${PREFIX}/share/doc/py-${PYMODULENAME}
EGDIR=			${DESTDIR}${PREFIX}/share/examples/py-${PYMODULENAME}

INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${EGDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
