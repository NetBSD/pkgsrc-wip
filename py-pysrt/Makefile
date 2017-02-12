# $NetBSD$

DISTNAME=	pysrt-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pysrt/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/byroot/pysrt
COMMENT=	Python parser for SubRip (srt) files
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
