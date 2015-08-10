# $NetBSD: Makefile,v 1.5 2015/08/10 22:59:31 jonthn Exp $

DISTNAME=	py-neovim-0.0.38
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
