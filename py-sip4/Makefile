# $NetBSD$

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/sip/sip4/}
COMMENT=	Tool to create Python bindings for C++ libraries

DISTNAME=	sip-4.19.25
CATEGORIES=	x11 devel python
MASTER_SITES=	https://www.riverbankcomputing.com/static/Downloads/sip/${PKGVERSION_NOREV}/
MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://riverbankcomputing.com/software/sip/

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

CONFIGURE_ARGS+=	-b ${PREFIX}/bin
CONFIGURE_ARGS+=	-d ${PREFIX}/${PYSITELIB}
CONFIGURE_ARGS+=	-e ${PREFIX}/${PYINC}
CONFIGURE_ARGS+=	-v ${PREFIX}/share/sip${PYVERSSUFFIX}
CONFIGURE_ARGS+=	CFLAGS=${CFLAGS:Q}
CONFIGURE_ARGS+=	CXXFLAGS=${CXXFLAGS:Q}
CONFIGURE_ARGS+=	INCDIR=${PREFIX}/include
CONFIGURE_ARGS+=	LIBDIR=${PREFIX}/lib

CONFIGURE_ARGS.DragonFly+=	-p freebsd-g++

PY_PATCHPLIST=		yes
#PYTHON_VERSIONS_INCOMPATIBLE+= 311 # as of 4.19.25

.include "../../mk/compiler.mk"

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	CFLAGS_SHLIB=-fno-common
CONFIGURE_ARGS+=	LFLAGS_PLUGIN="-bundle -flat_namespace -undefined suppress"
.else
CONFIGURE_ARGS+=	CFLAGS_SHLIB=-fPIC
CONFIGURE_ARGS+=	CXXFLAGS_SHLIB=-fPIC
.  if ${OPSYS} == "SunOS" && \
      (${CC_VERSION:Mgcc*} || !empty(PKGSRC_COMPILER:Mclang))
CONFIGURE_ARGS+=	-p solaris-g++
# gcc3 uses -mimpure-text to not pass -assert pure-text to the linker
CONFIGURE_ARGS+=	LFLAGS_SHLIB="-shared -mimpure-text"
.  else
CONFIGURE_ARGS+=	LFLAGS_SHLIB="-shared"
.  endif
.endif
CONFIGURE_ARGS+=	LFLAGS=${LDFLAGS:Q}

# Hack: gcc on sparc64 miscompiles sipgen/parser.c at -O2
.if ${MACHINE_ARCH} == "sparc64" && ${CC_VERSION:Mgcc*}
BUILDLINK_TRANSFORM+=	rm:-O2
.endif

SUBST_CLASSES+=		pyversfx
SUBST_STAGE.pyversfx=	pre-configure
SUBST_FILES.pyversfx=	sipgen/sipgen.sbf
SUBST_VARS.pyversfx=	PYVERSSUFFIX

PYTHON_VERSIONS_ACCEPTED=	311 312

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${PYTHONBIN} configure.py ${CONFIGURE_ARGS}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
