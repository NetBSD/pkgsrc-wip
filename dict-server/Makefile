# $NetBSD: Makefile,v 1.2 2006/07/12 13:15:18 cheusov Exp $

DISTNAME=	dictd-1.10.6
PKGNAME=	dict-server-1.10.6
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dict/} \
		ftp://ftp.dict.org/pub/dict/

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.dict.org/
COMMENT=	Dictionary Service Protocol server

USE_TOOLS+=		gmake yacc
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-cflags=${CFLAGS:M*:Q}

MESSAGE_SUBST+=		VARBASE="${VARBASE}"

PKG_GROUPS=	${DICTD_GROUP}
PKG_USERS=	${DICTD_USER}:${DICTD_GROUP}::Dictionary\ protocol\ server\ user:/nonexistent:${NOLOGIN}

RCD_SCRIPTS=	dictd

# for -L /var/log/dictd/<filename_or_pattern>
OWN_DIRS_PERMS=	${VARBASE}/log/dictd ${DICTD_USER} ${DICTD_GROUP} 0750


BUILD_TARGET=	dictd dictzip

INSTALL_TARGET=	install.dictd install.dictzip install.dictfmt

EGDIR=		${PREFIX}/share/examples/dict-server
CONF_FILES=	${EGDIR}/dictd.conf \
		${PKG_SYSCONFDIR}/dictd.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${WRKSRC}/examples/dictd1.conf ${EGDIR}/dictd.conf
	${INSTALL_DATA_DIR} ${PREFIX}/share/dictd

.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
