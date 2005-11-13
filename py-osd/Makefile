# $NetBSD: Makefile,v 1.1.1.1 2005/11/13 05:56:49 dhowland Exp $
#

DISTNAME=		pyosd-0.2.14
PKGNAME=		${PYPKGPREFIX}-osd-0.2.14
CATEGORIES=		x11 python
MASTER_SITES=		http://repose.cx/pyosd/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://repose.cx/pyosd/
COMMENT=		Display text on an X11 display

DEPENDS+=               ${PYPKGPREFIX}-twisted>=2.0.0:../../wip/py-twisted

PYDISTUTILSPKG=		yes
PYBINMODULE=		yes

.include "../../x11/xosd/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
