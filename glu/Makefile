# $NetBSD: Makefile,v 1.4 2008/03/03 04:13:21 bsadewitz Exp $

PKGNAME=	glu-${MESA_PKGVERSION}
COMMENT=	GLU polygon tessellation facility for Mesa

CONFLICTS+=	Mesa-glx-[0-9]*
CONFLICTS+=	Mesa<3.2.1

MESA_HEADERS= 	glu.h glu_mangle.h

.include "../../wip/Mesa/Makefile.lib"

BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=${MESA_VERSION}
.include "../../wip/MesaLib/buildlink3.mk"

pre-build:
	cd ${WRKSRC} && ${RM} -fr src/mesa src/glut src/glw progs

.include "../../mk/bsd.pkg.mk"
