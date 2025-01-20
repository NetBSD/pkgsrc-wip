# $NetBSD$

DISTNAME=	coturn-4.6.3
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=coturn/}
GITHUB_PROJECT=	coturn

MAINTAINER=	kethzer.dr@gmail.com
#MAINTAINER+=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/coturn/coturn
COMMENT=	TURN and STUN server (for VoIP/webrtc)
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

HAS_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

COTURN_USER?=	coturn
COTURN_GROUP?=	${COTURN_USER}
COTURN_DATA?=	${VARBASE}/db/coturn
BUILD_DEFS+=	COTURN_USER COTURN_GROUP COTURN_DATA VARBASE

OWN_DIRS_PERMS+=		${COTURN_DATA} ${COTURN_USER} ${COTURN_GROUP} 0770

PKG_USERS_VARS=			COTURN_USER
PKG_GROUPS_VARS=		COTURN_GROUP
PKG_GROUPS=			${COTURN_GROUP}
PKG_USERS=			${COTURN_USER}:${COTURN_GROUP}
PKG_GECOS.${COTURN_USER}=	coturn daemon user
PKG_HOME.${COTURN_USER}=	${COTURN_DATA}
PKG_SHELL.${COTURN_USER}=	${NOLOGIN}

RCD_SCRIPTS=		turnserver

FILES_SUBST+=	COTURN_USER=${COTURN_USER:Q}
FILES_SUBST+=	COTURN_GROUP=${COTURN_GROUP:Q}
FILES_SUBST+=	PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

# Pass cflags/libs
CONFIGURE_ENV+=		PTHREAD_LIBS=-pthread TURN_DISABLE_RPATH=1
CONFIGURE_ENV+=		LIBEVENT_OPENSSL_CFLAGS="-I${BUILDLINK_PREFIX.libevent}/include"
CONFIGURE_ENV+=		LIBEVENT_OPENSSL_LIBS="-L${BUILDLINK_PREFIX.libevent}/lib -levent_openssl -levent"

CONFIGURE_ARGS+=	--prefix=${PREFIX}
# Use coturn as docs/examples subdir name.  \todo No command-line argument?
CONFIGURE_ENV+=		PORTNAME=coturn
# Defaults to ${PREFIX}/etc; respect pkgsrc tunable.
CONFIGURE_ARGS+=	--confdir=${PKG_SYSCONFDIR}
# Defaults to ${PREFIX}/var; give it a subdirectory.
CONFIGURE_ARGS+=	--localstatedir=${COTURN_DATA}

# \todo Why is there a db installed in /var?  Won't that overwrite the user's database?

post-install:
	${RM} ${DESTDIR}${PKG_SYSCONFDIR}/turnserver.conf.default

CONF_FILES+=		${PREFIX}/share/examples/coturn/etc/turnserver.conf ${PKG_SYSCONFDIR}/turnserver.conf


.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
