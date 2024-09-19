# $NetBSD: Makefile,v 1.1 2015/08/05 20:38:06 jihbed Exp $

DISTNAME=	Escher-1.1.2.post2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_PYPI:=E/Escher/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://escher.github.io
COMMENT=	Build, view, share, and embed pathway maps
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	jsonschema>=2.4.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-tornado-[0-9]*:../../www/py-tornado

WRKSRC=		${WRKDIR}/Escher-1.1.2.post2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
