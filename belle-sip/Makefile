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
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

MAKE_JOBS_SAFE=	no

PKGCONFIG_OVERRIDE+=	belle-sip.pc.in

SUBST_CLASSES+=		jar
SUBST_SED.jar+=		-e 's,/opt/local/share/java,${PREFIX}/share/java/classes,'
SUBST_FILES.jar+=	configure
SUBST_STAGE.jar=	pre-configure
SUBST_MESSAGE.jar=	Fixing path to Java class.

.include "../../wip/antlr/buildlink3.mk"
.include "../../wip/antlr3-c/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
