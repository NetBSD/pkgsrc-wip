# $NetBSD: Makefile,v 1.1.1.1 2004/11/09 19:41:53 poppnk Exp $
#

DISTNAME=		aircrack-2.1
CATEGORIES=		wip security
MASTER_SITES=		http://www.cr0.net:8040/code/network/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.cr0.net:8040/code/network/aircrack/
COMMENT=		802.11 WEP key cracker

USE_BUILDLINK3=		yes

SUBST_CLASSES=pfx
SUBST_STAGE.pfx=patch
SUBST_FILES.pfx=Makefile
SUBST_SED.pfx=-e 's,/usr/local,${PREFIX},g'

.include "../../mk/bsd.pkg.mk"
