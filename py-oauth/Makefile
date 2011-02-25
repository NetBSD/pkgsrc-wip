# $NetBSD: Makefile,v 1.4 2011/02/25 09:47:49 thomasklausner Exp $
#

DISTNAME=	oauth-1.0.1.tar
EGG_NAME=	${DISTNAME:S/.tar//}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/o/oauth/
EXTRACT_SUFX=	.gz#md5=30ed3cc8c11d7841a89feab437aabf81

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://code.google.com/p/oauth/
COMMENT=	Python bindings for OAuth
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir
WRKSRC=		${WRKDIR}/oauth-1.0.1

USE_LANGUAGES=	# none
PYTHON_VERSIONS_ACCEPTED=	27 26 25 24
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

EGDIR=		share/examples/py-oauth

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/oauth/example/*.py ${DESTDIR}${PREFIX}/${EGDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
