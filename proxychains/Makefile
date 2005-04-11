# $NetBSD: Makefile,v 1.4 2005/04/11 21:14:51 tvierling Exp $
#

DISTNAME=		proxychains-2.1
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=proxychains/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://proxychains.sourceforge.net/
COMMENT=			Chain multiple proxies in a transparent way

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

SUBST_CLASSES+=etc
SUBST_STAGE.etc=pre-build
SUBST_FILES.etc=proxychains/libproxychains.c
SUBST_SED.etc=-e s!/etc!${PREFIX}/etc!

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/proxychains/
	${INSTALL_DATA} ${WRKSRC}/proxychains/proxychains.conf \
		${PREFIX}/share/examples/proxychains/

.include "../../mk/bsd.pkg.mk"
