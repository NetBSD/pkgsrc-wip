# $NetBSD: Makefile,v 1.5 2008/03/03 04:14:40 bsadewitz Exp $

PKGNAME=	MesaLib-${MESA_PKGVERSION}
COMMENT=	Graphics library similar to SGI's OpenGL


MESA_HEADERS=	gl.h gl_mangle.h glext.h glx.h glxext.h glx_mangle.h	\
		osmesa.h xmesa.h xmesa_x.h xmesa_xf86.h

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

RM_PATCH_BACKUP_DIRS= 	docs src/mesa src/glut/glx \
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

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/GL
	cd ${WRKSRC}/include/GL; for hdr in				\
	do								\
		${INSTALL_DATA} $${hdr} ${DESTDIR}${PREFIX}/include/GL;	\
	done
.endif

.include "../../mk/bsd.pkg.mk"
