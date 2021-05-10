# $NetBSD$

DISTNAME=	v2.1.3
PKGNAME=	wendzelnntpd-${DISTNAME:S/v//}
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wendzelnntpd/}

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/wendzelnntpd
COMMENT=	Free Usenet server with SQL backend and RBAC
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	bison flex
USE_FEATURES=	err regcomp snprintf

BUILD_DEFS+=		VARBASE
INSTALLATION_DIRS=	sbin share/doc/wendzelnntpd share/man/man8
SPECIAL_PERMS+=		sbin/wendzelnntpd \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
SPECIAL_PERMS+=		sbin/wendzelnntpadm \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
OWN_DIRS_PERMS+=	${VARBASE}/spool/news/wendzelnntpd \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
CONF_FILES_PERMS=	${DESTDIR}${PREFIX}/share/examples/wendzelnntpd/wendzelnntpd.conf \
			${PKG_SYSCONFDIR}/wendzelnntpd.conf \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0644
WRKSRC=			${WRKDIR}/cdpxe-WendzelNNTPd-17d557d

do-configure:
	cd ${WRKSRC} && env MYSQL=NO CONFDIR=${PKG_SYSCONFDIR}/etc \
		FAKECDIR=${DESTDIR}${PKG_SYSCONFDIR} \
		${CONFIGURE_ENV} ${CONFIG_SHELL} ./configure

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/mhash/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
