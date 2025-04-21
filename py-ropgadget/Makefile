# $NetBSD$

DISTNAME=	ropgadget-7.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=R/ROPGadget/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/JonathanSalwan/ROPgadget
COMMENT=	Search gadgets on binaries to facilitate ROP exploitation
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-capstone>=5.0.1:../../devel/py-capstone

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/ROPgadget ${DESTDIR}${PREFIX}/bin/ROPgadget${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
