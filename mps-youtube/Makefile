# $NetBSD: Makefile,v 1.1 2015/02/14 12:27:21 jihbed Exp $

DISTNAME=	mps-youtube-0.2.2
CATEGORIES=	multimedia net python
MASTER_SITES=	https://pypi.python.org/packages/source/m/mps-youtube/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/np1/mps-youtube
COMMENT=	Terminal based YouTube player and downloader
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-pafy>=0.3.72:../../wip/py-pafy

WRKSRC=		${WRKDIR}/mps-youtube-0.2.2

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
