# $NetBSD$

#DISTNAME=		v2.1.3
#PKGNAME=		wendzelnntpd-${DISTNAME:S/v//}
DISTNAME=		wendzelnntpd-2.2.0git
CATEGORIES=		news
#MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wendzelnntpd/}
MASTER_SITES=		${MASTER_SITE_GITHUB:=cdpxe/}
#GITHUB_RELEASE=	v${PKGVERSION_NOREV}
GITHUB_TAG=		73d8e69871ff09444b6cf5aa089df5ce06112758

MAINTAINER=		micha@NetBSD.org
HOMEPAGE=		https://sourceforge.net/projects/wendzelnntpd
COMMENT=		Free Usenet server with SQL backend and RBAC
LICENSE=		gnu-gpl-v3

USE_TOOLS+=		bison flex gmake
USE_FEATURES=		err regcomp snprintf

BUILD_DEFS+=		VARBASE

# Build system expects PREFIX as part of DESTDIR
SUBST_CLASSES+=		make
SUBST_MESSAGE.make=	Adjust Makefile
SUBST_STAGE.make=	pre-configure
SUBST_FILES.make+=	Makefile
SUBST_SED.make+=	-e 's,$$(DESTDIR),$$(DESTDIR)$$(PREFIX),g'

# Directory for example config file
FAKECDIR=		${DESTDIR}${PREFIX}/share/examples/wendzelnntpd

INSTALLATION_DIRS=	sbin share/doc/wendzelnntpd ${PKGMANDIR}/man8
SPECIAL_PERMS+=		sbin/wendzelnntpd \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
SPECIAL_PERMS+=		sbin/wendzelnntpadm \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 755
OWN_DIRS_PERMS+=	${VARBASE}/spool/news/wendzelnntpd \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 700
CONF_FILES_PERMS=	${FAKECDIR}/wendzelnntpd.conf \
			${PKG_SYSCONFDIR}/wendzelnntpd.conf \
			${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0644
WRKSRC=			${WRKDIR}/WendzelNNTPd-73d8e69871ff09444b6cf5aa089df5ce06112758

CONFIGURE_ENV+=		MYSQL=NO
CONFIGURE_ENV+=		POSTGRES=NO
CONFIGURE_ENV+=		CONFDIR=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		FAKECDIR=${FAKECDIR}
CONFIGURE_ENV+=		DESTDIR=${DESTDIR}

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ${CONFIG_SHELL} ./configure

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/mhash/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
