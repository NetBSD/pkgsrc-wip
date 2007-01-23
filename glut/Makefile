# $NetBSD: Makefile,v 1.1 2007/01/23 17:53:42 bsadewitz Exp $

PKGNAME=	glut-${MESA_VERSION}
COMMENT=	GLUT Graphics library similar to SGI's OpenGL

CONFLICTS+=	Mesa-glx-[0-9]*
CONFLICTS+=	Mesa<3.2.1

.include "../../wip/Mesa/Makefile.lib"

BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=${MESA_VERSION}
BUILDLINK_API_DEPENDS.glu+=	glu>=${MESA_VERSION}

INSTLIBS=	${WRKSRC}/src/glut/glx/libglut.la

.include "../../wip/MesaLib/buildlink3.mk"
.include "../../wip/libX11/buildlink3.mk"
.include "../../wip/libXt/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../wip/libXi/buildlink3.mk"
.include "../../wip/glu/buildlink3.mk"

pre-build:
	cd ${WRKSRC} && ${RM} -fr src/mesa src/glu src/glw progs

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/GL
	cd ${WRKSRC}/include/GL; for hdr in				\
		glut.h glutf90.h;					\
	do								\
		${INSTALL_DATA} $${hdr} ${DESTDIR}${PREFIX}/include/GL;	\
	done

.include "../../mk/bsd.pkg.mk"
