# $NetBSD: Makefile,v 1.4 2005/06/25 23:10:33 ishit Exp $
#

DISTNAME=		aircrack-2.1
CATEGORIES=		wip security
MASTER_SITES=		http://www.cr0.net:8040/code/network/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.cr0.net:8040/code/network/aircrack/
COMMENT=		802.11 WEP key cracker

ONLY_FOR_PLATFORM=	Linux-[2-9]*-*

NO_CONFIGURE=		yes

#SUBST_CLASSES=pfx
#SUBST_STAGE.pfx=patch
#SUBST_FILES.pfx=Makefile
#SUBST_SED.pfx=-e 's,/usr/local,${PREFIX},g'

.include "../../mk/bsd.pkg.mk"
