# $NetBSD: Makefile,v 1.16 2013/12/31 18:29:37 othyro Exp $
#

DISTNAME=	pycsp-complete-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-complete//1}
CATEGORIES=	devel python
MASTER_SITES=	http://pycsp.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/pycsp/
COMMENT=	Brings CSP (communicating sequential processes) to Python
LICENSE=	mit

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV:S/${PYPKGPREFIX}-//1}
EGDIR=			${PREFIX}/share/examples/py-csp
EGG_NAME=		${DISTNAME:S/-complete//1}
INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/test/*.py ${DESTDIR}${EGDIR}

DEPENDS+=	${PYPKGPREFIX}-Pyro4>=3.4:../../devel/py-Pyro
DEPENDS+=	${PYPKGPREFIX}-greenlet>=0.2:../../devel/py-greenlet
DEPENDS+=	${PYPKGPREFIX}-uuid>=1.30:../../wip/py-uuid
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
