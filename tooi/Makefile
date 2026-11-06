# $NetBSD$

DISTNAME=	toot_tooi-0.28.0
PKGNAME=	${DISTNAME:S/toot_//}
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/toot-tooi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codeberg.org/ihabunek/tooi
COMMENT=	Text-based user interface for Mastodon, Pleroma and friends
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-aiodns>=3.3.0:../../net/py-aiodns
DEPENDS+=	${PYPKGPREFIX}-aiohttp>=3.8.0:../../www/py-aiohttp
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.10.0:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-certifi>=2022.12.07:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-click>=8.1.0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-html2text>=2024.2.25:../../textproc/py-html2text
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=4.0.0:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-pydantic>=2.0:../../devel/py-pydantic
DEPENDS+=	${PYPKGPREFIX}-rich>=14.2.0:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-textual>=7.3.0:../../comms/py-textual
DEPENDS+=	${PYPKGPREFIX}-textual-fspicker>=0.6.0:../../wip/py-textual-fspicker
DEPENDS+=	${PYPKGPREFIX}-textual-image>=0.7.0:../../wip/py-textual-image
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.12.0:../../textproc/py-tomlkit
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.4.0:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
