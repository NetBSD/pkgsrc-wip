# $NetBSD: Makefile,v 1.1 2007/01/23 17:51:59 bsadewitz Exp $

PKGNAME=	glu-${MESA_VERSION}
COMMENT=	GLU polygon tessellation facility for Mesa

CONFLICTS+=	Mesa-glx-[0-9]*
CONFLICTS+=	Mesa<3.2.1

.include "../../wip/Mesa/Makefile.lib"

INSTLIBS=	${WRKSRC}/src/glu/sgi/libGLU.la

BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=${MESA_VERSION}
.include "../../wip/MesaLib/buildlink3.mk"

pre-build:
	cd ${WRKSRC} && ${RM} -fr src/mesa src/glut src/glw progs

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/GL
	cd ${WRKSRC}/include/GL; for hdr in				\
		glu.h glu_mangle.h;					\
	do								\
		${INSTALL_DATA} $${hdr} ${DESTDIR}${PREFIX}/include/GL;	\
	done

.include "../../mk/bsd.pkg.mk"
