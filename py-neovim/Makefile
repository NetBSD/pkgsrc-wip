# $NetBSD: Makefile,v 1.5 2015/08/10 22:59:31 jonthn Exp $

DISTNAME=	py-neovim-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py-//}
CATEGORIES=	devel editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=neovim/}
GITHUB_PROJECT=	pynvim

HOMEPAGE=	https://github.com/neovim/pynvim
COMMENT=	Python client to Neovim
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/pynvim-${PKGVERSION_NOREV}
EGG_NAME=	pynvim-${PKGVERSION_NOREV}

PYTHON_VERSIONS_INCOMPATIBLE=	31 32 33

DEPENDS+=	${PYPKGPREFIX}-msgpack-[0-9]*:../../devel/py-msgpack
DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
