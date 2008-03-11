# $NetBSD: Makefile,v 1.8 2008/03/11 05:27:38 tnn2 Exp $

PKGNAME=	glut-${MESA_PKGVERSION}
COMMENT=	GLUT Graphics library similar to SGI's OpenGL

CONFLICTS+=	Mesa-glx-[0-9]*
CONFLICTS+=	Mesa<3.2.1

MESA_HEADERS=	glut.h glutf90.h

.include "../../wip/Mesa/Makefile.lib"

BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=${MESA_PKGVERSION}
BUILDLINK_API_DEPENDS.glu+=	glu>=${MESA_PKGVERSION}

.include "../../wip/MesaLib/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../wip/glu/buildlink3.mk"

pre-build:
	cd ${WRKSRC} && ${RM} -fr src/mesa src/glu src/glx src/glw progs
###	XXX why is this needed?
	mkdir -p ${WRKSRC}/src/glut/lib

.include "../../mk/bsd.pkg.mk"
