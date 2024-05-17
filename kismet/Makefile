# $NetBSD: Makefile,v 1.75 2024/05/06 08:40:30 jperkin Exp $

DISTNAME=		kismet-2023-07-R1
PKGNAME=		kismet-2023.07.01
CATEGORIES=		net
MASTER_SITES=		https://www.kismetwireless.net/code/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.kismetwireless.net/
COMMENT=		802.11 wireless network detector, sniffer and IDS

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes

# kismet does not (yet) hardcode this anywhere, so we can take advantage of
# that and install the config files directly into EGDIR.
#
# XXX: this isn't true, reset this back to PKG_SYSCONFDIR and install the
# config files to EGDIR manually.
CONFIGURE_ARGS+=	--sysconfdir=${EGDIR}

# lang/python doesn't support multiple directories containing setup.py
CONFIGURE_ARGS+=	--disable-python-tools

LIBS.NetBSD+=		-lm

.include "../../mk/bsd.prefs.mk"

KISMET_USER?=			kismet
KISMET_GROUP?=			kismet
PKG_GROUPS=			${KISMET_GROUP}
PKG_USERS=			${KISMET_USER}:${KISMET_GROUP}
PKG_GECOS.${KISMET_USER}=	Kismet user
PKG_HOME.${KISMET_USER}=	${VARBASE}/log/kismet
PKG_GROUPS_VARS+=		KISMET_GROUP
PKG_USERS_VARS+=		KISMET_USER
BUILD_DEFS+=			VARBASE

PKG_SYSCONFSUBDIR=	${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

KISMET_CONF_FILES=	kismet kismet_httpd kismet_memory
KISMET_CONF_FILES+=	kismet_logging kismet_filter kismet_uav
KISMET_CONF_FILES+=	kismet_80211 kismet_wardrive

.for c in ${KISMET_CONF_FILES}
CONF_FILES+=		${EGDIR}/${c}.conf ${PKG_SYSCONFDIR}/${c}.conf
.endfor
OWN_DIRS_PERMS+=	${VARBASE}/log/kismet ${KISMET_USER} ${KISMET_GROUP} 0700

INSTALLATION_DIRS+=	bin ${EGDIR}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/libwebsockets/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
