# $NetBSD: Makefile,v 1.40 2019/05/23 19:23:21 rillig Exp $

DISTNAME=	tinyproxy-1.10.0
PKGREVISION=	5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=tinyproxy/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tinyproxy.github.io/
COMMENT=	Lightweight HTTP/SSL proxy
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=		asciidoc-[0-9]*:../../textproc/asciidoc

BUILD_DEFS+=		VARBASE

PKG_SYSCONFSUBDIR=	tinyproxy

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
CONFIGURE_ARGS+=	--enable-transparent

RCD_SCRIPTS=		tinyproxy

.include "../../mk/bsd.prefs.mk"

TINYPROXY_USER?=	tinyproxy
TINYPROXY_GROUP?=	tinyproxy
PKG_GROUPS=		${TINYPROXY_GROUP}
PKG_USERS=		${TINYPROXY_USER}:${TINYPROXY_GROUP}
PKG_GROUPS_VARS+=	TINYPROXY_GROUP
PKG_USERS_VARS=		TINYPROXY_USER
FILES_SUBST+=		TINYPROXY_USER=${TINYPROXY_USER:Q}
FILES_SUBST+=		TINYPROXY_GROUP=${TINYPROXY_GROUP:Q}

EGDIR=		${PREFIX}/share/examples/tinyproxy
CONF_FILES=	${EGDIR}/tinyproxy.conf.default ${PKG_SYSCONFDIR}/tinyproxy.conf

SUBST_CLASSES+=		docs
SUBST_STAGE.docs=	pre-configure
SUBST_FILES.docs=	docs/man5/tinyproxy.conf.txt.in docs/man8/tinyproxy.txt.in etc/tinyproxy.conf.in
SUBST_VARS.docs=	TINYPROXY_USER
SUBST_VARS.docs+=	TINYPROXY_GROUP
SUBST_VARS.docs+=	PKG_SYSCONFDIR
SUBST_VARS.docs+=	VARBASE

INSTALLATION_DIRS=	${EGDIR} share/doc/tinyproxy

OWN_DIRS_PERMS+=	${VARBASE}/log/tinyproxy ${TINYPROXY_USER} ${TINYPROXY_GROUP} 0755
OWN_DIRS_PERMS+=	${VARBASE}/run/tinyproxy ${TINYPROXY_USER} ${TINYPROXY_GROUP} 0755

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/tinyproxy.conf \
		${DESTDIR}${EGDIR}/tinyproxy.conf.default
	${INSTALL_DATA} ${WRKSRC}/docs/filter-howto.txt \
		${DESTDIR}${PREFIX}/share/doc/tinyproxy/

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
