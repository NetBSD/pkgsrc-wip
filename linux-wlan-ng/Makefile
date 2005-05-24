# $NetBSD: Makefile,v 1.4 2005/05/24 10:30:50 rillig Exp $
#

DISTNAME=		linux-wlan-ng-0.2.1pre23
CATEGORIES=		wip net linux
MASTER_SITES=		ftp://ftp.linux-wlan.org/pub/linux-wlan-ng/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.linux-wlan.com/
COMMENT=		Linux utilities for wireless prism2 cards

USE_TOOLS+=		gmake
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-d

ONLY_FOR_PLATFORM=	Linux-*-*

SUBST_CLASSES+=		wlan
SUBST_STAGE.wlan=	post-configure
SUBST_FILES.wlan=	config.mk
SUBST_SED.wlan+=	-e 's,/sbin,${PREFIX}/sbin,g'
SUBST_SED.wlan+=	-e 's,/etc/wlan,${PREFIX}/etc/wlan,g'

.include "../../mk/bsd.pkg.mk"
