# $NetBSD: Makefile,v 1.5 2012/11/23 22:33:57 othyro Exp $
#

DISTNAME=	pygts-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pygts/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pygts.sourceforge.net/
COMMENT=	Python bindings for GNU Triangulated Surface Library
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config
PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

DOCDIR=	${PREFIX}/share/doc/py-gts

INSTALLATION_DIRS=	${DOCDIR}

do-test:
	( cd ${WRKSRC}/test && ${PYTHONBIN} test.py )

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/gts.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.developers ${DESTDIR}${DOCDIR}

.include "../../lang/python/extension.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../graphics/gts/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
