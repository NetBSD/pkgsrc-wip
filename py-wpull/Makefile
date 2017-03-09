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

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
