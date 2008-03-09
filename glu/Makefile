# $NetBSD: Makefile,v 1.6 2008/03/09 12:46:54 tnn2 Exp $

PKGNAME=	glu-${MESA_PKGVERSION}
COMMENT=	GLU polygon tessellation facility for Mesa

CONFLICTS+=	Mesa-glx-[0-9]*
CONFLICTS+=	Mesa<3.2.1

MESA_HEADERS=	glu.h glu_mangle.h

.include "../../wip/Mesa/Makefile.lib"

BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=${MESA_VERSION}
.include "../../wip/MesaLib/buildlink3.mk"

pre-build:
	cd ${WRKSRC} && ${RM} -fr src/glx src/mesa src/glut src/glw progs

.include "../../mk/bsd.pkg.mk"
