# $NetBSD: Makefile,v 1.15 2010/04/25 20:17:11 moubctez Exp $

DISTNAME=		aircrack-ng-1.1
CATEGORIES=		security net
MASTER_SITES=		http://download.aircrack-ng.org/

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		http://www.aircrack-ng.org/
COMMENT=		Tools for auditing wireless networks

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS+=	bin sbin ${PKGMANDIR}/man1

USE_TOOLS+=		bash gmake
REPLACE_BASH+=		scripts/airdriver-ng
REPLACE_BASH+=		scripts/airodump-ng-oui-update

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
