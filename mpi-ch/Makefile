# $NetBSD: Makefile,v 1.9 2008/04/18 21:24:50 asau Exp $

DISTNAME=	mpich2-1.0.7
CATEGORIES=	parallel
MASTER_SITES=	http://www.mcs.anl.gov/research/projects/mpich2/downloads/tarballs/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.mcs.anl.gov/research/projects/mpich2/
COMMENT=	Open source MPI and MPI-2 implementation from Univ. of Chicago

CONFLICTS+=	musicpd-[0-9]*	# installs bin/mpd
CONFLICTS+=	mpich-[0-9]*	# installs bin/mpicc & other wrappers
CONFLICTS+=	openmpi-[0-9]*	# installs bin/mpicc & other wrappers

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++ fortran

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/${PKGNAME_NOREV}
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/${PKGNAME_NOREV}
CONFIGURE_ARGS+=	--with-htmldir=${PREFIX}/share/doc/${PKGNAME_NOREV}/html

USE_TOOLS+=		perl:run

REPLACE_PYTHON+=	src/pm/mpd/*.py src/pm/mpd/test/*.py

CONF_FILES+=		share/${PKGNAME}/examples/mpe_callstack_ldflags.conf \
			${PKG_SYSCONFDIR}/mpe_callstack_ldflags.conf
CONF_FILES+=		share/${PKGNAME}/examples/mpe_f77env.conf \
			${PKG_SYSCONFDIR}/mpe_f77env.conf
CONF_FILES+=		share/${PKGNAME}/examples/mpe_help.conf \
			${PKG_SYSCONFDIR}/mpe_help.conf
CONF_FILES+=		share/${PKGNAME}/examples/mpe_log.conf \
			${PKG_SYSCONFDIR}/mpe_log.conf
CONF_FILES+=		share/${PKGNAME}/examples/mpe_log_postlib.conf \
			${PKG_SYSCONFDIR}/mpe_log_postlib.conf
CONF_FILES+=		share/${PKGNAME}/examples/mpe_mpicheck.conf \
			${PKG_SYSCONFDIR}/mpe_mpicheck.conf
CONF_FILES+=		share/${PKGNAME}/examples/mpe_mpilog.conf \
			${PKG_SYSCONFDIR}/mpe_mpilog.conf
CONF_FILES+=		share/${PKGNAME}/examples/mpe_mpitrace.conf \
			${PKG_SYSCONFDIR}/mpe_mpitrace.conf
CONF_FILES+=		share/${PKGNAME}/examples/mpe_nolog.conf \
			${PKG_SYSCONFDIR}/mpe_nolog.conf
CONF_FILES+=		share/${PKGNAME}/examples/mpicc.conf \
			${PKG_SYSCONFDIR}/mpicc.conf
CONF_FILES+=		share/${PKGNAME}/examples/mpicxx.conf \
			${PKG_SYSCONFDIR}/mpicxx.conf
CONF_FILES+=		share/${PKGNAME}/examples/mpif77.conf \
			${PKG_SYSCONFDIR}/mpif77.conf

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
