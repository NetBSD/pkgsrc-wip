# $NetBSD: Makefile,v 1.5 2004/01/25 02:23:46 grantbeattie Exp $
#

DISTNAME=	links-hacked-${VER}
CATEGORIES=	www
MASTER_SITES=	http://xray.sai.msu.ru/~karpov/links-hacked/downloads/
EXTRACT_SUFX=	.tgz
DISTFILES+=     ${DISTNAME}${EXTRACT_SUFX} links-fonts-new${EXTRACT_SUFX}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://xray.sai.msu.ru/~karpov/links-hacked/
COMMENT=        Enhanced version of Links with tabs and more

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes

VER=			030709

CONFLICTS+=	links-[0-9]* links-gui-[0-9]* elinks-[0-9]*

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
.include "../../wip/directfb/buildlink2.mk"
.endif

.if defined(LINKS_HACKED_USES_SVGALIB) && \
	!empty(LINKS_HACKED_USES_SVGALIB:M[yY][eE][sS])
CONFIGURE_ARGS+=        --without-x
.include "../../wip/svgalib/buildlink2.mk"
.endif

.if defined(LINKS_HACKED_USES_LUA) && \
	!empty(LINKS_HACKED_USES_LUA:M[yY][eE][sS])
.include "../../lang/lua/buildlink2.mk"
.endif

post-extract:
	@${MV} ${WRKDIR}/font ${WRKSRC}

pre-configure:
	@cd ${WRKSRC};                                           \
	${ACLOCAL};                                             \
	${AUTOHEADER};                                          \
	${AUTOMAKE} -a --foreign -i;                            \
	${AUTOCONF}

.include "../../mk/automake.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../databases/gdbm/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../archivers/bzip2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
