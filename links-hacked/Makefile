# $NetBSD: Makefile,v 1.24 2012/11/13 20:26:27 othyro Exp $
#

DISTNAME=	links-hacked-${VER}
PKGREVISION=	6
CATEGORIES=	www
MASTER_SITES=	http://xray.sai.msu.ru/~karpov/links-hacked/downloads/
EXTRACT_SUFX=	.tgz
DISTFILES=	{DEFAULT_DISTFILES} links-fonts-new${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xray.sai.msu.ru/~karpov/links-hacked/
COMMENT=	Enhanced version of Links with tabs and more


GNU_CONFIGURE=		yes
USE_TOOLS+=		aclocal autoheader autoconf automake gmake

VER=			030709

CONFLICTS+=		links-[0-9]* links-gui-[0-9]* elinks-[0-9]*

LIBS+=			-lpng
CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--enable-javascript
CONFIGURE_ARGS+=	--enable-form-saving
CONFIGURE_ARGS+=	--enable-graphics

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	LINKS_HACKED_STATIC LINKS_HACKED_USES_DIRECTFB \
		LINKS_HACKED_USES_SVGALIB LINKS_HACKED_USES_LUA

.if defined(LINKS_HACKED_STATIC) && \
	!empty(LINKS_HACKED_STATIC:M[yY][eE][sS])
CONFIGURE_ARGS+=	--enable-static
.endif

.if defined(LINKS_HACKED_USES_DIRECTFB) && \
	!empty(LINKS_HACKED_USES_DIRECTFB:M[yY][eE][sS])
CONFIGURE_ARGS+=	--without-x
.include "../../wip/directfb/buildlink3.mk"
.endif

.if defined(LINKS_HACKED_USES_SVGALIB) && \
	!empty(LINKS_HACKED_USES_SVGALIB:M[yY][eE][sS])
CONFIGURE_ARGS+=	--without-x
.include "../../wip/svgalib/buildlink3.mk"
.endif

.if defined(LINKS_HACKED_USES_LUA) && \
	!empty(LINKS_HACKED_USES_LUA:M[yY][eE][sS])
.include "../../lang/lua/buildlink3.mk"
.endif

post-extract:
	${MV} ${WRKDIR}/font ${WRKSRC}

pre-configure:
	cd ${WRKSRC} && aclocal
	cd ${WRKSRC} && autoheader
	cd ${WRKSRC} && automake -a --foreign -i
	cd ${WRKSRC} && autoconf

.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
