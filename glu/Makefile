# $NetBSD: Makefile,v 1.3 2008/02/26 06:47:37 bsadewitz Exp $

PKGNAME=	glu-${MESA_PKGVERSION}
COMMENT=	GLU polygon tessellation facility for Mesa

CONFLICTS+=	Mesa-glx-[0-9]*
CONFLICTS+=	Mesa<3.2.1

.include "../../wip/Mesa/Makefile.lib"

INSTLIBS=	${WRKSRC}/src/glu/sgi/libGLU.la

BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=${MESA_VERSION}
.include "../../wip/MesaLib/buildlink3.mk"

pre-build:
	cd ${WRKSRC} && ${RM} -fr src/mesa src/glut src/glw progs

.include "../../mk/bsd.pkg.mk"
