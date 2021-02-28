# $NetBSD$

DISTNAME=	rich-9.12.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGVERSION=	1
CATEGORIES=	python comms
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rich/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/willmcgugan/rich
COMMENT=	Render rich text, tables, progress bars, syntax highlighting
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.0:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-commonmark>=0.9:../../textproc/py-commonmark
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.5.2:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.7.4:../../devel/py-typing-extensions


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
