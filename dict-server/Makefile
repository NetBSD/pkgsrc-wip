# $NetBSD: Makefile,v 1.12 2006/07/20 13:01:26 cheusov Exp $

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

PKG_GROUPS=		dictd
PKG_USERS=		dictd:dictd
PKG_GECOS.dictd=	Dictionary\ protocol\ server\ user

RCD_SCRIPTS=		dictd

# for -L /var/log/dictd/<filename_or_pattern>
OWN_DIRS_PERMS=	${VARBASE}/log/dictd dictd dictd 0750


BUILD_TARGET=	dictd dictzip dictfmt

INSTALL_TARGET=	install.dictd install.dictzip install.dictfmt

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
PKGDOCDIR=	${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS+=	share/dictd ${EGDIR} ${PKGDOCDIR}

CONF_FILES=	${EGDIR}/dictd.conf \
		${PKG_SYSCONFDIR}/dictd.conf

EXTRA_DOC_FILES=	COPYING NEWS README INSTALL
EXTRA_EXAMPLES_FILES=	dictd1.conf dictd2.conf \
			dictd3.conf dictd4.conf dictd_complex.conf \
			dictd_mime.conf dictd_plugin_dbi.conf \
			dictd_site.txt dictd_virtual.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${.CURDIR}/files/dictd.conf ${EGDIR}/
.for i in ${EXTRA_DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PKGDOCDIR}
.endfor
.for i in ${EXTRA_EXAMPLES_FILES}
	${INSTALL_DATA} ${WRKSRC}/examples/${i} ${EGDIR}
.endfor

.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
