# $NetBSD$

GITHUB_PROJECT=	gerbera
GITHUB_TAG=	v1.4.0
DISTNAME=	v1.4.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=gerbera/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gerbera/gerbera/
COMMENT=	UPnP Media Server
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

USE_CMAKE=	yes

RCD_SCRIPTS=	gerbera

.include "../../mk/bsd.prefs.mk"

PKG_GROUPS=	${GERBERA_GROUP}
PKG_USERS=	${GERBERA_USER}:${GERBERA_GROUP}

PKG_GECOS.${GERBERA_USER}=	Gerbera Server
PKG_HOME.${GERBERA_USER}=	${VARBASE}/gerbera

PKG_SYSCONFSUBDIR=	gerbera
EGDIR=			${PREFIX}/share/examples/gerbera
CONF_FILES_PERMS+=	${EGDIR}/config.xml ${PKG_SYSCONFDIR}/config.xml \
			${GERBERA_USER} ${GERBERA_GROUP} 0640

FILES_SUBST+=		PKG_HOME=${PKG_HOME.${GERBERA_USER}:Q}
FILES_SUBST+=		GERBERA_GROUP=${GERBERA_GROUP}
FILES_SUBST+=		GERBERA_USER=${GERBERA_USER}
FILES_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR}

GERBERA_HOME=		${PKG_HOME.${GERBERA_USER}}

SUBST_CLASSES+=		config
SUBST_FILES.config=	config.xml
SUBST_VARS.config=	GERBERA_HOME PREFIX OPSYS
SUBST_STAGE.config=	pre-configure

INSTALLATION_DIRS+=	share/examples/gerbera

post-extract:
	${CP} ${FILESDIR}/config.xml.in ${WRKSRC}/config.xml

post-install:
	${INSTALL_DATA} ${WRKSRC}/config.xml ${DESTDIR}${EGDIR}/config.xml

.include "options.mk"

.include "../../audio/taglib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libinotify/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../multimedia/libmatroska/buildlink3.mk"
.include "../../net/libupnp/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
