# $NetBSD$

DISTNAME=	cutadapt-3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cutadapt/}

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	https://cutadapt.readthedocs.io/en/stable/
COMMENT=	Find and remove adapter sequences, primers, poly-A tails, etc
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-xopen>=0.8.2:../../devel/py-xopen
DEPENDS+=	${PYPKGPREFIX}-dnaio>=0.3:../../wip/py-dnaio

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
