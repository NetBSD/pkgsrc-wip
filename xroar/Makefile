# $NetBSD: Makefile,v 1.17 2024/04/06 08:05:20 wiz Exp $

DISTNAME=	xroar-1.6.6
CATEGORIES=	emulators
MASTER_SITES=	https://www.6809.org.uk/xroar/dl/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.6809.org.uk/xroar/
COMMENT=	MC6809-based Dragon and Colour Computer (CoCo) emulator
LICENSE=	gnu-gpl-v3

USE_TOOLS=	gmake pkg-config:run
GNU_CONFIGURE=	yes
INFO_FILES=	yes

# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=	c99

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--without-x
.else
CONFIGURE_ARGS+=	--with-gtk3
.endif

.include "options.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
