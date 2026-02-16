# $NetBSD$

DISTNAME=		v2.2.0-alpha
PKGNAME=		wendzelnntpd-${DISTNAME:S/v//:S/-//}
CATEGORIES=		news
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wendzelnntpd/}

MAINTAINER=		micha@NetBSD.org
HOMEPAGE=		https://sourceforge.net/projects/wendzelnntpd
COMMENT=		Free Usenet server with SQL backend and RBAC
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		YES
USE_TOOLS+=		bison flex gmake bash:run
USE_FEATURES=		err regcomp snprintf

REPLACE_BASH=		create_certificate_raw

SUBST_CLASSES+=		openssl
SUBST_MESSAGE.openssl=	Insert absolute path for openssl binary.
SUBST_STAGE.openssl=	pre-configure
SUBST_FILES.openssl=	create_certificate_raw
SUBST_SED.openssl=	-e 's,openssl ,${BUILDLINK_PREFIX.openssl}/bin/openssl ,g'

# Directory for example config file
EGDIR=			${PREFIX}/share/examples/wendzelnntpd
WRKSRC=			${WRKDIR}/cdpxe-WendzelNNTPd-bf144dc
BUILD_DEFS+=		VARBASE
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/wendzelnntpd \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700
OWN_DIRS_PERMS+=	${VARBASE}/spool/news/wendzelnntpd \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0700
CONF_FILES_PERMS=	${EGDIR}/wendzelnntpd/wendzelnntpd.conf \
			${PKG_SYSCONFDIR}/wendzelnntpd/wendzelnntpd.conf \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0600
INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR} \
			UDBDIR=${PREFIX}/var/spool/news/wendzelnntpd \
			SQLITEINST=NO CREATE_CERTIFICATES=NO

RCD_SCRIPTS=		wendzelnntpd

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/mhash/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
