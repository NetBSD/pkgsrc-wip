
SUBST_CLASSES+=		fix-conf
SUBST_STAGE.fix-conf=	pre-patch
SUBST_MESSAGE.fix-conf=	Fixing configuration files
SUBST_FILES.fix-conf=	configs/netbsd-dri
SUBST_FILES.fix-conf+=	configs/netbsd-dri-x86
SUBST_FILES.fix-conf+=	configs/netbsd-dri-amd64
SUBST_FILES.fix-conf+=	configs/netbsd
SUBST_FILES.fix-conf+=	configs/default
SUBST_SED.fix-conf=	-e 's,FreeBSD,NetBSD,g'
SUBST_SED.fix-conf+=	-e 's,freebsd,netbsd,g'
SUBST_SED.fix-conf+=	-e 's,/usr/X11R6,${PREFIX},g'
SUBST_SED.fix-conf+=	-e 's,-DHAVE_POSIX_MEMALIGN,,g'
SUBST_SED.fix-conf+=	-e 's,/usr/local,${PREFIX},g'
SUBST_SED.fix-conf+=	-e 's,gcc,${CC},g'
SUBST_SED.fix-conf+=	-e 's,g++,${CXX},g'
SUBST_SED.fix-conf+=	-e 's,OPT_FLAGS = .*,OPT_FLAGS = ${CFLAGS},g'
SUBST_SED.fix-conf+=	-e 's,-lpthread,,g'
SUBST_SED.fix-conf+=	-e 's,SRC_DIRS = .*,SRC_DIRS = glx/x11 mesa glw,g'
SUBST_SED.fix-conf+=	-e 's,^\(MKDEP_OPTIONS.*\),\1 -- -I${PREFIX}/include --,'
#SUBST_SED.fix-conf+=	-e 's,-ffast-math,,g'
SUBST_SED.fix-conf+=	-e 's,^\(DRI_DIRS.*\\\),,g'
SUBST_SED.fix-conf+=	-e 's,\(unichrome.*\),,g'
SUBST_SED.fix-conf+=	-e 's,-l$$(GL_LIB),-lGL,g'
#SUBST_SED.fix-conf+=	-e 's,-L,-R,g'
SUBST_SED.fix-conf+=	-e 's,-fPIC,,g'
SUBST_SED.fix-conf+=	-e 's,-DPIC,,g'
SUBST_SED.fix-conf+=	-e 's|^DRI_DRIVER_INSTALL_DIR.*|DRI_DRIVER_INSTALL_DIR = ${PREFIX}/${DRI_MODULE_PATH}|'

SUBST_CLASSES+=		fix-pthread
SUBST_STAGE.fix-pthread= pre-patch
SUBST_MESSAGE.fix-pthread= Eliminating pthread links
SUBST_FILES.fix-pthread=src/mesa/drivers/dri/glcore/Makefile
SUBST_FILES.fix-pthread+=${SUBST_FILES.fix-conf}
SUBST_SED.fix-pthread+= -e "s,-lpthread,,g"

SUBST_CLASSES+=		pkg-config
SUBST_STAGE.pkg-config=	pre-patch
SUBST_MESSAGE.pkg-config=Substituting back-quoted pkg-config flags
SUBST_FILES.pkg-config=	${SUBST_FILES.fix-conf}
SUBST_FILES.pkg-config+=	src/mesa/drivers/dri/Makefile.template
SUBST_SED.pkg-config=	-e 's,`pkg-config --cflags libdrm`,-I${BUILDLINK_PREFIX.libdrm}/include/drm,g'
SUBST_SED.pkg-config+=	-e 's,`pkg-config --libs libdrm`,-ldrm,g'
