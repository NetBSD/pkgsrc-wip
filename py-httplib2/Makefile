# $NetBSD: Makefile,v 1.5 2009/08/19 20:20:34 jihbed Exp $
#

DISTNAME=	httplib2-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://httplib2.googlecode.com/files/

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	http://code.google.com/p/httplib2/
COMMENT=	Comprehensive http client library for Python
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_ACCEPTED= 26 25 24 23

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes


# Install README manually
DOCDIR=		${PREFIX}/share/doc/py-httplib2

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
