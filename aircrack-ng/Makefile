# $NetBSD: Makefile,v 1.2 2006/09/11 17:23:52 poppnk Exp $
#

DISTNAME=		aircrack-ng-0.6.1
CATEGORIES=		security
MASTER_SITES=		http://download.aircrack-ng.org/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.aircrack-ng.org/
COMMENT=		Tools for auditing wireless networks

SUBST_CLASSES+=pfx
SUBST_STAGE.pfx=pre-build
SUBST_FILES.pfx=Makefile
SUBST_SED.pfx=-e 's|/usr/local|${PREFIX}|g'

ONLY_FOR_PLATFORM+=	Linux-*-*

.include "../../mk/bsd.pkg.mk"
