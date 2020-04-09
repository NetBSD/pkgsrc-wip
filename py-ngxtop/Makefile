# $NetBSD$

DISTNAME= 	ngxtop	
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=lebinh/}
GITHUB_TAG=     0.0.2
EXTRACT_SUFX=	.zip
CATEGORIES= 	sysutils

MAINTAINER=	kethzer.dr@gmail.com	
HOMEPAGE=	https://github.com/lebinh/
COMMENT=	real-time metrics for nginx server
LICENSE=	mit	


#PYTHON_VERSIONS_ACCEPTED=      27

WRKSRC=         ${WRKDIR}/${DISTNAME}-${GITHUB_TAG}

DEPENDS+=       ${PYPKGPREFIX}-docopt>=0.6.2:../../devel/py-docopt
DEPENDS+=       ${PYPKGPREFIX}-tabulate>=0.8.6:../../textproc/py-tabulate
DEPENDS+=       ${PYPKGPREFIX}-pyparsing>=2.4.5:../../devel/py-pyparsing
DEPENDS+=       ${PYPKGPREFIX}-curses>=3.7.6:../../devel/py-curses
DEPENDS+=       ${PYPKGPREFIX}-sqlite3>=3.7.6:../../databases/py-sqlite3 


post-install:
	${CP} -r ${WRKDIR}/.destdir/usr/pkg/bin/ngxtop ${PREFIX}/bin

.include "../../lang/python/egg.mk"
# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
