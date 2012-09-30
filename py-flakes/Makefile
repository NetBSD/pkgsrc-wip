# $NetBSD: Makefile,v 1.7 2012/09/30 09:55:06 noud4 Exp $
#

DISTNAME=	pyflakes-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel python
CATEGORIES=	wip
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyflakes/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://launchpad.net/pyflakes
COMMENT=	Passive checker of Python programs
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pyflakes-0.5.0

USE_LANGUAGES=	# none

PYDISTUTILSPKG= yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/bin/pyflakes ${WRKSRC}/bin/pyflakes${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
