# $NetBSD$

DISTNAME=	python-lsp-server-1.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-lsp-server/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/python-lsp/python-lsp-server
COMMENT=	Python Language Server for the Language Server Protocol
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-jedi-[0-9]*:../../editors/py-jedi
DEPENDS+=	${PYPKGPREFIX}-pluggy>=1.0.0:../../devel/py-pluggy
DEPENDS+=	${PYPKGPREFIX}-ujson>=5.5.0:../../textproc/py-ujson
DEPENDS+=	${PYPKGPREFIX}-docstring-to-markdown-[0-9]*:../../wip/py-docstring-to-markdown
DEPENDS+=	${PYPKGPREFIX}-lsp-jsonrpc>=1.0.0:../../wip/py-lsp-jsonrpc

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
