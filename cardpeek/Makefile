# $NetBSD: Makefile,v 1.1 2015/04/11 18:59:30 gschwarz Exp $

DISTNAME=	cardpeek-0.8.4
CATEGORIES=	misc
MASTER_SITES=	http://downloads.pannetrat.com/install/

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://pannetrat.com/Cardpeek/
COMMENT=	Cardpeek is a tool to read the contents of ISO7816 smart cards
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

GNU_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
.  if exists(/Developer/Applications/Xcode.app)
SUBST_CLASSES+=			xcode
SUBST_FILES.xcode=		configure
SUBST_MESSAGE.xcode=		adapting Xcode install path
SUBST_SED.xcode=		-e "s|/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform||g"
SUBST_SED.xcode+=		-e "s|head -1|tail -1|g"
SUBST_SED.xcode+=		-e "s|/Applications/Xcode.app/|/Developer/Applications/Xcode.app/|g"
SUBST_STAGE.xcode=		post-patch
BUILDLINK_PASSTHRU_DIRS+=	/Developer
.  endif
.else
BUILDLINK_PASSTHRU_DIRS+=	/Applications/Xcode.app
.endif

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../lang/lua52/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../security/pcsc-lite/buildlink3.mk"
.endif
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
