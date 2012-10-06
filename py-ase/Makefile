# $NetBSD: Makefile,v 1.6 2012/10/06 17:13:31 asau Exp $
#

DISTNAME=	python-ase-3.4.1.1765
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	2
CATEGORIES=	biology python
MASTER_SITES=	https://wiki.fysik.dtu.dk/ase-files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://wiki.fysik.dtu.dk/ase/
COMMENT=	Atomic Simulation Environment
LICENSE=	gnu-lgpl-v2.1

FETCH_USING=		wget
FETCH_BEFORE_ARGS=	--no-check-certificate

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../devel/pango/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
#.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
