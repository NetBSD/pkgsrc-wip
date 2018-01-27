# $NetBSD$

GITHUB_PROJECT=	rmilter
DISTNAME=	1.10.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=vstakhov/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	bartosz.kuzma@gmail.com
HOMEPAGE=	https://github.com/vstakhov/rmilter/
COMMENT=	Milter for rspamd
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/rmilter-1.10.0
USE_CMAKE=	yes

BUILD_DEFS+=	VARBASE

RMILTER_USER?=		rmilter
RMILTER_GROUP?=		rmilter
PKG_GROUPS=		${RMILTER_GROUP}
PKG_USERS=		${RMILTER_USER}:${RMILTER_GROUP}
PKG_GROUPS_VARS=	RMILTER_GROUP
PKG_USERS_VARS=		RMILTER_USER
PKG_GECOS.${R_USER}=	rspamd user

CMAKE_ARGS+=	-DEXAMPLESDIR:PATH=${EGDIR}
CMAKE_ARGS+=	-DMANDIR:PATH=${PREFIX}/${PKGMANDIR}
CMAKE_ARGS+=	-DRMILTER_USER=${RMILTER_USER}
CMAKE_ARGS+=	-DRMILTER_GROUP=${RMILTER_GROUP}
CMAKE_ARGS+=	-DENABLE_DKIM=OFF

PKG_SYSCONFSUBDIR=	rmilter
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
RUNDIR=			${VARBASE}/run/rmilter

RCD_SCRIPTS=		rmilter

INSTALLATION_DIRS+=	${EGDIR}

OWN_DIRS_PERMS+=	${RUNDIR} ${RMILTER_USER} ${RMILTER_GROUP} 0755

CONF_FILES=	${EGDIR}/rmilter.conf ${PKG_SYSCONFDIR}/rmilter.conf
CONF_FILES+=	${EGDIR}/rmilter-grey.conf ${PKG_SYSCONFDIR}/rmilter-grey.conf

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-configure
SUBST_FILES.path=	src/main.c
SUBST_SED.path=		-e 's|/usr/local/etc/|${PKG_SYSCONFDIR}/|g'

post-install:
	${INSTALL_DATA} ${WRKSRC}/rmilter.conf.sample \
		${DESTDIR}${EGDIR}/rmilter.conf
	${INSTALL_DATA} ${WRKSRC}/rmilter-grey.conf \
		${DESTDIR}${EGDIR}/rmilter-grey.conf

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libmemcached/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mail/libmilter/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
