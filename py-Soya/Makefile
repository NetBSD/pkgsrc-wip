# $NetBSD: Makefile,v 1.1.1.1 2003/11/05 04:10:14 mpasternak Exp $
#

DISTNAME=		Soya-0.5.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel
MASTER_SITES=		http://oomadness.tuxfamily.org/downloads/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://oomadness.tuxfamily.org/en/soya/
COMMENT=		High level 3D engine for Python

USE_BUILDLINK2=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	23pth

.include "../../lang/python/extension.mk"
.include "../../graphics/Mesa/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../wip/cal3d/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
