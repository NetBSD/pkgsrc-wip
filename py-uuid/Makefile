# $NetBSD: Makefile,v 1.9 2014/06/01 12:49:47 thomasklausner Exp $
#

DISTNAME=	uuid-1.30
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uuid/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/uuid/1.30
COMMENT=	UUID object and generation functions
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/uuid-1.30
USE_LANGUAGES=	# none

PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
