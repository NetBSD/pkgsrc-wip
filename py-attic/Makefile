# $NetBSD: Makefile,v 1.2 2015/03/18 09:49:07 thomasklausner Exp $

DISTNAME=	Attic-0.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/A/a/}
CATEGORIES=	sysutils
MASTER_SITES=	https://pypi.python.org/packages/source/A/Attic/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://attic-backup.org/
COMMENT=	Deduplicating backup program
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-msgpack-[0-9]*:../../devel/py-msgpack

# missing xattr support; packages, but does not run
NOT_FOR_PLATFORM=	NetBSD-*-*

PYTHON_VERSIONS_INCOMPATIBLE=	26 27
PLIST_SUBST+=			PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	cd ${DESTDIR}${PREFIX}/bin && mv attic attic${PYVERSSUFFIX}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
