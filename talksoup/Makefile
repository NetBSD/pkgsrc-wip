# $NetBSD: Makefile,v 1.2 2012/10/07 17:17:22 asau Exp $
#

DISTNAME=	TalkSoup-1.0alpha
PKGNAME=	talksoup-1.0alpha
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=talksoup/}

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://talksoup.sourceforge.net/
COMMENT=	IRC client for GNUstep and MacOSX


USE_LANGUAGES=		objc
NO_CONFIGURE=		yes
CONFIGURE_ARGS+=	--exec-prefix=${PREFIX}/libexec/GNUstep
MAKE_FILE=		GNUmakefile

# This package uses *old* install conventions.
MAKE_ENV+=	GNUSTEP_INSTALLATION_DIR=${PREFIX}/share/GNUstep/Local/

.include "../../devel/gnustep-make/buildlink3.mk"
.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../x11/gnustep-gui/buildlink3.mk"
.include "../../wip/netclasses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
