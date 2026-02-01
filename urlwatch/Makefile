# $NetBSD: Makefile,v 1.1 2015/08/18 18:36:32 yhardy Exp $

DISTNAME=	urlwatch-2.29
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=thp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/thp/urlwatch
COMMENT=	Watch web pages and arbitrary URLs for changes
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-appdirs-[0-9]*:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-codestyle-[0-9]*:../../devel/py-codestyle
DEPENDS+=	${PYPKGPREFIX}-cssselect-[0-9]*:../../textproc/py-cssselect
DEPENDS+=	${PYPKGPREFIX}-keyring-[0-9]*:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-minidb-[0-9]*:../../wip/py-minidb
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.32:../../devel/py-wheel

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 share/doc/${PKGBASE}

# no support for 2.x
PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
