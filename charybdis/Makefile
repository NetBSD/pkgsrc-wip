# $NetBSD$

DISTNAME=	charybdis-4.0
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=charybdis-ircd/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/freenode/ircd-seven/
COMMENT=	Freenode's IRC server daemon
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	automake autoconf autoreconf

GNU_CONFIGURE=	yes

BUILD_DEFS+=	VARBASE

# Put this in mk/defaults/mk.conf
CHARYBDIS_USER?=	charybdis
CHARYBDIS_GROUP?=	charybdis

PKG_USERS_VARS+=	CHARYBDIS_USER
PKG_GROUPS_VARS+=	CHARYBDIS_GROUP

PKG_USERS=		${CHARYBDIS_USER}:${CHARYBDIS_GROUP}
PKG_GROUPS=		${CHARYBDIS_GROUP}

CHARYBDIS_PID_DIR=	${VARBASE}/run  # default directory for PID files
FILES_SUBST+=		CHARYBDIS_PID_DIR=${CHARYBDIS_PID_DIR}

CONFIGURE_ARGS+=	--with-rundir=${CHARYBDIS_PID_DIR}

EGDIR=		${PREFIX}/share/examples/charybdis

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

CFLAGS+=		-DCHARYBDIS_USER='"${CHARYBDIS_USER}"'

pre-configure:
	${RUN} cd ${WRKSRC} && ./autogen.sh

MAKE_DIRS+=	${PKG_SYSCONFDIR}
.for f in ircd.conf.example ircd.motd reference.conf
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

RCD_SCRIPTS+=		charybdis

.include "../../mk/bsd.pkg.mk"
