# $NetBSD: Makefile,v 1.1.1.1 2003/11/26 16:24:23 mpasternak Exp $
#

DISTNAME=		pywm-0.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		wm
MASTER_SITES=		http://www.freenet.org.nz/python/pywm/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.freenet.org.nz/python/pywm/
COMMENT=		Window manager in Python

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

BUILD_DEPENDS=		${PYPKGPREFIX}-pyrex>=0.8.1:../../lang/py-pyrex

.include "../../lang/python/extension.mk"
.include "../../x11/fltk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
