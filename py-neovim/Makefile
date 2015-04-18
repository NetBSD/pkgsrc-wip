# $NetBSD: Makefile,v 1.3 2015/04/18 15:35:19 jonthn Exp $

DISTNAME=	py-neovim-0.0.34
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py-//}
CATEGORIES=	devel editors
MASTER_SITES=	${MASTER_SITE_GITHUB:=neovim/}
GITHUB_PROJECT=	python-client

HOMEPAGE=	https://github.com/neovim/python-client
COMMENT=	Python client to Neovim
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/python-client-${PKGVERSION_NOREV}

EGG_NAME=	${DISTNAME:S/-/_/}

DEPENDS+=       ${PYPKGPREFIX}-msgpack:../../devel/py-msgpack
DEPENDS+=       ${PYPKGPREFIX}-greenlet:../../devel/py-greenlet
DEPENDS+=       ${PYPKGPREFIX}-trollius:../../wip/py-trollius

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
