# $NetBSD: Makefile,v 1.12 2010/01/03 16:07:03 pallegra Exp $

.include "../../wip/gl/version.mk"

DISTNAME=	Mesa-${MESA_PKGVERSION}
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Graphics library meta package, similar to SGI's OpenGL
CATEGORIES=	graphics

META_PACKAGE=	yes

CONFLICTS=	Mesa-glx-[0-9]*

DEPENDS+=	glx-utils-[0-9]*:../../wip/glx-utils

.include "../../wip/glut/buildlink3.mk"
.include "../../wip/glu/buildlink3.mk"
.include "../../wip/dri/buildlink3.mk"
.include "../../wip/glw/buildlink3.mk"
.include "../../wip/gl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
