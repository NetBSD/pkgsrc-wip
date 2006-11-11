# $NetBSD: Makefile,v 1.1.1.1 2006/11/11 17:36:32 kh-p Exp $

DISTNAME=		xmoto-0.2.2-src
PKGNAME=		xmoto-0.2.2
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xmoto/}

MAINTAINER=		kh.p@no-log.org
HOMEPAGE=		http://xmoto.sourceforge.net/
COMMENT=		2D motocross plateform game

WRKSRC=                 ${WRKDIR}/${PKGNAME_NOREV}

USE_X11BASE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt autoconf automake gmake pkg-config
USE_LANGUAGES+=		c c++

GCC_REQD+=		3.4

GNU_CONFIGURE=          yes

#Not needed
#CONFIGURE_ENV+=         XGETTEXT=${TOOLS_PATH.xgettext:Q}

BROKEN_GETTEXT_DETECTION=     yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CONFIGURE_ENV+=         INTLLIBS="-lintl"
.endif

# man(6) aren't installed.
#do-install:
#	${INSTALL_MAN} ${WRKSRC}/xmoto.6.gz ${PREFIX}/man/man6
#	${INSTALL_MAN} ${WRKSRC}/xmoto-edit.6.gz ${PREFIX}/man/man6

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../wip/libdrm/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../audio/libmikmod/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../wip/ode/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../lang/gcc34/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
