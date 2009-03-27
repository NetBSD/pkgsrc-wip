# $NetBSD: Makefile,v 1.10 2009/03/27 09:37:50 thomasklausner Exp $

DISTNAME=		aircrack-ng-1.0-rc2
PKGNAME=		aircrack-ng-1.0rc2
CATEGORIES=		security
MASTER_SITES=		http://download.aircrack-ng.org/

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		http://www.aircrack-ng.org/
COMMENT=		Tools for auditing wireless networks

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS+=	bin sbin ${PKGMANDIR}/man1

USE_TOOLS+=		bash gmake
REPLACE_BASH+=		airdriver-ng

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
