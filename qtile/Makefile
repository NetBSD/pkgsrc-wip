# $NetBSD$

DISTNAME=	qtile-0.11.1
CATEGORIES=	wm python
MASTER_SITES=	${MASTER_SITE_GITHUB:=qtile/}
GITHUB_PROJECT=	qtile
GITHUB_TAG=	v${PKGVERSION_NOREV}

HOMEPAGE=	http://www.qtile.org/
COMMENT=	Fully-featured, pure-Python tiling window manager
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-cairocffi-[0-9]*:../../graphics/py-cairocffi
DEPENDS+=	${PYPKGPREFIX}-xcffib-[0-9]*:../../wip/py-xcffib # XXX
.if ${PYVERSSUFFIX} == 2.7
DEPENDS+=	${PYPKGPREFIX}-futures-[0-9]*:../../devel/py-futures
.endif
DEPENDS+=	${PYPKGPREFIX}-trollius-[0-9]*:../../wip/py-trollius # XXX

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
