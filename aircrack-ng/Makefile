# $NetBSD: Makefile,v 1.11 2009/03/29 16:33:22 tnn2 Exp $

DISTNAME=		aircrack-ng-1.0-rc3
PKGNAME=		aircrack-ng-1.0rc3
CATEGORIES=		security net
MASTER_SITES=		http://download.aircrack-ng.org/

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		http://www.aircrack-ng.org/
COMMENT=		Tools for auditing wireless networks

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS+=	bin sbin ${PKGMANDIR}/man1

USE_TOOLS+=		bash gmake
REPLACE_BASH+=		scripts/airdriver-ng

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
