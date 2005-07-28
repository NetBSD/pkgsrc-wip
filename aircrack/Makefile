# $NetBSD: Makefile,v 1.5 2005/07/28 17:34:48 poppnk Exp $
#

DISTNAME=		aircrack-2.2-beta11
PKGNAME=		aircrack-2.2b11
CATEGORIES=		wip security
MASTER_SITES=		http://www.cr0.net:8040/code/network/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.cr0.net:8040/code/network/aircrack/
COMMENT=		802.11 WEP key cracker

ONLY_FOR_PLATFORM=	Linux-[2-9]*-*

NO_CONFIGURE=		yes
USE_TOOLS+=		gmake

#SUBST_CLASSES=pfx
#SUBST_STAGE.pfx=patch
#SUBST_FILES.pfx=Makefile
#SUBST_SED.pfx=-e 's,/usr/local,${PREFIX},g'

.include "../../mk/bsd.pkg.mk"
