# $NetBSD$

DISTNAME=	ede-2.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ede/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://edeproject.org/
COMMENT=	Equinox Desktop Environment
LICENSE=	gnu-gpl-v2 # or later

USE_LANGUAGES=		c c++
USE_CC_FEATURES+=	c99
USE_CXX_FEATURES+=	c++11
USE_PKGLOCALEDIR=	yes
USE_FEATURES+=		snprintf vsnprintf
USE_TOOLS+=		gmake msgfmt pkg-config
GNU_CONFIGURE=		yes

TOOL_DEPENDS+=		jam-[0-9]*:../../devel/jam

BUILDLINK_TRANSFORM.NetBSD+=	rm:-ldl

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} jam -q

do-install:
	cd ${WRKSRC} && env ${INSTALL_ENV} ${MAKE_ENV} jam install

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/fam.buildlink3.mk"
.include "../../wip/edelib/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
