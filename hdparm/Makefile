# $NetBSD: Makefile,v 1.5 2012/09/29 17:05:54 asau Exp $
#

DISTNAME=		hdparm-6.6
CATEGORIES=		linux sysutils
MASTER_SITES=		http://www.ibiblio.org/pub/Linux/system/hardware/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.ibiblio.org/pub/Linux/system/hardware/
COMMENT=		Linux tool for view and manipulate IDE drive parameters

ONLY_FOR_PLATFORM=	Linux-*-*

USE_TOOLS+=		gmake
SUBST_CLASSES+= prefix

SUBST_STAGE.prefix=pre-build
SUBST_FILES.prefix=Makefile
SUBST_SED.prefix  =-e s,/usr,,g \
		   -e s,DESTDIR\ =,DESTDIR=${PREFIX},g

PKG_DESTDIR_SUPPORT=	none

.include "../../mk/bsd.pkg.mk"
