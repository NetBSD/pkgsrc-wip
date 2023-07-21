# $NetBSD: Makefile,v 1.2 2023/07/20 11:03:00 zilti Exp $

DISTNAME=	bw_web_v${PKGVER}
PKGNAME=	vaultwarden-web_valut-${PKGVER}
PKGVER=		2023.4.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=dani-garcia/bw_web_builds/releases/download/v${PKGVER}/}

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	zilti@NetBSD.org
HOMEPAGE=	https://github.com/dani-garcia/bw_web_builds
COMMENT=	Bitwarden web vault with the patches to make it work with security/vaultwarden

LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/web-vault
NO_BUILD=	yes
GENERATE_PLIST=	yes
USE_TOOLS=	pax

APACHE_USER?=		nginx
APACHE_GROUP?=		nginx
PKG_GROUPS=		${APACHE_GROUP}
PKG_USERS=		${APACHE_USER}:${APACHE_GROUP}
PKG_USERS_VARS=		APACHE_USER
PKG_GROUPS_VARS=	APACHE_GROUP

INSTALLATION_DIRS=	share/vaultwarden-web-vault
PKG_DESTDIR_SUPPORT=	destdir

do-install:
	${PAX} -wr ${WRKSRC} ${DESTDIR}${PREFIX}${INSTALLATION_DIRS};

.include "../../mk/bsd.pkg.mk"
