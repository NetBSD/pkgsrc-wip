# $NetBSD: Makefile,v 1.4 2011/07/24 22:00:13 jihbed Exp $
#

DISTNAME=	pyflakes-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyflakes/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://www.divmod.org/trac/wiki/DivmodPyflakes
COMMENT=	Passive checker of Python programs
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pyflakes-0.4.0
USE_LANGUAGES=	# none

PYDISTUTILSPKG= yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/bin/pyflakes ${WRKSRC}/bin/pyflakes${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
