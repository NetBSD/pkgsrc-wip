# $NetBSD: Makefile,v 1.4 2015/06/23 21:41:02 jonthn Exp $

DISTNAME=	py-neovim-0.0.36
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py-//}
CATEGORIES=	devel editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=neovim/}
GITHUB_PROJECT=	python-client

HOMEPAGE=	https://github.com/neovim/python-client
COMMENT=	Python client to Neovim
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/python-client-${PKGVERSION_NOREV}
EGG_NAME=	neovim-${PKGVERSION_NOREV}

DEPENDS+=       ${PYPKGPREFIX}-msgpack:../../devel/py-msgpack
DEPENDS+=       ${PYPKGPREFIX}-greenlet:../../devel/py-greenlet
DEPENDS+=       ${PYPKGPREFIX}-trollius:../../wip/py-trollius

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
