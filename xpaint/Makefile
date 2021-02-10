# $NetBSD: Makefile,v 1.80 2020/03/20 11:57:53 nia Exp $

DISTNAME=	xpaint-3.1.2
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sf-xpaint/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://sf-xpaint.sourceforge.net/
COMMENT=	Simple paint program
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_LIBTOOL=	yes
USE_TOOLS+=	bash gmake gunzip

REPLACE_BASH=	share/bin/imgmerge share/bin/xpaint_ocr

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif

SUBST_CLASSES+=		ln
SUBST_STAGE.ln=		pre-configure
SUBST_MESSAGE.ln=	Linking to libXaw3dXft include directory.
SUBST_FILES.ln=		Makefile.in
SUBST_SED.ln=		-e 's|/usr/include/X11/Xaw3dxft|${WRKDIR}/.buildlink/include/X11/Xaw3dxft|'

pre-install:
	for file in ${WRKSRC}/bitmaps/toolicons/*.xpm.gz ; do \
		${TOOLS_PLATFORM.gunzip} $$file ; \
	done

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/netpbm/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../wip/libXaw3dXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
