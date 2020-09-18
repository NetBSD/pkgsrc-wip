# $NetBSD: Makefile,v 1.10 2018/05/06 22:20:22 khorben Exp $

DISTNAME=	manticore-${GITHUB_TAG}
PKGNAME=	${PYPKGPREFIX}-${EGG_NAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=trailofbits/}
GITHUB_PROJECT=	manticore
GITHUB_TAG=	0.3.4

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/trailofbits/manticore/
COMMENT=	Symbolic execution tool for analysis of binaries and smart contracts
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PYPKGPREFIX}-capstone-[0-9]*:../../devel/py-capstone
DEPENDS+=	${PYPKGPREFIX}-rlp-[0-9]*:../../wip/py-rlp
DEPENDS+=	${PYPKGPREFIX}-ply-[0-9]*:../../devel/py-ply
DEPENDS+=	${PYPKGPREFIX}-pyelftools-[0-9]*:../../devel/py-pyelftools
DEPENDS+=	${PYPKGPREFIX}-pysha3-[0-9]*:../../devel/py-pysha3
DEPENDS+=	${PYPKGPREFIX}-unicorn-[0-9]*:../../emulators/py-unicorn
DEPENDS+=	${PYPKGPREFIX}-crytic-compile-[0-9]*:../../wip/py-crytic-compile
DEPENDS+=	${PYPKGPREFIX}-pyevmasm-[0-9]*:../../wip/py-pyevmasm
DEPENDS+=	${PYPKGPREFIX}-z3-[0-9]*:../../math/py-z3
DEPENDS+=	${PYPKGPREFIX}-prettytable-[0-9]*:../../wip/py-prettytable
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

PYTHON_VERSIONS_ACCEPTED=	37 36

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
