# $NetBSD: Makefile,v 1.1 2015/01/03 12:40:10 jonthn Exp $

DISTNAME=	py-neovim-0.0.25
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py-//}
CATEGORIES=	devel editors
MASTER_SITES=	-https://github.com/neovim/python-client/archive/${PKGVERSION_NOREV}${EXTRACT_SUFX}

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
