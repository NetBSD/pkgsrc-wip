# $NetBSD: Makefile,v 1.1 2015/02/05 20:06:43 outpaddling Exp $
#

DISTNAME=	espresso-5.0.2
CATEGORIES=	science
MASTER_SITES=	http://qe-forge.org/gf/download/frsrelease/116/403/
# FIXME: Fetch only what's being built
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
                SaX-2.0.2.tar.gz \
                ${PLUGINS_DISTFILES}

# Not included in "all" target
#		XSpectra-5.0.2.tar.gz \
#		qe-gipaw-5.0.3.tar.gz \

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://qe-forge.org/gf/download/frsrelease/116/403/
COMMENT=	Nanoscale electronic-structure calculations and materials modeling
#LICENSE=	# TODO: (see mk/license.mk)

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c fortran

# Adding -traditional to CPPFLAGS causes conftests to fail for gcc
# CPPFLAGS+=	-P
SUBST_CLASSES+=		cpp
SUBST_STAGE.cpp=	post-configure
SUBST_FILES.cpp=	make.sys
SUBST_SED.cpp=		-e 's|CPPFLAGS[ \t]*=|CPPFLAGS = -P -traditional|g'

# Slave packages for gui xspectra gipaw w90 want yambo?
# Some could be independent packages?
# plumed must be compiled in: option?
# doc links
BUILD_TARGET=	all links

# Not included in "all" target
#		want-2.4.0-base.tar.gz \
#		yambo-3.2.5-rev.26.tar.gz \
#		wannier90-1.2.tar.gz \
#		plumed-1.3-qe.tar.gz \
#		PWgui-5.0.2.tgz

# install/plugins_list
PLUGINS_DISTFILES= \
	atomic-5.0.2.tar.gz \
	pwcond-5.0.2.tar.gz \
	neb-5.0.2.tar.gz \
	PHonon-5.0.2.tar.gz \
	tddfpt-5.0.2.tar.gz
DIST_SUBDIR=	espresso

MASTER_SITES_BASE=	http://www.qe-forge.org/gf/download/frsrelease

# FETCH creates files called index.php?file=filename
# I don't see a clean way to use -o in FETCH_ARGS with multiple DISTFILES
do-fetch:
	@${MKDIR} ${DISTDIR}/${DIST_SUBDIR}
	@(cd ${DISTDIR}/${DIST_SUBDIR} && fetch -Fro \
		${DISTNAME}${EXTRACT_SUFX} \
		${MASTER_SITES}${DISTNAME}${EXTRACT_SUFX})
	@(cd ${DISTDIR}/${DIST_SUBDIR} && fetch -Fro \
		XSpectra-5.0.2.tar.gz \
		${MASTER_SITES_BASE}/116/410/XSpectra-5.0.2.tar.gz)
	@(cd ${DISTDIR}/${DIST_SUBDIR} && fetch -Fro \
		qe-gipaw-5.0.3.tar.gz \
		${MASTER_SITES_BASE}/146/473/qe-gipaw-5.0.3.tar.gz)
	@(cd ${DISTDIR}/${DIST_SUBDIR} && fetch -Fro \
		SaX-2.0.2.tar.gz \
		${MASTER_SITES_BASE}/111/192/SaX-2.0.2.tar.gz)
.for file in ${PLUGINS_DISTFILES}
	@(cd ${DISTDIR}/${DIST_SUBDIR} && fetch -Fro ${file} \
		http://files.qe-forge.org/index.php?file=${file})
.endfor

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/* ${WRKSRC}/archive

post-build:
	${MKDIR} ${WRKSRC}/scripts
	${MV} ${WRKSRC}/bin/iotk ${WRKSRC}/scripts

do-install:
	${MKDIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/iotk ${DESTDIR}${PREFIX}/bin
	for p in ${WRKSRC}/bin/*; do \
		${INSTALL_PROGRAM} $${p} \
		${DESTDIR}${PREFIX}/bin; \
	done

.include "../../math/blas/buildlink3.mk"
.include "../../math/lapack/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
