# $NetBSD: Makefile,v 1.2 2004/10/15 10:44:10 poppnk Exp $
#

DISTNAME=		proxychains-2.1
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=proxychains/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://proxychains.sourceforge.net/
COMMENT=			Chain multiple proxies in a transparent way

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=	make
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

SUBST_CLASSES=ooo
SUBST_STAGE.ooo=pre-build
SUBST_FILES.ooo=proxychains/Makefile
SUBST_SED.ooo=-e s!OBJEXT\ =!OBJEXT=o!

SUBST_CLASSES+=pfx
SUBST_STAGE.pfx=pre-build
SUBST_FILES.pfx=proxychains/main.c
SUBST_SED.pfx=-e s!/usr!${PREFIX}!

.include "../../mk/bsd.pkg.mk"
