# $NetBSD: Makefile,v 1.3 2014/12/31 13:58:36 thomasklausner Exp $

DISTNAME=	plex-2.0.0dev
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/dev//}
EGG_NAME=	${DISTNAME:S/dev/.dev0/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/plex/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/python-plex/
COMMENT=	Plex is a library building lexical analysers
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 2.0.0dev

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
