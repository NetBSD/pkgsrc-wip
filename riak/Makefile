# $NetBSD: Makefile,v 1.13 2012/10/07 14:53:43 asau Exp $
#

DISTNAME=		riak-1.2.0
CATEGORIES=		databases
MASTER_SITES=		http://s3.amazonaws.com/downloads.basho.com/riak/1.2/${PKGVERSION}/

MAINTAINER=		filip@joyent.com
HOMEPAGE=		http://www.basho.com/products_riak_overview.php
COMMENT=		Distributed, highly available data store
LICENSE=		apache-2.0

USE_LANGUAGES=		c c++
USE_TOOLS=		gmake

DISTFILES=		${DEFAULT_DISTFILES}
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
INNOVER=		1.0.4
INNOSTORE=		innostore-${INNOVER}.tar.gz
SITES.${INNOSTORE}=	http://downloads.basho.com/innostore/innostore-${INNOVER}/
DISTFILES+=		${INNOSTORE}
EXTRACT_ONLY+=		${INNOSTORE}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../lang/erlang/Makefile.versions"
.include "Makefile.versions"

BUILD_DEFS+=		VARBASE RIAK_USER RIAK_GROUP
BUILD_DEFS+=		RIAK_DATA RIAK_LOG

RIAK_USER?=		riak
RIAK_GROUP?=		${RIAK_USER}
RIAK_DATA?=		${VARBASE}/db/riak
RIAK_LOG?=		${VARBASE}/log/riak

PKG_GROUPS+=		${RIAK_GROUP}
PKG_USERS+=		${RIAK_USER}:${RIAK_GROUP}
PKG_HOME.${RIAK_USER}=	${RIAK_DATA}
PKG_GECOS.${RIAK_USER}=	Riak daemon user

OWN_DIRS+=		${RIAK_DATA} ${RIAK_LOG}
OWN_DIRS_PERMS+=	${RIAK_DATA} ${RIAK_USER} ${RIAK_GROUP} 0770
OWN_DIRS_PERMS+=	${RIAK_LOG} ${RIAK_USER} ${RIAK_GROUP} 0770

PKG_SYSCONFSUBDIR=	riak
CONF_FILES+=		share/examples/riak/app.config ${PKG_SYSCONFDIR}/app.config
CONF_FILES+=		share/examples/riak/vm.args ${PKG_SYSCONFDIR}/vm.args

BUILD_TARGET=		rel
PLIST_VARS+=		innostore dtrace

.if !empty(PKG_BUILD_OPTIONS.erlang:Mdtrace)
PLIST.dtrace=		yes
.endif

SUBST_CLASSES+=		pkgsrc
SUBST_STAGE.pkgsrc=	post-patch
SUBST_MESSAGE.pkgsrc=	Fixing pkgsrc locations and tools
SUBST_FILES.pkgsrc=	rel/vars.config
SUBST_VARS.pkgsrc=	PREFIX PKG_SYSCONFDIR
SUBST_VARS.pkgsrc+=	RIAK_USER RIAK_DATA RIAK_LOG

REPLACE_INTERPRETER+=	escript
REPLACE.escript.old=	.*escript
REPLACE.escript.new=	${BUILDLINK_PREFIX.erlang}/bin/escript
REPLACE_FILES.escript=	rel/files/nodetool
REPLACE_FILES.escript+=	${WRKDIR}/innostore-${INNOVER}/priv/innodump
REPLACE_FILES.escript+=	${WRKDIR}/innostore-${INNOVER}/priv/innoload

CHECK_PORTABILITY_SKIP+=	tests/riak_search/run_all.sh	\
				deps/riak_search/tests/riak_search/run_all.sh

MAKE_ENV+=		PATCH=${PATCH:Q}

INSTALL_ENV+=		REPO=riak
INSTALL_ENV+=		PKG_VERSION=${PKGVERSION_NOREV}
INSTALL_ENV+=		OSNAME=${OPSYS}
INSTALL_ENV+=		ARCH=${MACHINE_ARCH}

post-extract:
	${CHMOD} -R u=rwX,g=rX,o=rX \
	  ${WRKDIR}/innostore-${INNOVER} ${WRKSRC}
	${CHOWN} -R ${ROOT_USER}:${ROOT_GROUP} \
	  ${WRKDIR}/innostore-${INNOVER} ${WRKSRC}
	cp ${FILESDIR}/disable_visibility_on_sun.patch \
	  ${WRKDIR}/innostore-${INNOVER}/c_src/patches
	cp ${FILESDIR}/js-src-jslock.c.patch \
	  ${WRKSRC}/deps/erlang_js/c_src/patches

do-install:
	${MKDIR} ${WRKSRC}/package/pkgsrc
	${INSTALL_DATA} ${FILESDIR}/Makefile ${WRKSRC}/package/pkgsrc
	cd ${WRKSRC}/package && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV}    \
           ${MAKE_PROGRAM} ${MAKE_FLAGS} ${INSTALL_MAKE_FLAGS} package

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
