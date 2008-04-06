# $NetBSD: Makefile,v 1.12 2008/04/06 22:22:34 bsadewitz Exp $

PKGNAME=	MesaLib-${MESA_PKGVERSION}
COMMENT=	Graphics library similar to SGI's OpenGL

MESA_HEADERS=	gl.h gl_mangle.h glext.h glx.h glxext.h glx_mangle.h \
		osmesa.h xmesa.h xmesa_x.h xmesa_xf86.h

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "x86_64" || ${MACHINE_ARCH} == "sparc64" || \
    ${MACHINE_ARCH} == "alpha" 
CFLAGS+= 	-D__GLX_ALIGN64
.endif

.include "../../wip/Mesa/Makefile.lib"

.include "options.mk"

.include "../../mk/pthread.buildlink3.mk"

.if !empty(MACHINE_PLATFORM:MNetBSD-[12].*)
.  include "../../devel/pthread-stublib/buildlink3.mk"
PTHREAD_STUBLIB= "-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -lpthstub"
.else
PTHREAD_STUBLIB= # provided by libc
.endif
PKGSRC_MAKE_ENV+=	PTHREAD_STUBLIB=${PTHREAD_STUBLIB}

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
MAKE_ENV+=	CROSS_COMPILING=yes
.endif

RM_PATCH_BACKUP_DIRS=	docs src/mesa src/glut/glx \
			progs/demos progs/xdemos progs/glsl
post-extract:
	${CP} ${FILESDIR}/gen_matypes.awk ${WRKSRC}/src/mesa/x86
	${CP} ${FILESDIR}/gen_matypes.sh ${WRKSRC}/src/mesa/x86
	${CHMOD} a+x ${WRKSRC}/src/mesa/x86/gen_matypes.sh
	@ for fn in ${RM_PATCH_BACKUP_DIRS}; do \
		${RM} -f ${WRKSRC}/$${fn}/*.orig; \
	 done

pre-build:
	cd ${WRKSRC} && ${RM} -fr src/glu src/glut progs

.include "../../mk/bsd.pkg.mk"
