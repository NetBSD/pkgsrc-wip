# $NetBSD$

DISTNAME=	toot_tooi-0.16.3
PKGNAME=	${DISTNAME:S/toot_//}
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/toot-tooi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codeberg.org/ihabunek/tooi
COMMENT=	Text-based user interface for Mastodon, Pleroma and friends
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-aiodns-[0-9]*:../../net/py-aiodns
DEPENDS+=	${PYPKGPREFIX}-aiodns-[0-9]*:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-html2text-[0-9]*:../../textproc/py-html2text
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=4.0.0:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.0:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-textual>=6.0.0:../../comms/py-textual
DEPENDS+=	${PYPKGPREFIX}-textual-fspicker>=0.6.0:../../wip/py-textual-fspicker
DEPENDS+=	${PYPKGPREFIX}-textual-image>=0.7.0:../../wip/py-textual-image
DEPENDS+=	${PYPKGPREFIX}-tomlkit-[0-9]*:../../textproc/py-tomlkit

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
