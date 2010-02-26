# $NetBSD: Makefile,v 1.7 2010/02/26 18:10:48 jihbed Exp $
#

DISTNAME=	httplib2-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://httplib2.googlecode.com/files/

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	http://code.google.com/p/httplib2/
COMMENT=	Comprehensive http client library for Python
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_ACCEPTED= 26

# Install README manually
DOCDIR=		${PREFIX}/share/doc/py-httplib2

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
