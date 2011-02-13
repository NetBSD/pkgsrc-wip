# $NetBSD: Makefile,v 1.7 2011/02/13 21:02:54 mwilhelmy Exp $

DISTNAME=		xrdp-0.4.2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xrdp/}

MAINTAINER=		lkundrak@skosi.org
HOMEPAGE=		http://xrdp.sourceforge.net/
COMMENT=		Remote Desktop Protocol server
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		gmake

PKG_DESTDIR_SUPPORT=	user-destdir

EGDIR=			${PREFIX}/share/examples/xrdp
MAKE_ENV+=		DESTDIR=${DESTDIR:Q}${PREFIX:Q}
MAKE_ENV+=		CFGDIR=${EGDIR:Q}
MAKE_ENV+=		PIDDIR=/var/run
MAKE_ENV+=		MANDIR=${PREFIX:Q}/${PKGMANDIR:Q}
MAKE_ENV+=		DOCDIR=${PREFIX:Q}/share/doc/xrdp
MAKE_ENV+=		DLLIB=${BUILDLINK_LDADD.dl:Q}
MAKE_ENV+=		CFGDIR=${PKG_SYSCONFDIR}

INSTALL_ENV+=		BINDIR=${PREFIX}/bin
INSTALL_ENV+=		LIBDIR=${PREFIX}/lib
INSTALL_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}
INSTALL_ENV+=		ETCDIR=${PREFIX}/share/examples/xrdp
INSTALL_ENV+=		PAMDIR=${PREFIX}/share/examples/pam.d
INSTALL_ENV+=		SHAREDIR=${PREFIX}/share

AUTO_MKDIRS=		yes
INSTALLATION_DIRS=	share/xrdp share/examples/xrdp

PKG_SYSCONFSUBDIR=	xrdp
CONF_FILES+=		${EGDIR}/sesman.ini	${PKG_SYSCONFDIR}/sesman.ini
CONF_FILES+=		${EGDIR}/rsakeys.ini	${PKG_SYSCONFDIR}/rsakeys.ini
CONF_FILES+=		${EGDIR}/xrdp.ini	${PKG_SYSCONFDIR}/xrdp.ini

#PTHREAD_OPTS+=		native

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
