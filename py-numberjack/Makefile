# $NetBSD$

DISTNAME=	Numberjack-1.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_PYPI:=N/Numberjack/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://numberjack.ucc.ie/
COMMENT=	Python platform for combinatorial optimization
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PYDISTUTILSPKG=	yes

PKGCONFIG_OVERRIDE+=	Numberjack/solvers/Mistral2/mistral/tools/tclap/tclap.pc.in

.include "../../devel/swig/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
