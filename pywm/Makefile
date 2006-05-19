# $NetBSD: Makefile,v 1.5 2006/05/19 16:51:35 ykomatsu Exp $
#

DISTNAME=		pywm-0.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		wm
MASTER_SITES=		http://www.freenet.org.nz/python/pywm/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.freenet.org.nz/python/pywm/
COMMENT=		Window manager in Python

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

BUILD_DEPENDS=		${PYPKGPREFIX}-pyrex>=0.8.1:../../lang/py-pyrex

.include "../../lang/python/extension.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
