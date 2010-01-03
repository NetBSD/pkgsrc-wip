# $NetBSD: Makefile,v 1.15 2010/01/03 15:52:45 pallegra Exp $

.include "../../wip/gl/version.mk"

DISTNAME=	MesaLib-${MESA_PKGVERSION}
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Graphics library meta package, similar to SGI's OpenGL
CATEGORIES=	graphics

META_PACKAGE=	yes

CONFLICTS=	Mesa-glx-[0-9]*

.include "../../wip/dri/buildlink3.mk"
.include "../../wip/glw/buildlink3.mk"
.include "../../wip/gl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
