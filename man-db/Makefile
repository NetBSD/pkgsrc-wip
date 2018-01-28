# $NetBSD: Makefile,v 1.19 2012/10/03 15:09:50 asau Exp $

DISTNAME=		man-db-2.7.5
CATEGORIES=		misc
MASTER_SITES=		http://download.savannah.gnu.org/releases/man-db/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.chiark.greenend.org.uk/~cjwatson/code/man-db/
COMMENT=		Manual pager and related man page utilities

CONFLICTS+=		man-[0-9]*

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "NetBSD"
DEPENDS+=		groff-[0-9]*:../../textproc/groff
.endif

.if !exists(/usr/bin/yacc)
BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
.endif



MAN_DB_CAT_DIR?=	/var/cache/man

# for modifying cat and database files
MAN_DB_USER?=		man-db
PKG_USERS=		${MAN_DB_USER}:${ROOT_GROUP}::man-db\ user:${MAN_DB_CAT_DIR}

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
MAKE_FILE=		GNUmakefile
CONFIGURE_ARGS+=	--mandir=${PREFIX}/man
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-setuid=${MAN_DB_USER:Q}

CONF_FILES=		${PREFIX}/share/examples/man-db/man_db.conf ${PKG_SYSCONFDIR}/man_db.conf

OWN_DIRS_PERMS=		${MAN_DB_CAT_DIR} ${MAN_DB_USER} ${ROOT_GROUP} 2755

MESSAGE_SUBST+=		MAN_DB_USER=${MAN_DB_USER}

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/man-db
	${INSTALL_DATA} ${WRKSRC}/src/man_db.conf ${PREFIX}/share/examples/man-db

USE_DB185=	YES
.include "../../mk/bdb.buildlink3.mk"
.if ${BDB_TYPE} != "native"
CONFIGURE_ARGS+=	--with-db=${BDB_TYPE}
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
