# $NetBSD: Makefile,v 1.1.1.1 2004/11/17 19:16:52 poppnk Exp $
#

DISTNAME=		mdadm-1.8.1
CATEGORIES=		wip sysutils linux
MASTER_SITES=		http://www.cse.unsw.edu.au/~neilb/source/mdadm/ \
			http://www.kernel.org/pub/linux/utils/raid/mdadm/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.cse.unsw.edu.au/~neilb/source/mdadm/ANNOUNCE
COMMENT=		RAID management for Linux systems

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+= make

ONLY_FOR_PLATFORM=Linux-*-*

SUBST_CLASSES=pfx
SUBST_FILES.pfx=Makefile
SUBST_STAGE.pfx=configure
SUBST_SED.pfx=-e 's,DESTDIR\ =,DESTDIR=\"${PREFIX}\",'

.include "../../mk/bsd.pkg.mk"
