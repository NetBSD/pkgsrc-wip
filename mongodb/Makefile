# $NetBSD: Makefile,v 1.11 2012/07/26 11:08:46 fhajny Exp $

DISTNAME=	mongodb-src-r2.0.6
PKGNAME=	${DISTNAME:S/src-r//}
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://downloads.mongodb.org/src/

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	http://mongodb.org/
COMMENT=	NOSQL distributed document-oriented database
LICENSE=	gnu-agpl-v3 # Client and tools licensed under apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

NO_CONFIGURE=	yes
USE_LANGUAGES=	c c++

BUILD_DEPENDS+=	scons:../../devel/scons

SCONS_BIN=	${PREFIX}/bin/scons
SCONS_ARGS=	${_MAKE_JOBS}
SCONS_ARGS+=	--use-system-all
SCONS_ARGS+=	--cc=${WRAPPER_BINDIR}/${CC}
SCONS_ARGS+=	--cxx=${WRAPPER_BINDIR}/${CXX}

.include "options.mk"

BUILD_DEFS+=		VARBASE
BUILD_DEFS+=		MONGODB_USER MONGODB_GROUP MONGODB_DBPATH

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

FILES_SUBST+=		MONGODB_USER=${MONGODB_USER}
FILES_SUBST+=		MONGODB_GROUP=${MONGODB_GROUP}
FILES_SUBST+=		MONGODB_DBPATH=${MONGODB_DBPATH}

# XXX No better idea how to pass CXXFLAGS and LDFLAGS to scons
SUBST_CLASSES+=		scons
SUBST_STAGE.scons=	post-patch
SUBST_FILES.scons=	SConstruct
SUBST_VARS.scons=	PREFIX CXXFLAGS LDFLAGS

SUBST_CLASSES+=		dbpath
SUBST_STAGE.dbpath=	post-patch
SUBST_FILES.dbpath=	db/db.cpp db/flushtest.cpp db/pdfile.cpp
SUBST_SED.dbpath=	-e "s|/data/db|${MONGODB_DBPATH}|g"

RCD_SCRIPTS=		mongodb

INSTALLATION_DIRS=	share/doc/mongodb

post-extract:
	chmod -R g-w ${WRKSRC}

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
.include "../../devel/snappy/buildlink3.mk"
.include "../../lang/spidermonkey/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
