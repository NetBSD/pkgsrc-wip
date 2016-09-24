# $NetBSD: Makefile,v 1.16 2013/12/31 18:29:37 othyro Exp $
#

DISTNAME=	pycsp-0.9.2
GITHUB_PROJECT=	pycsp
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=runefriborg/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/pycsp/
COMMENT=	Brings CSP (communicating sequential processes) to Python
LICENSE=	mit

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
