# $NetBSD: Makefile,v 1.22 2012/10/03 21:32:46 asau Exp $
#

DISTNAME=	oops-1.5.24
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://zipper.paco.net/~igor/oops/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://oops-cache.org/
COMMENT=	Multithreaded caching HTTP proxy server

# Oops requires working native threads
NOT_FOR_PLATFORM=	NetBSD-1.*-*


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

OOPSVAR?=		/var/run/oops
OOPSUSER?=		oops
OOPSGROUP?=		oops
PKG_GROUPS=		${OOPSGROUP}
PKG_USERS=		${OOPSUSER}:${OOPSGROUP}::Oops\ proxy\ server
OWN_DIRS_PERMS+=	${OOPSVAR} ${OOPSUSER} ${OOPSGROUP} 755
MAKE_DIRS_PERMS+=	${PREFIX}/oops/storages ${OOPSUSER} ${OOPSGROUP} 700
MAKE_DIRS_PERMS+=	${PREFIX}/oops/DB ${OOPSUSER} ${OOPSGROUP} 700
MAKE_DIRS_PERMS+=	${PREFIX}/oops/logs ${OOPSUSER} ${OOPSGROUP} 700

PKG_SYSCONFSUBDIR=	oops
EGDIR=			${PREFIX}/share/examples/oops
CONF_FILES=		${EGDIR}/oops.cfg ${PKG_SYSCONFDIR}/oops.cfg
CONF_FILES+=		${EGDIR}/accel_maps ${PKG_SYSCONFDIR}/accel_maps
CONF_FILES+=		${EGDIR}/acl_local_networks ${PKG_SYSCONFDIR}/acl_local_networks
CONF_FILES+=		${EGDIR}/passwd ${PKG_SYSCONFDIR}/passwd
CONF_FILES+=		${EGDIR}/redir_rules ${PKG_SYSCONFDIR}/redir_rules
CONF_FILES+=		${EGDIR}/select.sql ${PKG_SYSCONFDIR}/select.sql
CONF_FILES+=		${EGDIR}/auth_template.html ${PKG_SYSCONFDIR}/auth_template.html
CONF_FILES+=		${EGDIR}/err_template.html ${PKG_SYSCONFDIR}/err_template.html
CONF_FILES+=		${EGDIR}/redir_template.html ${PKG_SYSCONFDIR}/redir_template.html
CONF_FILES+=		${EGDIR}/tables/koi-alt.tab ${PKG_SYSCONFDIR}/tables/koi-alt.tab
CONF_FILES+=		${EGDIR}/tables/koi-iso.tab ${PKG_SYSCONFDIR}/tables/koi-iso.tab
CONF_FILES+=		${EGDIR}/tables/koi-win.tab ${PKG_SYSCONFDIR}/tables/koi-win.tab

RCD_SCRIPTS=	oops

BDB_ACCEPTED=	db2 db4

.if ${OPSYS} == NetBSD
PTHREAD_OPTS+=	require native
.endif

post-install:
	mkdir ${EGDIR} ${EGDIR}/tables
	set -eu;							\
	for m in oops.cfg accel_maps acl_local_networks passwd		\
		redir_rules select.sql auth_template.html		\
		err_template.html redir_template.html;			\
	do ${INSTALL_DATA} ${WRKSRC}/src/"$$m" ${EGDIR};		\
	done
	set -eu;							\
	for m in koi-alt.tab koi-iso.tab koi-win.tab;			\
	do ${INSTALL_DATA} ${WRKSRC}/src/tables/"$$m" ${EGDIR}/tables; \
	done
	${INSTALL_MAN} ${WRKSRC}/doc/oops.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/doc/oopsctl.8 ${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/compiler.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
