# $NetBSD: Makefile,v 1.2 2007/02/26 20:00:43 lkundrak Exp $

DISTNAME=		xrdp-0.3.2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xrdp/}

MAINTAINER=		lkundrak@skosi.org
HOMEPAGE=		http://xrdp.sourceforge.net/
COMMENT=		Remote Desktop Protocol server

USE_TOOLS+=		gmake

EGDIR=			${PREFIX}/share/examples/xrdp
MAKE_ENV+=		DESTDIR=${PREFIX:Q}
MAKE_ENV+=		CFGDIR=${EGDIR:Q}
MAKE_ENV+=		PIDDIR=/var/run
MAKE_ENV+=		MANDIR=${PREFIX:Q}/${PKGMANDIR:Q}
MAKE_ENV+=		DOCDIR=${PREFIX:Q}/share/doc/xrdp

INSTALLATION_DIRS+=	bin share/doc/xrdp share/xrdp
INSTALLATION_DIRS+=	${EGDIR} share/examples/pam.d

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
