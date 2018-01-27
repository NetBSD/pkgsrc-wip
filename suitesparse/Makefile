# $NetBSD: Makefile,v 1.12 2012/11/28 21:43:05 outpaddling Exp $
# FreeBSD Id: ports/math/suitesparse/Makefile,v 1.38 2011/07/20 16:17:35 bf Exp

# DISTNAME=	SuiteSparse-3.6.1
# PKGNAME=	suitesparse-3.6.1
DISTNAME=	SuiteSparse-4.0.2
PKGNAME=	suitesparse-4.0.2
CATEGORIES=	math
MASTER_SITES=	http://faculty.cse.tamu.edu/davis/SuiteSparse/
#MASTER_SITES=	http://www.cise.ufl.edu/research/sparse/SuiteSparse/

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://www.cise.ufl.edu/research/sparse/SuiteSparse/
COMMENT=	SuiteSparse is a set of packages for sparse matrices calculation

# Actually uses a combination of gpl and lgpl
# Not sure how to specify 2 licenses, so just listing the stricter one
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-O ${PTHREAD_CFLAGS} ${PICFLAG}

.if ( ${MACHINE_ARCH} == "sparc" ) || ( ${MACHINE_ARCH} == "powerpc" )
PICFLAG?=	-fPIC
.else
PICFLAG?=	-fpic
.endif

# Platforms without librt
.if ${OPSYS} == "Darwin"
LIB=		-lm
.else
LIB=		-lm -lrt
.endif

BLAS=		-lblas
LAPACK=		-llapack

# /home/bacon/Pkgsrc/pkgsrc-1/mk/pkgformat/pkg/list-dependencies: line 52: -e: command not found
# Problem is ${SED} is empty
# TOOLS_PLATFORM.gsed=	#empty
USE_TOOLS+=	gmake gsed

USE_LANGUAGES=	c c++ fortran77

WRKSRC=		${WRKDIR}/SuiteSparse
# Creating shared libs for all platforms is complicated.  Putting this off
# for now.
# WRKSRC_SHARED=${WRKSRC}_shared
SVERSION=	1

.if defined (WITH_METIS)
METIS=			${PREFIX}/lib/libmetis.a
METIS_PATH=		${PREFIX}/include/metis
CHOLMOD_CONFIG =
.else
CHOLMOD_CONFIG =	-DNPARTITION
.endif

AUTO_MKDIRS=		yes
INSTALLATION_DIRS=	include/suitesparse lib

# Non-standard variables used by SuiteSparse Makefiles
MAKE_FLAGS+=	BLAS="${LDFLAGS} ${BLAS}" \
		CHOLMOD_CONFIG="${CHOLMOD_CONFIG}" \
		CPLUSPLUS="${CXX}" \
		CF="${CFLAGS} ${CXXFLAGS}" \
		F77FLAGS="${FFLAGS} ${PICFLAG}" \
		LAPACK="${LDFLAGS} ${LAPACK}" \
		METIS="${METIS}" \
		METIS_PATH="${METIS_PATH}" \
		SPQR_CONFIG="${CHOLMOD_CONFIG}" \
		LIB="${LIB}"

post-patch:
	${CP} ${FILESDIR}/SuiteSparse_config.mk ${WRKSRC}/SuiteSparse_config
#	${FIND} ${WRKSRC} -type f \( -name 'Makefile' -o -name '*.mk' \) \
		-exec gsed -i'.bak' -e '\|^AR =|s|ar|${AR}|' \
			-e '\|^BLAS =|s|=.*|= ${LDFLAGS} ${BLAS}|' \
			-e '\|^CC =|d' \
			-e '\|^CFLAGS =|{s|-O[1-9]\{0,1\}||g;s|=|= ${CFLAGS} $${PICFLAG} |;}' \
			-e '\|^CHOLMOD_CONFIG =|s|=.*|= ${CHOLMOD_CONFIG}|' \
			-e '\|^CPLUSPLUS =|s|=.*|= ${CXX}|' \
			-e '\|^F77 =|d' \
			-e '\|^F77FLAGS =|s|=.*|= ${FFLAGS} $${PICFLAG}|' \
			-e '\|^LAPACK =|s|=.*|= ${LDFLAGS} ${LAPACK}|' \
			-e '\|^METIS =|s|=.*|= ${METIS}|' \
			-e '\|^METIS_PATH =|s|=.*|= ${METIS_PATH}|' \
			-e 's|-I\$$(METIS_PATH)/Lib|-I${METIS_PATH}|' \
			-e '\|^RANLIB =|s|ranlib|${RANLIB}|' \
			-e '\|^SPQR_CONFIG =|s|=.*|= ${CHOLMOD_CONFIG}|' \
			-e 's|/usr/local|${PREFIX}|g' '{}' \;
#	${CP} -r ${WRKSRC} ${WRKSRC_SHARED}

do-build:
	cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} PICFLAG= \
		${GMAKE} ${_MAKE_JOBS} ${MAKE_FLAGS}

#	cd ${WRKSRC_SHARED} ; ${SETENV} ${MAKE_ENV} PICFLAG=${PICFLAG} \
#		${GMAKE} ${_MAKE_JOBS} ${MAKE_FLAGS}

# OS X ld does not support -Bshareable or --whole-archive
# Find a portable way to add sonames
#post-build:
#	for i in `find ${WRKSRC_SHARED} -type f -name '*.a'` ; do \
#		j=$${i##*/} ; ${LD} -Bshareable -o $${i%.a}.so.${SVERSION} -x \
#		-soname $${j%.a}.so.${SVERSION} --whole-archive $${i} ; \
#	done

do-install:
	${INSTALL_DATA} ${WRKSRC}/SuiteSparse_config/SuiteSparse_config.h \
		${DESTDIR}${PREFIX}/include/suitesparse
.for d in AMD BTF CAMD CCOLAMD CHOLMOD COLAMD CXSparse KLU SPQR UMFPACK
	${INSTALL_DATA} ${WRKSRC}/${d}/Include/*.h ${DESTDIR}${PREFIX}/include/suitesparse
.endfor
	(cd ${DESTDIR}${PREFIX}/include && ${LN} -sf suitesparse ufsparse)
	${INSTALL_DATA} ${WRKSRC}/SPQR/Include/*.hpp ${DESTDIR}${PREFIX}/include/suitesparse
	for i in `find ${WRKSRC} -type f -name '*.a'` ; do \
		${INSTALL_DATA} $${i} ${DESTDIR}${PREFIX}/lib ; \
	done

# Shared libs
#	for i in `find ${WRKSRC_SHARED} -type f -name '*.a'` ; do \
#		${INSTALL_DATA} ${WRKSRC}/$${i##${WRKSRC_SHARED}/} \
#		$${i%.a}.so.${SVERSION} ${DESTDIR}${PREFIX}/lib ; \
#		j=$${i##*/} ;  ${LN} -sf $${j%.a}.so.${SVERSION} ${DESTDIR}${PREFIX}/lib/$${j%.a}.so ; \
#	done

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../math/metis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
