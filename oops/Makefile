# $NetBSD: Makefile,v 1.2 2004/03/28 14:12:24 shattered Exp $
#

DISTNAME=	oops-1.5.23
CATEGORIES=	net
MASTER_SITES=	http://zipper.paco.net/~igor/oops/

MAINTAINER=	shattered@users.sourceforge.net
HOMEPAGE=	http://oops-cache.org/
COMMENT=	Multithreaded caching HTTP proxy server

# Oops requires native threads; NetBSD threads are not good enough until
# ~1.6Z (it compiles and runs, but connections hang).  Even on a 1.6Zx
# system it will promptly abort with an assertion failure unless run
# with PTHREAD_DIAGASSERT=AEL.
NOT_FOR_PLATFORM=	NetBSD-1.6[M-Z]-*

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--enable-oops-user=oops
CONFIGURE_ARGS+=	--enable-large-files
CONFIGURE_ARGS+=	--with-DB=${PREFIX}
CONFIGURE_ARGS+=	--sbindir=${PREFIX}/sbin
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/etc/oops
CONFIGURE_ARGS+=	--localstatedir=${OOPSVAR}
CONFIGURE_ARGS+=	--libdir=${PREFIX}/libexec/oops

OOPSVAR?=	/var/run/oops
OOPSUSER?=	oops
OOPSGROUP?=	oops
PKG_GROUPS=	${OOPSGROUP}
PKG_USERS=	${OOPSUSER}:${OOPSGROUP}::Oops\\ proxy\\ server\\ user
OWN_DIRS_PERMS+=	${OOPSVAR} ${OOPSUSER} ${OOPSGROUP} 755
MAKE_DIRS_PERMS+=	${PREFIX}/oops/storages ${OOPSUSER} ${OOPSGROUP} 700
MAKE_DIRS_PERMS+=	${PREFIX}/oops/DB ${OOPSUSER} ${OOPSGROUP} 700
MAKE_DIRS_PERMS+=	${PREFIX}/oops/logs ${OOPSUSER} ${OOPSGROUP} 700

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == NetBSD
PTHREAD_OPTS+=	require native
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/oops.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/oopsctl.8 ${PREFIX}/man/man8

.include "../../mk/pthread.buildlink3.mk"
.include "../../databases/db/buildlink3.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
