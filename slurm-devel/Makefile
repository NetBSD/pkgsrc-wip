# $NetBSD: Makefile,v 1.8 2015/04/29 12:40:50 outpaddling Exp $

DISTNAME=	slurm-17.11.1-2
CATEGORIES=	parallel
MASTER_SITES=	http://www.schedmd.com/download/archive/ \
		http://www.schedmd.com/download/latest/ \
		http://www.schedmd.com/download/development/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://www.schedmd.com/
COMMENT=	Simple Linux Utility for Resource Management

LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	libtool-base-[0-9]*:../../devel/libtool-base

USE_LANGUAGES=	c c++

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake perl pkg-config
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--htmldir=${PREFIX}/share/doc/${PKGNAME_NOREV}/html
CONFIGURE_ARGS+=	--with-munge=${BUILDLINK_PREFIX.munge}
# Add mysql option
CONFIGURE_ARGS+=	--with-mysql_config=/nonexistent

LDFLAGS+=		-llz4

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

SUBST_CLASSES+=		gtk
SUBST_STAGE.gtk=	post-patch
SUBST_SED.gtk=		-e 's|min_gtk_version=.*|min_gtk_version=2000.0.0|'
SUBST_FILES.gtk=	${WRKSRC}/configure

SUBST_CLASSES+=		make-ex
SUBST_STAGE.make-ex=	post-install
SUBST_FILES.make-ex=	etc/Makefile
SUBST_SED.make-ex=	-e 's|${WRKDIR}|<build-prefix>|g'

INSTALLATION_DIRS+=	share/examples/${PKGBASE}

post-install:
	${RM} -f ${WRKSRC}/etc/init.d.slurm.in.orig
	${INSTALL_DATA} ${WRKSRC}/etc/* \
		${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/

.include "../../www/curl/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../security/munge/buildlink3.mk" # optional
.include "../../parallel/hwloc/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../archivers/lz4/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../databases/mysql57-client/buildlink3.mk"
# vuln in 55 and 56 .include "../../mk/mysql.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
