# $NetBSD$

DISTNAME=	gef-2021.10
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=hugsy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hugsy/gef/
COMMENT=	Modern experience for GDB with advanced debugging features
LICENSE=	mit

USE_TOOLS+=	pax

DEPENDS+=	gdb>=7.7:../../devel/gdb
DEPENDS+=	${PYPKGPREFIX}-capstone-[0-9]*:../../devel/py-capstone
DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-keystone-[0-9]*:../../emulators/py-keystone
DEPENDS+=	${PYPKGPREFIX}-pylint-[0-9]*:../../devel/py-pylint
DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
DEPENDS+=	ropper-[0-9]*:../../devel/ropper
DEPENDS+=	${PYPKGPREFIX}-unicorn-[0-9]*:../../emulators/py-unicorn

PYTHON_VERSIONS_INCOMPATIBLE=	27

NO_BUILD=	yes

INSTALLATION_DIRS+=	lib/${PKGBASE}
INSTALLATION_DIRS+=	share/doc/${PKGBASE}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gef.py \
		${DESTDIR}${PREFIX}/lib/${PKGBASE}/gef.py
	${RUN} cd ${WRKDIR}/${DISTNAME}/docs && \
		${PAX} -wr * ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
