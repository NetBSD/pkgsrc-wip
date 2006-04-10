# $NetBSD: Makefile,v 1.1.1.1 2006/04/10 15:10:00 lkundrak Exp $

DISTNAME=		xrdp-0.2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xrdp/}

MAINTAINER=		lkundrak@skosi.org
HOMEPAGE=		http://xrdp.sourceforge.net/
COMMENT=		Remote Desktop Protocol server

USE_TOOLS+=		gmake

MAKE_ENV+=		DESTDIR=${PREFIX:Q}
MAKE_ENV+=		CFGDIR=${PKG_SYSCONFDIR:Q}
MAKE_ENV+=		"PIDDIR=${VARBASE}/run"
MAKE_ENV+=		"MANDIR=${PREFIX}/${PKGMANDIR}"
MAKE_ENV+=		"DOCDIR=${PREFIX}/share/doc/xrdp"

EGDIR=			${PREFIX}/share/examples/xrdp

PKG_SYSCONFSUBDIR=	xrdp
CONF_FILES+=		${EGDIR}/sesman.ini	${PKG_SYSCONFDIR}/sesman.ini
CONF_FILES+=		${EGDIR}/rsakeys.ini	${PKG_SYSCONFDIR}/rsakeys.ini
CONF_FILES+=		${EGDIR}/xrdp.ini	${PKG_SYSCONFDIR}/xrdp.ini

OWN_DIRS+=		${EGDIR}
OWN_DIRS+=		${PREFIX}/share/xrdp
OWN_DIRS+=		${PREFIX}/share/doc/xrdp
MAKE_DIRS+=		${PREFIX}/share/examples/pam.d

PTHREAD_OPTS+=		native

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
