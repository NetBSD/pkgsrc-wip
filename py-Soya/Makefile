# $NetBSD: Makefile,v 1.13 2006/06/12 16:28:59 thomasklausner Exp $
#

DISTNAME=		Soya-0.6.1
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://download.gna.org/soya/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://home.gna.org/oomadness/en/soya/index.html
COMMENT=		High level 3D engine for Python

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	23

.include "../../lang/python/extension.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/cal3d/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
