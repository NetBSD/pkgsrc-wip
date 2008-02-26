# $NetBSD: Makefile,v 1.4 2008/02/26 06:47:37 bsadewitz Exp $

PKGNAME=	glut-${MESA_PKGVERSION}
COMMENT=	GLUT Graphics library similar to SGI's OpenGL

CONFLICTS+=	Mesa-glx-[0-9]*
CONFLICTS+=	Mesa<3.2.1

.include "../../wip/Mesa/Makefile.lib"

BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=${MESA_PKGVERSION}
BUILDLINK_API_DEPENDS.glu+=	glu>=${MESA_PKGVERSION}

.include "../../wip/MesaLib/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../wip/glu/buildlink3.mk"

pre-build:
	cd ${WRKSRC} && ${RM} -fr src/mesa src/glu src/glw progs

.include "../../mk/bsd.pkg.mk"
