# $NetBSD: Makefile,v 1.6 2012/11/25 23:32:20 othyro Exp $
#

DISTNAME=		hdparm-6.6
CATEGORIES=		linux sysutils
MASTER_SITES=		http://www.ibiblio.org/pub/Linux/system/hardware/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ibiblio.org/pub/Linux/system/hardware/
COMMENT=		Linux tool for view and manipulate IDE drive parameters

ONLY_FOR_PLATFORM=	Linux-*-*

USE_TOOLS+=	gmake
SUBST_CLASSES+=	prefix

SUBST_STAGE.prefix=	pre-build
SUBST_FILES.prefix=	Makefile
SUBST_SED.prefix  =	-e s,/usr,,g \
			-e s,DESTDIR\ =,DESTDIR=${PREFIX},g


.include "../../mk/bsd.pkg.mk"
