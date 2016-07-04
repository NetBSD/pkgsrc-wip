# $NetBSD$

DISTNAME=	belle-sip-1.4.2
CATEGORIES=	audio
MASTER_SITES=	http://download.savannah.gnu.org/releases/linphone/belle-sip/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.linphone.org/technical-corner/belle-sip/overview
COMMENT=	C object oriented SIP Stack
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	belle-sip.pc.in

.include "../../wip/antlr3-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
