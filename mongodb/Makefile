# $NetBSD: Makefile,v 1.6 2012/02/23 19:11:40 bartoszkuzma Exp $

DISTNAME=	mongodb-src-r2.0.2
PKGNAME=	${DISTNAME:S/src-r//}
CATEGORIES=	databases
MASTER_SITES=	http://downloads.mongodb.org/src

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://mongodb.org/
COMMENT=	NOSQL distributed document-oriented database
LICENSE=	gnu-agpl-v3 # Client and tools licensed under apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes

BUILD_DEPENDS+=	scons:../../devel/scons

SCONS_BIN=	${PREFIX}/bin/scons
SCONS_ARGS=	${_MAKE_JOBS}
SCONS_ARGS+=	--use-system-all

.include "options.mk"

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		MONGODB_DBPATH

MONGODB_USER?=		mongodb
MONGODB_GROUP?=		mongodb
MONGODB_DBPATH?=	${VARBASE}/mongodb

PKG_USERS_VARS+=	MONGODB_USER
PKG_GROUPS_VARS+=	MONGODB_GROUP

PKG_GROUPS=		${MONGODB_GROUP}
PKG_USERS=		${MONGODB_USER}:${MONGODB_GROUP}

PKG_GECOS.${MONGODB_USER}=	MongoDB database administrator
PKG_HOME.${MONGODB_USER}=	${MONGODB_DBPATH}
PKG_SHELL.${MONGODB_USER}=	${SH}

OWN_DIRS_PERMS+=	${MONGODB_DBPATH} ${MONGODB_USER} ${MONGODB_GROUP} 0755

# XXX No better idea how to pass CXXFLAGS and LDFLAGS to scons
SUBST_CLASSES+=		scons
SUBST_STAGE.scons=	post-patch
SUBST_FILES.scons=	SConstruct
SUBST_SED.scons=	-e "s|%PREFIX%|${PREFIX}|g"
SUBST_SED.scons+=	-e "s|%CXXFLAGS%|${CXXFLAGS}|g"
SUBST_SED.scons+=	-e "s|%LINKFLAGS%|${LDFLAGS}|g"

SUBST_CLASSES+=		dbpath
SUBST_STAGE.dbpath=	post-patch
SUBST_FILES.dbpath=	db/db.cpp db/flushtest.cpp db/pdfile.cpp
SUBST_SED.dbpath=	-e "s|/data/db|${MONGODB_DBPATH}|g"

INSTALLATION_DIRS=	share/doc/mongodb

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONS_BIN} ${SCONS_ARGS} all

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONS_BIN} \
		${SCONS_ARGS} --full --prefix ${DESTDIR}${PREFIX} install

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mongodb

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/boost-python/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/spidermonkey/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
