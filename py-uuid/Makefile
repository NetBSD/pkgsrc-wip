# $NetBSD: Makefile,v 1.7 2012/11/23 22:44:44 othyro Exp $
#

DISTNAME=	uuid-1.30
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://pypi.python.org/packages/source/u/uuid/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/uuid/1.30
COMMENT=	UUID object and generation functions
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/uuid-1.30
USE_LANGUAGES=	# none

PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
