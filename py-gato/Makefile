# $NetBSD: Makefile,v 1.1 2015/02/16 22:06:44 jihbed Exp $

DISTNAME=	Gato-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math graphics python
MASTER_SITES=	https://pypi.python.org/packages/source/G/Gato/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://gato.sf.net/
COMMENT=	Python-based toolbox to visualise algorithms on graphs
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

USE_LANGUAGES=	# none

PYDISTUTILSPKG= yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

post-extract:
	${MV} ${WRKSRC}/scripts/Gato ${WRKSRC}/scripts/Gato${PYVERSSUFFIX}
	${MV} ${WRKSRC}/scripts/Gred ${WRKSRC}/scripts/Gred${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
