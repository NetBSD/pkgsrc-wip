# $NetBSD: Makefile,v 1.2 2010/03/28 09:38:16 jihbed Exp $
#

DISTNAME=	oauth-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	http://pypi.python.org/packages/source/o/oauth/

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://code.google.com/p/oauth/
COMMENT=	Python bindings for OAuth
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYTHON_VERSIONS_ACCEPTED=	26 25 24
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

EGDIR=		share/examples/py-oauth

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/oauth/example/*.py ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
