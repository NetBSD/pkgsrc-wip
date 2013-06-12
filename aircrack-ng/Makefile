# $NetBSD: Makefile,v 1.19 2013/06/12 17:45:48 moubctez Exp $

DISTNAME=	aircrack-ng-1.2-beta1
PKGNAME=	aircrack-ng-1.2b1
CATEGORIES=	security net
MASTER_SITES=	http://download.aircrack-ng.org/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.aircrack-ng.org/
COMMENT=	Tools for auditing wireless networks
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS+=	bin sbin ${PKGMANDIR}/man1 ${PKGMANDIR}/man8

USE_TOOLS+=		bash gmake
REPLACE_BASH+=		scripts/airdriver-ng
REPLACE_BASH+=		scripts/airodump-ng-oui-update

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
