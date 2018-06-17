# $NetBSD$

DISTNAME=	tootstream-0.3.4
CATEGORIES=	www chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=magicalraccoon/}

HOMEPAGE=	https://github.com/magicalraccoon/tootstream
COMMENT=	Command line interface for interacting with Mastodon instances
LICENSE=	mit

EXTRACT_USING=	bsdtar
USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-colored-[0-9]*:../../wip/py-colored # XXX
DEPENDS+=	${PYPKGPREFIX}-emoji-[0-9]*:../../wip/py-emoji # XXX
DEPENDS+=	${PYPKGPREFIX}-humanize-[0-9]*:../../textproc/py-humanize
DEPENDS+=	${PYPKGPREFIX}-Mastodon.py-[0-9]*:../../wip/py-Mastodon.py # XXX
DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
