# $NetBSD: Makefile,v 1.5 2004/11/27 21:20:05 shattered Exp $
#

DISTNAME=	oops-1.5.23
PKGREVISION=	1
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

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-oops-user=${OOPSUSER}
CONFIGURE_ARGS+=	--enable-large-files
CONFIGURE_ARGS+=	--with-DB=${PREFIX}
CONFIGURE_ARGS+=	--sbindir=${PREFIX}/sbin
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${OOPSVAR}
CONFIGURE_ARGS+=	--libdir=${PREFIX}/libexec/oops

.include "../../mk/bsd.prefs.mk"

.if defined(OOPS_CURRENT) && ${OOPS_CURRENT} == YES
PATCHFILES+=	diff_from_1.5.23.patch.gz
PATCH_SITES=	${MASTER_SITES}
PATCH_DIST_STRIP= -p1
PLIST_SUBST+=	OOPS_CURRENT=""
.else
PLIST_SUBST+=	OOPS_CURRENT="@comment "
.endif

OOPSVAR?=	/var/run/oops
OOPSUSER?=	oops
OOPSGROUP?=	oops
PKG_GROUPS=	${OOPSGROUP}
PKG_USERS=	${OOPSUSER}:${OOPSGROUP}::Oops\\ proxy\\ server
OWN_DIRS_PERMS+=	${OOPSVAR} ${OOPSUSER} ${OOPSGROUP} 755
MAKE_DIRS_PERMS+=	${PREFIX}/oops/storages ${OOPSUSER} ${OOPSGROUP} 700
MAKE_DIRS_PERMS+=	${PREFIX}/oops/DB ${OOPSUSER} ${OOPSGROUP} 700
MAKE_DIRS_PERMS+=	${PREFIX}/oops/logs ${OOPSUSER} ${OOPSGROUP} 700

PKG_SYSCONFSUBDIR=	oops
EGDIR=	${PREFIX}/share/examples/oops
CONF_FILES=	${EGDIR}/oops.cfg ${PKG_SYSCONFDIR}/oops.cfg
CONF_FILES+=	${EGDIR}/accel_maps ${PKG_SYSCONFDIR}/accel_maps
CONF_FILES+=	${EGDIR}/acl_local_networks ${PKG_SYSCONFDIR}/acl_local_networks
CONF_FILES+=	${EGDIR}/passwd ${PKG_SYSCONFDIR}/passwd
CONF_FILES+=	${EGDIR}/redir_rules ${PKG_SYSCONFDIR}/redir_rules
CONF_FILES+=	${EGDIR}/select.sql ${PKG_SYSCONFDIR}/select.sql
CONF_FILES+=	${EGDIR}/auth_template.html ${PKG_SYSCONFDIR}/auth_template.html
CONF_FILES+=	${EGDIR}/err_template.html ${PKG_SYSCONFDIR}/err_template.html
CONF_FILES+=	${EGDIR}/redir_template.html ${PKG_SYSCONFDIR}/redir_template.html

RCD_SCRIPTS=	oops

BDB_DEFAULT=	db2
BDB_ACCEPTED=	db2

.if ${OPSYS} == NetBSD
PTHREAD_OPTS+=	require native
.endif

post-install:
	@${MKDIR} ${EGDIR}
	for m in oops.cfg accel_maps acl_local_networks passwd redir_rules \
		select.sql auth_template.html err_template.html \
		redir_template.html; \
		do ${INSTALL_DATA} ${WRKSRC}/src/$$m ${EGDIR}; done
	${INSTALL_MAN} ${WRKSRC}/doc/oops.8 ${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/oopsctl.8 ${PREFIX}/man/man8

.include "../../mk/compiler.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
