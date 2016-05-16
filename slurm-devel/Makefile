# $NetBSD: Makefile,v 1.8 2015/04/29 12:40:50 outpaddling Exp $

DISTNAME=	slurm-16.05.0-0rc1
PKGNAME=	slurm-16.05.0
CATEGORIES=	parallel
MASTER_SITES=	http://www.schedmd.com/download/archive/ \
		http://www.schedmd.com/download/latest/ \
		http://www.schedmd.com/download/development/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.schedmd.com/
COMMENT=	Simple Linux Utility for Resource Management

LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl pkg-config
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--htmldir=${PREFIX}/share/doc/${PKGNAME_NOREV}/html
CONFIGURE_ARGS+=	--with-munge=${BUILDLINK_PREFIX.munge}

REPLACE_PYTHON=		doc/html/shtml2html.py
REPLACE_PYTHON+=	doc/man/man2html.py
REPLACE_PYTHON+=	testsuite/expect/regression.py
REPLACE_PYTHON+=	testsuite/expect/driveregress.py
REPLACE_PYTHON+=	contribs/cray/csm/slurmconfgen_smw.py

PKG_GROUPS=		slurm
PKG_USERS=		slurm:slurm

PKG_GECOS.slurm=	SLURM user
PKG_SHELL.slurm=	${NOLOGIN}

RCD_SCRIPTS+=		slurmd slurmctld

SUBST_CLASSES+=		linuxinit
SUBST_STAGE.linuxinit=	post-patch
SUBST_FILES.linuxinit=	${WRKSRC}/etc/init.d.slurm.in
SUBST_SED.linuxinit=	-e 's|^exec_prefix=|&${PREFIX}|'
SUBST_SED.linuxinit+=	-e 's|^prefix=|&${PREFIX}|'
SUBST_SED.linuxinit+=	-e 's|@bindir@|$${exec_prefix}/bin|'
SUBST_SED.linuxinit+=	-e 's|@sbindir@|$${exec_prefix}/sbin|'
SUBST_SED.linuxinit+=	-e 's|@libdir@|$${exec_prefix}/lib|'
SUBST_SED.linuxinit+=	-e 's|@sysconfdir@|$${prefix}/etc|'

MAKEFILE_EXAMPLE=	${WRKSRC}/etc/Makefile

INSTALLATION_DIRS+=	share/examples/${PKGBASE}

post-install:
	# Sanity checks fail if installed files contain references to WRKSRC
	${SED} -e "s|${WRKDIR}|PREFIX|g" \
		${MAKEFILE_EXAMPLE} > ${MAKEFILE_EXAMPLE}.tmp
	${MV} -f ${MAKEFILE_EXAMPLE}.tmp ${MAKEFILE_EXAMPLE}
	${RM} -f ${WRKSRC}/etc/init.d.slurm.in.orig
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/etc/* ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/
	${CHMOD} 755 ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/init.d.slurm

.include "../../lang/python/tool.mk"
.include "../../security/munge/buildlink3.mk" # optional
.include "../../parallel/hwloc/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
