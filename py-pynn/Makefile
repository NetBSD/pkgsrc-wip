# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:44 thomasklausner Exp $

DISTNAME=	PyNN-0.9.2
PKGNAME=	${PYPKGPREFIX}-pynn-0.9.2
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyNN/}
LICENSE=	cecill-2.1

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://neuralensemble.org/trac/PyNN/wiki
COMMENT=	Python package for neuronal network models

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

INSTALLATION_DIRS=	share/doc/py-pynn

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DESTDIR}${PREFIX}/share/doc/py-pynn

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
