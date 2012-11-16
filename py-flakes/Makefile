# $NetBSD: Makefile,v 1.10 2012/11/16 23:54:02 noud4 Exp $
#

DISTNAME=	pyflakes-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	1	
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyflakes/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://launchpad.net/pyflakes
COMMENT=	Passive checker of Python programs
LICENSE=	mit

WRKSRC=		${WRKDIR}/pyflakes-0.5.0

USE_LANGUAGES=	# none

PYDISTUTILSPKG= yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/bin/pyflakes ${WRKSRC}/bin/pyflakes${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
