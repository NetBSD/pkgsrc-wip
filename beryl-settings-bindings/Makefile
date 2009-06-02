# $NetBSD: Makefile,v 1.3 2009/06/02 12:18:01 noud4 Exp $
#

DISTNAME=	beryl-settings-bindings-${BERYL_VERSION}
CATEGORIES=	wm

COMMENT=	Beryl settings bindings

.include "../../wip/beryl/Makefile.inc"

PKGCONFIG_OVERRIDE+=	beryl-settings-bindings.pc.in

DEPENDS+=	${PYPKGPREFIX}-pyrex>=0.9:../../lang/py-pyrex

PYTHON_VERSION_REQD=	25
PYBINMODULE=	YES
PY_PATCHPLIST=	YES

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-[3-4]*)
CFLAGS+= -fno-strict-aliasing
.endif

.include "../../lang/python/extension.mk"

.include "../../wip/beryl-core/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
