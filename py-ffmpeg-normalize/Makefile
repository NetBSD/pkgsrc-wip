# $NetBSD$

DISTNAME=	ffmpeg-normalize-1.20.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	multimedia python
MASTER_SITES=	https://files.pythonhosted.org/packages/c9/26/0db7a2df2d792289d6ccbc068e0c25a7110643ffec71f86a6873df783dfc/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/slhck/ffmpeg-normalize
COMMENT=	Normalize audio via ffmpeg
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-tqdm>=4.38.0:../../misc/py-tqdm
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.3:../../comms/py-colorama

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
