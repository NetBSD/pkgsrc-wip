# $NetBSD: Makefile,v 1.14 2006/04/20 13:36:41 cheusov Exp $
#

DISTNAME=	oops-1.5.24
CATEGORIES=	net
MASTER_SITES=	http://zipper.paco.net/~igor/oops/

MAINTAINER=	shattered@users.sourceforge.net
HOMEPAGE=	http://oops-cache.org/
COMMENT=	Multithreaded caching HTTP proxy server

# Oops requires native threads; NetBSD threads are not good enough until
# ~1.6Z (it compiles and runs, but connections hang).  Even on a 1.6Zx
# system it will promptly abort with an assertion failure unless run
# with PTHREAD_DIAGASSERT=AEL.
NOT_FOR_PLATFORM=	NetBSD-1.6*-*

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-oops-user=${OOPSUSER:Q}
CONFIGURE_ARGS+=	--enable-large-files
CONFIGURE_ARGS+=	--with-DB=${PREFIX:Q}
CONFIGURE_ARGS+=	--sbindir=${PREFIX:Q}/sbin
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${OOPSVAR:Q}
CONFIGURE_ARGS+=	--libdir=${PREFIX:Q}/libexec/oops

.include "../../mk/bsd.prefs.mk"

OOPSVAR?=	/var/run/oops
OOPSUSER?=	oops
OOPSGROUP?=	oops
PKG_GROUPS=	${OOPSGROUP}
PKG_USERS=	${OOPSUSER:Q}:${OOPSGROUP:Q}::Oops\ proxy\ server
OWN_DIRS_PERMS+=	${OOPSVAR} ${OOPSUSER:Q} ${OOPSGROUP:Q} 755
MAKE_DIRS_PERMS+=	${PREFIX:Q}/oops/storages ${OOPSUSER:Q} ${OOPSGROUP:Q} 700
MAKE_DIRS_PERMS+=	${PREFIX:Q}/oops/DB ${OOPSUSER:Q} ${OOPSGROUP:Q} 700
MAKE_DIRS_PERMS+=	${PREFIX:Q}/oops/logs ${OOPSUSER:Q} ${OOPSGROUP:Q} 700

PKG_SYSCONFSUBDIR=	oops
EGDIR=	${PREFIX}/share/examples/oops
CONF_FILES=	${EGDIR:Q}/oops.cfg ${PKG_SYSCONFDIR:Q}/oops.cfg
CONF_FILES+=	${EGDIR:Q}/accel_maps ${PKG_SYSCONFDIR:Q}/accel_maps
CONF_FILES+=	${EGDIR:Q}/acl_local_networks ${PKG_SYSCONFDIR:Q}/acl_local_networks
CONF_FILES+=	${EGDIR:Q}/passwd ${PKG_SYSCONFDIR:Q}/passwd
CONF_FILES+=	${EGDIR:Q}/redir_rules ${PKG_SYSCONFDIR:Q}/redir_rules
CONF_FILES+=	${EGDIR:Q}/select.sql ${PKG_SYSCONFDIR:Q}/select.sql
CONF_FILES+=	${EGDIR:Q}/auth_template.html ${PKG_SYSCONFDIR:Q}/auth_template.html
CONF_FILES+=	${EGDIR:Q}/err_template.html ${PKG_SYSCONFDIR:Q}/err_template.html
CONF_FILES+=	${EGDIR:Q}/redir_template.html ${PKG_SYSCONFDIR:Q}/redir_template.html
CONF_FILES+=	${EGDIR:Q}/tables/koi-alt.tab ${PKG_SYSCONFDIR:Q}/tables/koi-alt.tab
CONF_FILES+=	${EGDIR:Q}/tables/koi-iso.tab ${PKG_SYSCONFDIR:Q}/tables/koi-iso.tab
CONF_FILES+=	${EGDIR:Q}/tables/koi-win.tab ${PKG_SYSCONFDIR:Q}/tables/koi-win.tab

RCD_SCRIPTS=	oops

BDB_ACCEPTED=	db2

.if ${OPSYS} == NetBSD
PTHREAD_OPTS+=	require native
.endif

post-install:
	@${MKDIR} ${EGDIR:Q} ${EGDIR:Q}/tables
	set -eu;							\
	for m in oops.cfg accel_maps acl_local_networks passwd		\
		redir_rules select.sql auth_template.html		\
		err_template.html redir_template.html;			\
	do ${INSTALL_DATA} ${WRKSRC:Q}/src/"$$m" ${EGDIR:Q};		\
	done
	set -eu;							\
	for m in koi-alt.tab koi-iso.tab koi-win.tab;			\
	do ${INSTALL_DATA} ${WRKSRC:Q}/src/tables/"$$m" ${EGDIR:Q}/tables; \
	done
	${INSTALL_MAN} ${WRKSRC:Q}/doc/oops.8 ${PREFIX:Q}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC:Q}/doc/oopsctl.8 ${PREFIX:Q}/${PKGMANDIR}/man8

.include "../../mk/compiler.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
