# $NetBSD: Makefile,v 1.9 2012/10/03 09:40:14 jihbed Exp $
#

DISTNAME=	httplib2-0.7.6
EGG_NAME=	httplib2-0.7.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://httplib2.googlecode.com/files/

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	http://code.google.com/p/httplib2/
COMMENT=	Comprehensive http client library for Python
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

PLIST_SUBST+=	EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

# Install README manually
DOCDIR=		${PREFIX}/share/doc/py-httplib2

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
