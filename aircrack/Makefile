# $NetBSD: Makefile,v 1.7 2006/05/01 14:20:07 shattered Exp $
#

DISTNAME=		aircrack-2.2-beta11
PKGNAME=		aircrack-2.2b11
CATEGORIES=		security
MASTER_SITES=		http://www.wirelessdefence.org/Contents/Files/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.wirelessdefence.org/Contents/AircrackMain.htm
COMMENT=		802.11 WEP key cracker

ONLY_FOR_PLATFORM=	Linux-[2-9]*-*

NO_CONFIGURE=		yes
USE_TOOLS+=		gmake

#SUBST_CLASSES=pfx
#SUBST_STAGE.pfx=patch
#SUBST_FILES.pfx=Makefile
#SUBST_SED.pfx=-e 's,/usr/local,${PREFIX},g'

.include "../../mk/bsd.pkg.mk"
