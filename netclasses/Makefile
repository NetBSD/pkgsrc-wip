# $NetBSD: Makefile,v 1.1.1.1 2008/06/10 10:04:28 hoka_adam Exp $
#

DISTNAME=	netclasses-1.06
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=netclasses/}

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://netclasses.sourceforge.net/
COMMENT=	Asynchronous networking library

USE_LANGUAGES=		objc
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/libexec/GNUstep
MAKE_FILE=		GNUmakefile

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
