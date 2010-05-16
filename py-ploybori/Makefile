# $NetBSD: Makefile,v 1.1.1.1 2010/05/16 15:58:17 jihbed Exp $
#

DISTNAME=	polybori-0.6-3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://garr.dl.sourceforge.net/project/polybori/polybori/0.6.3/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://polybori.sourceforge.net/
COMMENT=	Polynomials over Boolean Rings, Python module
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	scons-[0-9]*:../../devel/scons
DEPENDS+=	${PYPKGPREFIX}-jinja>=1.2:../../textproc/py-jinja
DEPENDS+=	${PYPKGPREFIX}-genshi>=0.5.1:../../www/py-genshi

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/polybori-0.6
USE_TOOLS+=	bash:run
USE_LANGUAGES=	c c++

GCC_REQD+=	3.3

REPLACE_BASH+=	ipbori/ipbori

PYTHON_VERSIONS_ACCEPTED= 26 25 24

EDGDIR=	${PREFIX}/share/examples/py-polybori

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${EDGDIR}

do-build:
	cd ${WRKSRC}					\
	&& ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons

do-install:
	${INSTALL_DATA} ${WRKSRC}/ipbori/ipbori ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/ipbori/ipythonrc-polybori \
		${DESTDIR}${PREFIX}/share/examples/py-polybori
	${INSTALL_MAN} ${WRKSRC}/doc/man/ipbori.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1


.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-python/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
