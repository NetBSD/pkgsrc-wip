# $NetBSD: Makefile,v 1.17 2012/09/24 16:56:32 asau Exp $

DISTNAME=		aircrack-ng-1.1
CATEGORIES=		security net
MASTER_SITES=		http://download.aircrack-ng.org/

MAINTAINER=		tnn@NetBSD.org
HOMEPAGE=		http://www.aircrack-ng.org/
COMMENT=		Tools for auditing wireless networks

LICENSE=		gnu-gpl-v3

INSTALLATION_DIRS+=	bin sbin ${PKGMANDIR}/man1

USE_TOOLS+=		bash gmake
REPLACE_BASH+=		scripts/airdriver-ng
REPLACE_BASH+=		scripts/airodump-ng-oui-update

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
