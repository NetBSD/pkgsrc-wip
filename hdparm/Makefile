# $NetBSD: Makefile,v 1.1.1.1 2004/08/02 22:08:52 poppnk Exp $
#

DISTNAME=		hdparm-5.4
CATEGORIES=		wip linux sysutils
MASTER_SITES=		http://www.ibiblio.org/pub/Linux/system/hardware/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.ibiblio.org/pub/Linux/system/hardware/
COMMENT=		Linux tool for view and manipulate IDE drive parameters

ONLY_FOR_PLATFORM=	Linux-*-*

USE_BUILDLINK3=		yes

SUBST_CLASSES+= prefix

SUBST_STAGE.prefix=pre-build
SUBST_FILES.prefix=Makefile
SUBST_SED.prefix  =-e s,/usr,,g \
		   -e s,DESTDIR\ =,DESTDIR=${PREFIX},g

.include "../../mk/bsd.pkg.mk"
