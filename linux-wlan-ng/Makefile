# $NetBSD: Makefile,v 1.2 2005/04/11 21:13:54 tvierling Exp $
#

DISTNAME=		linux-wlan-ng-0.2.1pre23
CATEGORIES=		wip net linux
MASTER_SITES=		ftp://ftp.linux-wlan.org/pub/linux-wlan-ng/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.linux-wlan.com/
COMMENT=		Linux utilities for wireless prism2 cards

USE_GNU_TOOLS+=		make
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-d

ONLY_FOR_PLATFORM=	Linux-*-*

SUBST_CLASSES=sbin etc

SUBST_STAGE.sbin=post-configure
SUBST_FILES.sbin=${WRKSRC}/config.mk
SUBST_SED.sbin=-e 's,/sbin,${PREFIX}/sbin,g'

SUBST_STAGE.etc=post-configure
SUBST_FILES.etc=${WRKSRC}/config.mk
SUBST_SED.etc=-e 's,/etc/wlan,${PREFIX}/etc/wlan,g'

.include "../../mk/bsd.pkg.mk"
