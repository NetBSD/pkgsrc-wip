# $NetBSD: Makefile,v 1.10 2006/07/18 20:43:11 cheusov Exp $

DISTNAME=	dictd-1.10.7
PKGNAME=	dict-server-1.10.7
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dict/} \
		ftp://ftp.dict.org/pub/dict/

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://www.dict.org/
COMMENT=	Dictionary Service Protocol server

USE_TOOLS+=		gmake yacc m4:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-cflags=${CFLAGS:M*:Q}
CONFIGURE_ARGS+=	--disable-plugin

MESSAGE_SUBST+=		VARBASE="${VARBASE}"
MESSAGE_SUBST+=		PATH_TO_M4="${TOOLS_PATH.m4}"
FILES_SUBST+=		PATH_TO_M4="${TOOLS_PATH.m4}"

INSTALLATION_DIRS+=	share/dictd

PKG_GROUPS=		dictd
PKG_USERS=		dictd:dictd
PKG_GECOS.dictd=	Dictionary\ protocol\ server\ user

RCD_SCRIPTS=		dictd

# for -L /var/log/dictd/<filename_or_pattern>
OWN_DIRS_PERMS=	${VARBASE}/log/dictd ${DICTD_USER} ${DICTD_GROUP} 0750


BUILD_TARGET=	dictd dictzip

INSTALL_TARGET=	install.dictd install.dictzip install.dictfmt

EGDIR=		${PREFIX}/share/examples/dict-server
CONF_FILES=	${EGDIR}/dictd.conf \
		${PKG_SYSCONFDIR}/dictd.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${.CURDIR}/files/dictd.conf ${EGDIR}/

.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
