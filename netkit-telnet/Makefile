# $NetBSD: Makefile,v 1.7 2007/01/03 14:38:15 shattered Exp $
#

DISTNAME=		netkit-telnet-0.17
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.uk.linux.org/pub/linux/Networking/netkit/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		ftp://ftp.uk.linux.org/pub/linux/Networking/netkit/
COMMENT=		The telnet and telnetd for Linux

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
ONLY_FOR_PLATFORM=	Linux-*-*

CONFIGURE_ARGS+=--prefix=${PREFIX:Q}

SUBST_CLASSES+=	warn
SUBST_STAGE.warn=pre-configure
SUBST_FILES.warn=configure
SUBST_SED.warn  =-e s,^WARNINGS=,\#WARNINGS=,g

.include "../../mk/bsd.pkg.mk"
