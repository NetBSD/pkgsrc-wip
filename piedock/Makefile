# $NetBSD: Makefile,v 1.2 2012/10/29 17:15:48 othyro Exp $
#

DISTNAME=	piedock-1.6.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.markusfisch.de/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.markusfisch.de/
COMMENT=	Task bar and application menu launcher in shape of a pie menu
LICENSE=	mit

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config

EGDIR=			share/examples/piedock
INSTALLATION_DIRS+=	${EGDIR}

SUBST_CLASSES+=		share
SUBST_MESSAGE.share=	Fixing share path.
SUBST_STAGE.share=	pre-install
SUBST_FILES.share=	res/piedockrc.sample
SUBST_SED.share=	-e "s|/usr/share|${PREFIX}/share|g"

.include "options.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/res/piedockrc.sample ${DESTDIR}${PREFIX}/${EGDIR}/

.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
