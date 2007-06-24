# $NetBSD: Makefile,v 1.10 2007/06/24 10:04:30 shattered Exp $
#

DISTNAME=	lam-7.1.3
PKGNAME=	${DISTNAME:S/lam/lammpi/}
CATEGORIES=	net
MASTER_SITES=	http://www.lam-mpi.org/download/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lam-mpi.org/download/files/
COMMENT=	Implementation of the Message Passing Interface (MPI) Standard

CONFLICTS=	lam-[0-9]*

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++ fortran
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--disable-deprecated-executable-names

EGDIR=		${PREFIX}/share/examples/${PKGBASE}

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS+=	${PKGMANDIR}/mans include/mpi2cxx lib/lam ${DOCDIR}

.for i in lam-bhost.def lam-conf.lamd lam-helpfile lam-hostmap.txt lam-ssi-boot-globus-helpfile \
          lam-ssi-boot-slurm-helpfile lam-ssi-crlam-self-helpfile lam-ssi-crmpi-self-helpfile
CONF_FILES+=	${EGDIR}/${i} ${PKG_SYSCONFDIR}/${i}
.endfor

do-install:
	cd ${WRKSRC} && env ${MAKE_ENV} \
	   ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} -f ${MAKE_FILE} \
	   ${INSTALL_TARGET} sysconfdir=${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/tools/mpiexec/mpiexec ${DESTDIR}${PREFIX}/bin/

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
