# $NetBSD: Makefile,v 1.3 2004/01/02 03:06:31 mpasternak Exp $
#

DISTNAME=		Soya-0.6.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://oomadness.tuxfamily.org/downloads/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://oomadness.tuxfamily.org/en/soya/index.html
COMMENT=		High level 3D engine for Python

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	23pth

.include "../../lang/python/extension.mk"
.include "../../mk/opengl.buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../wip/cal3d/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
