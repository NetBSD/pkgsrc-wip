# $NetBSD: Makefile,v 1.1 2007/04/25 07:07:58 bsadewitz Exp $
#

DISTNAME=	beryl-settings-bindings-${BERYL_VERSION}
CATEGORIES=	wm

COMMENT=	Beryl settings bindings

.include "../../wip/beryl/Makefile.inc"

PKGCONFIG_OVERRIDE+=	beryl-settings-bindings.pc.in

DEPENDS+=	${PYPKGPREFIX}-pyrex>=0.9:../../lang/py-pyrex

PYTHON_VERSION_REQD=	24
PYBINMODULE=	YES
PY_PATCHPLIST=	YES

.include "../../lang/python/extension.mk"

.include "../../wip/beryl-core/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
