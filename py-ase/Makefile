# $NetBSD: Makefile,v 1.2 2011/02/25 09:47:48 thomasklausner Exp $
#

DISTNAME=	python-ase-3.4.1.1765
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	biology python
MASTER_SITES=	https://wiki.fysik.dtu.dk/ase-files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://wiki.fysik.dtu.dk/ase/
COMMENT=	Atomic Simulation Environment
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

FETCH_USING=		wget
FETCH_BEFORE_ARGS=	--no-check-certificate

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 27 26 25 24
PYDISTUTILSPKG=	yes

.include "../../devel/py-ctypes/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/py-gobject/buildlink3.mk"
.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
#.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
