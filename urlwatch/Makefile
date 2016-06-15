# $NetBSD: Makefile,v 1.1 2015/08/18 18:36:32 yhardy Exp $

DISTNAME=	urlwatch-2.2
CATEGORIES=	net
MASTER_SITES=	http://thp.io/2008/urlwatch/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://thp.io/2008/urlwatch/
COMMENT=	Watch web pages and arbitrary URLs for changes
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-minidb-[0-9]*:../../wip/py-minidb
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	${PKGMANDIR}/man1 share/doc/${PKGBASE}

# no support for 2.x
PYTHON_VERSIONS_INCOMPATIBLE=	27

pre-configure:
	cd ${WRKSRC} && ${MKDIR} -p share/examples \
	             && ${MV} share/urlwatch/examples share/examples/urlwatch \
	             && ${RMDIR} share/urlwatch

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/urlwatch.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
