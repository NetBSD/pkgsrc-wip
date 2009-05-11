# $NetBSD: Makefile,v 1.3 2009/05/11 08:40:37 jihbed Exp $
#

DISTNAME=		pyosd-0.2.14
PKGNAME=		${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=		x11 python
MASTER_SITES=		http://ichi2.net/pyosd/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://ichi2.net/pyosd/
COMMENT=		Display text on an X11 display
LICENSE=		gnu-gpl-v2

DEPENDS+=		${PYPKGPREFIX}-twisted>=2.0.0:../../wip/py-twisted

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=		yes

.include "../../x11/xosd/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
