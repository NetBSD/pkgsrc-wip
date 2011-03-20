# $NetBSD: Makefile,v 1.1.1.1 2011/03/20 23:17:13 jihbed Exp $
#

DISTNAME=	chaos
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}-${VERSION}
CATEGORIES=	math
MASTER_SITES=	http://www.math.uic.edu/~culler/chaos/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.math.uic.edu/~culler/chaos/
COMMENT=	UIC REU on Chaos, Fractals and Complex Dynamics
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

VERSION=	1.0
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
