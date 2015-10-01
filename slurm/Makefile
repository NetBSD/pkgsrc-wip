# $NetBSD: Makefile,v 1.8 2015/04/29 12:40:50 outpaddling Exp $

DISTNAME=	slurm-14.11.6
CATEGORIES=	parallel
MASTER_SITES=	http://www.schedmd.com/download/archive/ \
		http://www.schedmd.com/download/latest/ \
		http://www.schedmd.com/download/development/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.schedmd.com/
COMMENT=	Simple Linux Utility for Resource Management

USE_LANGUAGES=	c c++

GNU_CONFIGURE=	yes
USE_TOOLS=	perl pkg-config
USE_LIBTOOL=	yes

# Fix installation:
CONFIGURE_ARGS+=	--htmldir=$(PREFIX)/share/doc/$(PKGNAME_NOREV)/html

REPLACE_PYTHON=	doc/html/shtml2html.py

PKG_GROUPS=		slurm
PKG_USERS=		slurm:slurm

PKG_GECOS.slurm=	SLURM user
PKG_SHELL.slurm=	$(NOLOGIN)

RCD_SCRIPTS+=	slurmd slurmctld

SUBST_CLASSES+=		linuxinit
SUBST_STAGE.linuxinit=	post-patch
SUBST_FILES.linuxinit=	${WRKSRC}/etc/init.d.slurm.in
SUBST_SED.linuxinit=	-e 's|^exec_prefix=|&$(PREFIX)|' \
			-e 's|^prefix=|&$(PREFIX)|' \
			-e 's|@bindir@|$${exec_prefix}/bin|' \
			-e 's|@sbindir@|$${exec_prefix}/sbin|' \
			-e 's|@libdir@|$${exec_prefix}/lib|' \
			-e 's|@sysconfdir@|$${prefix}/etc|'

post-install:
	$(INSTALL_DATA_DIR) $(DESTDIR)$(PREFIX)/share/examples/$(PKGBASE)
	$(INSTALL_DATA) $(WRKSRC)/etc/* $(DESTDIR)$(PREFIX)/share/examples/$(PKGBASE)/
	chmod 755 $(DESTDIR)$(PREFIX)/share/examples/slurm/init.d.slurm

.include "../../lang/python/tool.mk"

CONFIGURE_ARGS+=	--with-munge=$(BUILDLINK_PREFIX.munge:Q)

.include "../../security/munge/buildlink3.mk" # optional
.include "../../parallel/hwloc/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
# Privelege escalation vulnerabilities as of 1-4-2013
# OpenPAM also vulnerable.
# PAM module only needed to limit certain nodes to certain users
#.include "../../mk/pam.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
