# $NetBSD: Makefile,v 1.4 2004/01/09 05:14:02 mpasternak Exp $
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
.if exists(../../mk/opengl.buildlink2.mk") # see PR #23845 for details
.include "../../mk/opengl.buildlink2.mk"
.else
.include "../../graphics/MesaLib/buildlink2.mk"
.endif
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../wip/cal3d/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
