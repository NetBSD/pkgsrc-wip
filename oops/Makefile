# $NetBSD: Makefile,v 1.3 2004/09/09 21:46:37 shattered Exp $
#

DISTNAME=	oops-1.5.23
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://zipper.paco.net/~igor/oops/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} diff_from_1.5.23.patch.gz

MAINTAINER=	shattered@users.sourceforge.net
HOMEPAGE=	http://oops-cache.org/
COMMENT=	Multithreaded caching HTTP proxy server

# Oops requires native threads; NetBSD threads are not good enough until
# ~1.6Z (it compiles and runs, but connections hang).  Even on a 1.6Zx
# system it will promptly abort with an assertion failure unless run
# with PTHREAD_DIAGASSERT=AEL.
NOT_FOR_PLATFORM=	NetBSD-1.6[M-Z]-*

EXTRACT_ONLY=		${DISTFILES:N*.patch.gz}
USE_BUILDLINK3=	YES
USE_LANGUAGES=	c c++
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

BDB_DEFAULT=	db2
BDB_ACCEPTED=	db2

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == NetBSD
PTHREAD_OPTS+=	require native
.endif

pre-patch:
	@cd ${WRKSRC} && \
	(${GZIP_CMD} -dc ${_DISTDIR}/diff_from_1.5.23.patch.gz | ${PATCH} -p1) > /dev/null

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/oops.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/oopsctl.8 ${PREFIX}/man/man8

.include "../../mk/compiler.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
