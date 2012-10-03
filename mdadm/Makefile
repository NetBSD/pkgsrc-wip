# $NetBSD: Makefile,v 1.6 2012/10/03 15:09:53 asau Exp $
#

DISTNAME=		mdadm-1.8.1
CATEGORIES=		sysutils linux
MASTER_SITES=		http://www.cse.unsw.edu.au/~neilb/source/mdadm/ \
			http://www.kernel.org/pub/linux/utils/raid/mdadm/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.cse.unsw.edu.au/~neilb/source/mdadm/ANNOUNCE
COMMENT=		RAID management for Linux systems

PKG_DESTDIR_SUPPORT=	none

USE_TOOLS+= gmake

ONLY_FOR_PLATFORM=Linux-*-*

SUBST_CLASSES+=pfx
SUBST_FILES.pfx=Makefile
SUBST_STAGE.pfx=configure
SUBST_SED.pfx=-e 's,DESTDIR\ =,DESTDIR=\"${PREFIX}\",'

.include "../../mk/bsd.pkg.mk"
