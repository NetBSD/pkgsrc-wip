# $NetBSD: Makefile,v 1.27 2010/08/01 14:57:09 asau Exp $

DISTNAME=	mpich2-trunk-r6380
PKGNAME=	${DISTNAME}
PKGNAME=	mpich2-1.2.99.6380
CATEGORIES=	parallel
MASTER_SITES=	http://www.mcs.anl.gov/research/projects/mpich2/downloads/tarballs/1.3a1/ \
		http://www.mcs.anl.gov/research/projects/mpich2/downloads/tarballs/nightly/trunk/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.mcs.anl.gov/research/projects/mpich2/
COMMENT=	Open source MPI and MPI-2 implementation from Univ. of Chicago

CONFLICTS+=	mpich-[0-9]*	# installs bin/mpicc & other wrappers
CONFLICTS+=	openmpi-[0-9]*	# installs bin/mpicc & other wrappers
CONFLICTS+=	openpa-[0-9]*	# installs the library

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

DEPENDS+=	bash-[0-9]*:../../shells/bash

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++ fortran77

PKG_SYSCONFSUBDIR=	mpich

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/${PKGBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/${PKGBASE}
CONFIGURE_ARGS+=	--htmldir=${PREFIX}/share/doc/${PKGBASE}/html

CONFIGURE_ARGS+=	--with-pm=hydra:gforker
CONFIGURE_ARGS+=	--disable-f90		# problems?

USE_TOOLS+=		perl:run

CONF_FILES+=		share/${PKGBASE}/examples/mpe_callstack_ldflags.conf \
			${PKG_SYSCONFDIR}/mpe_callstack_ldflags.conf
CONF_FILES+=		share/${PKGBASE}/examples/mpe_f77env.conf \
			${PKG_SYSCONFDIR}/mpe_f77env.conf
CONF_FILES+=		share/${PKGBASE}/examples/mpe_help.conf \
			${PKG_SYSCONFDIR}/mpe_help.conf
CONF_FILES+=		share/${PKGBASE}/examples/mpe_log.conf \
			${PKG_SYSCONFDIR}/mpe_log.conf
CONF_FILES+=		share/${PKGBASE}/examples/mpe_log_postlib.conf \
			${PKG_SYSCONFDIR}/mpe_log_postlib.conf
CONF_FILES+=		share/${PKGBASE}/examples/mpe_mpicheck.conf \
			${PKG_SYSCONFDIR}/mpe_mpicheck.conf
CONF_FILES+=		share/${PKGBASE}/examples/mpe_mpilog.conf \
			${PKG_SYSCONFDIR}/mpe_mpilog.conf
CONF_FILES+=		share/${PKGBASE}/examples/mpe_mpitrace.conf \
			${PKG_SYSCONFDIR}/mpe_mpitrace.conf
CONF_FILES+=		share/${PKGBASE}/examples/mpe_nolog.conf \
			${PKG_SYSCONFDIR}/mpe_nolog.conf
CONF_FILES+=		share/${PKGBASE}/examples/mpicc.conf \
			${PKG_SYSCONFDIR}/mpicc.conf
CONF_FILES+=		share/${PKGBASE}/examples/mpicxx.conf \
			${PKG_SYSCONFDIR}/mpicxx.conf
CONF_FILES+=		share/${PKGBASE}/examples/mpif77.conf \
			${PKG_SYSCONFDIR}/mpif77.conf

# FreeBSD 6 hack:
.include "../../mk/bsd.prefs.mk"
.if $(OPSYS) == "FreeBSD" || $(OPSYS) == "DragonFly"
BUILDLINK_TRANSFORM+=	rm:-lrt
.endif

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
