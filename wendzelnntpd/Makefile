# $NetBSD$

DISTNAME=		v2.2.0-alpha
PKGNAME=		wendzelnntpd-${DISTNAME:S/v//:S/-//}
CATEGORIES=		news
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wendzelnntpd/}

MAINTAINER=		micha@NetBSD.org
HOMEPAGE=		https://sourceforge.net/projects/wendzelnntpd
COMMENT=		Free Usenet server with SQL backend and RBAC
LICENSE=		gnu-gpl-v3

USE_TOOLS+=		bison flex gmake bash:run
USE_FEATURES=		err regcomp snprintf

BUILD_DEFS+=		VARBASE

# Directory for example config file
EGDIR=			${PREFIX}/share/examples/wendzelnntpd

RCD_SCRIPTS=		wendzelnntpd

OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/wendzelnntpd \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700
OWN_DIRS_PERMS+=	${VARBASE}/spool/news/wendzelnntpd \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700
CONF_FILES_PERMS=	${EGDIR}/wendzelnntpd/wendzelnntpd.conf \
			${PKG_SYSCONFDIR}/wendzelnntpd/wendzelnntpd.conf \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0600
WRKSRC=			${WRKDIR}/cdpxe-WendzelNNTPd-bf144dc

GNU_CONFIGURE=		YES

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR} UDBDIR=${PREFIX}/var/spool/news/wendzelnntpd SQLITEINST=NO CREATE_CERTIFICATES=NO

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/mhash/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
