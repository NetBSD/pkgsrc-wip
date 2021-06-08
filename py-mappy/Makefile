# $NetBSD$

DISTNAME=	mappy-2.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	https://files.pythonhosted.org/packages/a2/d7/284160aed169db536db7ac823bddcf3c86d22258497ae0db28475c68330e/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lh3/minimap2
COMMENT=	Minimap2 python binding
LICENSE=	mit

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	share/examples/mappy

post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/minimap2.py
	${INSTALL_DATA} ${WRKSRC}/python/README.rst ${DESTDIR}${PREFIX}/share/examples/mappy

BUILDLINK_DEPENDS.py-cython+=	build
BUILDLINK_API_DEPENDS.py-cython+=	${PYPKGPREFIX}-cython>=0.29.23
.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
