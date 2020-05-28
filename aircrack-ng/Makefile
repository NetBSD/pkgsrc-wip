# $NetBSD: Makefile,v 1.21 2015/02/09 17:28:42 leot1990 Exp $

DISTNAME=	aircrack-ng-1.2-rc4
PKGNAME=	aircrack-ng-1.2rc4
PKGREVISION=	1
CATEGORIES=	security net
#MASTER_SITES=	http://download.aircrack-ng.org/
MASTER_SITES=	${MASTER_SITE_GITHUB:=aircrack-ng/}
GITHUB_TAG=	caa946dad310ce6bf53b08ba5fc98a2d7c7a8053

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.aircrack-ng.org/
COMMENT=	Tools for auditing wireless networks
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS+=	bin sbin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		bash gmake autoconf automake
REPLACE_BASH+=		scripts/airodump-ng-oui-update

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_MESSAGE.paths=	Fixing hard-coded paths
SUBST_FILES.paths=	src/airodump-ng.h
SUBST_FILES.paths+=	scripts/*
SUBST_FILES.paths+=	scripts/*/*/*
SUBST_SED.paths=	-e 's,/usr/local/etc,${PKG_SYSCONFDIR},g'

pre-configure:
	ls -ld ${WRKSRC}
	cd ${WRKSRC} && autoreconf -vif

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
