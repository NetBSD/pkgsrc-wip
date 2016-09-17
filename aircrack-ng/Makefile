# $NetBSD: Makefile,v 1.21 2015/02/09 17:28:42 leot1990 Exp $

DISTNAME=	aircrack-ng-1.2-rc4
PKGNAME=	aircrack-ng-1.2rc4
CATEGORIES=	security net
MASTER_SITES=	http://download.aircrack-ng.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.aircrack-ng.org/
COMMENT=	Tools for auditing wireless networks
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS+=	bin sbin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8

USE_LANGUAGES=		c c++
USE_TOOLS+=		bash gmake
REPLACE_BASH+=		scripts/airodump-ng-oui-update

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_MESSAGE.paths=	Fixing hard-coded paths
SUBST_FILES.paths=	src/airodump-ng.h
SUBST_FILES.paths+=	scripts/*
SUBST_FILES.paths+=	scripts/*/*
SUBST_FILES.paths+=	scripts/*/*/*
SUBST_FILES.paths+=	scripts/*/*/*/*
SUBST_SED.paths=	-e 's,/usr/local/etc,${PKG_SYSCONFDIR},g'

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
