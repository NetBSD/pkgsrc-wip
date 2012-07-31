# $NetBSD: Makefile,v 1.12 2012/07/31 22:27:59 fhajny Exp $

DISTNAME=	mongodb-src-r2.0.6
PKGNAME=	${DISTNAME:S/src-r//}
PKGREVISION=	3
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
BUILD_DEFS+=		MONGODB_LOGPATH

MONGODB_USER?=		mongodb
MONGODB_GROUP?=		mongodb
MONGODB_DBPATH?=	${VARBASE}/mongodb
MONGODB_LOGPATH?=	${VARBASE}/log/mongodb

PKG_USERS_VARS+=	MONGODB_USER
PKG_GROUPS_VARS+=	MONGODB_GROUP

PKG_GROUPS=		${MONGODB_GROUP}
PKG_USERS=		${MONGODB_USER}:${MONGODB_GROUP}

PKG_GECOS.${MONGODB_USER}=	MongoDB database administrator
PKG_HOME.${MONGODB_USER}=	${MONGODB_DBPATH}
PKG_SHELL.${MONGODB_USER}=	${SH}

OWN_DIRS_PERMS+=	${MONGODB_DBPATH} ${MONGODB_USER} ${MONGODB_GROUP} 0755
OWN_DIRS_PERMS+=	${MONGODB_LOGPATH} ${MONGODB_USER} ${MONGODB_GROUP} 0755

FILES_SUBST+=		MONGODB_USER=${MONGODB_USER}
FILES_SUBST+=		MONGODB_GROUP=${MONGODB_GROUP}
FILES_SUBST+=		MONGODB_DBPATH=${MONGODB_DBPATH}
FILES_SUBST+=		MONGODB_LOGPATH=${MONGODB_LOGPATH}

# XXX No better idea how to pass CXXFLAGS and LDFLAGS to scons
SUBST_CLASSES+=		scons
SUBST_STAGE.scons=	post-patch
SUBST_FILES.scons=	SConstruct
SUBST_VARS.scons=	PREFIX CXXFLAGS LDFLAGS

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	db/db.cpp db/flushtest.cpp db/pdfile.cpp
SUBST_FILES.path+=	debian/mongodb.conf
SUBST_SED.path=		-e "s|/data/db|${MONGODB_DBPATH}|g"
SUBST_VARS.path=	MONGODB_DBPATH MONGODB_LOGPATH

MONGODB_MAN_FILES=	bsondump.1 mongo.1 mongod.1 mongodump.1 mongoexport.1 \
			mongofiles.1 mongoimport.1 mongorestore.1 mongos.1    \
			mongosniff.1 mongostat.1

RCD_SCRIPTS=		mongodb

INSTALLATION_DIRS=	share/doc/mongodb share/examples/mongodb ${PKGMANDIR}/man1

CONF_FILES+=		share/examples/mongodb/mongodb.conf \
			${PKG_SYSCONFDIR}/mongodb.conf

post-extract:
	chmod -R g-w ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONS_BIN} ${SCONS_ARGS} all

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONS_BIN} \
		${SCONS_ARGS} --full --prefix ${DESTDIR}${PREFIX} install

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/mongodb
.	for file in ${MONGODB_MAN_FILES}
	${INSTALL_MAN} ${WRKSRC}/debian/${file} \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.	endfor
	${INSTALL_DATA} ${WRKSRC}/debian/mongodb.conf \
		${DESTDIR}${PREFIX}/share/examples/mongodb

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/boost-python/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../lang/spidermonkey/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
