# $NetBSD: Makefile,v 1.1 2015/08/18 18:36:32 yhardy Exp $

DISTNAME=	urlwatch-2.7
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=thp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/thp/urlwatch
COMMENT=	Watch web pages and arbitrary URLs for changes
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-appdirs-[0-9]*:../../devel/py-appdirs
DEPENDS+=	${PYPKGPREFIX}-minidb-[0-9]*:../../wip/py-minidb
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 share/doc/${PKGBASE}

# no support for 2.x
PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
