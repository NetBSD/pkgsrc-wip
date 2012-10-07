# $NetBSD: Makefile,v 1.6 2012/10/07 13:57:32 asau Exp $
#

DISTNAME=	uuid-1.30
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://pypi.python.org/packages/source/u/uuid/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pypi.python.org/pypi/uuid/1.30
COMMENT=	UUID object and generation functions
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/uuid-1.30
USE_LANGUAGES=	# none

PYDISTUTILSPKG= yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
