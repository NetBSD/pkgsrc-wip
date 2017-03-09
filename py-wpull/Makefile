# $NetBSD$

GITHUB_PROJECT=	wpull
DISTNAME=	wpull-2.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=chfoo/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/chfoo/wpull/
COMMENT=	Wget-compatible web downloader and crawler
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-yapsy-[0-9]*:../../wip/py-yapsy
DEPENDS+=	${PYPKGPREFIX}-tornado-[0-9]*:../../www/py-tornado
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-[0-9]*:../../databases/py-sqlalchemy
DEPENDS+=	${PYPKGPREFIX}-namedlist-[0-9]*:../../wip/py-namedlist
DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-dnspython3-[0-9]*:../../wip/py-dnspython3
DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
