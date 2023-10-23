# $NetBSD$

DISTNAME=       ngxtop-0.0.2
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
MASTER_SITES=   ${MASTER_SITE_PYPI:=n/ngxtop/}
CATEGORIES= 	sysutils

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/lebinh/
COMMENT=	real-time metrics for nginx server
LICENSE=	mit

DEPENDS+=       ${PYPKGPREFIX}-docopt>=0.6.2:../../devel/py-docopt
DEPENDS+=       ${PYPKGPREFIX}-tabulate>=0.8.3:../../textproc/py-tabulate
DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing

WRKSRC=         ${WRKDIR}/${DISTNAME}-${GITHUB_TAG}

post-install:
	${CP} -r ${WRKDIR}/.destdir/usr/pkg/bin/ngxtop ${PREFIX}/bin

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
