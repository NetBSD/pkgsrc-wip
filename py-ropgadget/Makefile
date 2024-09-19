# $NetBSD$

DISTNAME=	ROPGadget-6.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=R/ROPGadget/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/JonathanSalwan/ROPgadget
COMMENT=	Search gadgets on binaries to facilitate ROP exploitation
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-capstone-[0-9]*:../../devel/py-capstone

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/ROPgadget ${DESTDIR}${PREFIX}/bin/ROPgadget${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
