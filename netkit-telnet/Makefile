# $NetBSD: Makefile,v 1.2 2005/04/11 21:14:30 tvierling Exp $
#

DISTNAME=		netkit-telnet-0.17
CATEGORIES=		wip net
MASTER_SITES=		ftp://ftp.uk.linux.org/pub/linux/Networking/netkit/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		ftp://ftp.uk.linux.org/pub/linux/Networking/netkit/
COMMENT=		The telnet and telnetd for Linux

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_GNU_TOOLS+=		make

CONFIGURE_ARGS+=--prefix=${PREFIX}

SUBST_CLASSES+=	warn
SUBST_STAGE.warn=pre-configure
SUBST_FILES.warn=configure
SUBST_SED.warn  =-e s,^WARNINGS=,\#WARNINGS=,g

.include "../../mk/bsd.pkg.mk"
