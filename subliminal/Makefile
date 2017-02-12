# $NetBSD$

DISTNAME=	subliminal-2.0.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=s/subliminal/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Diaoul/subliminal/
COMMENT=	Video subtitles downloader
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-appdirs>=1.3:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-babelfish>=0.5.2:../../wip/py-babelfish
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.4.0:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-chardet>=2.3.0:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-click>=4.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-dogpile-cache>=0.6.0:../../wip/py-dogpile-cache
DEPENDS+=	${PYPKGPREFIX}-enzyme>=0.4.1:../../wip/py-enzyme
DEPENDS+=	${PYPKGPREFIX}-pysrt>=1.0.1:../../wip/py-pysrt
DEPENDS+=	${PYPKGPREFIX}-pytz>=2012c:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-rarfile>=2.7:../../wip/py-rarfile
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-stevedore>=1.0.0:../../wip/py-stevedore
DEPENDS+=	guessit>=2.0.1:../../wip/guessit

.include "../../lang/python/egg.mk"

.if ${_PYTHON_VERSION} < 33
DEPENDS+=	${PYPKGPREFIX}-futures>=3.0:../../devel/py-futures
.endif

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
