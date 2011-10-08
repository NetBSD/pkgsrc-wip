# $NetBSD: Makefile,v 1.1.1.1 2011/10/08 00:10:16 bubuchka Exp $

DISTNAME=	texlive-20100720-source
PKGNAME=	xdvipdfmx-${DISTNAME:C/texlive-([0-9]+)-source/\1/g}
CATEGORIES=	print converters
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://scripts.sil.org/XeTeX
COMMENT=	Extended DVI to PDF converter, mainly used by XeTeX

LICENSE=	gnu-gpl-v2

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/xdvipdfmx

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
#XXX do we really need this: USE_TOOLS+=	gs:run ps2pdf:run
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/xdvipdfmx

CONFIGURE_ARGS+=	--with-system-kpathsea \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib
CONFIGURE_ARGS+=	--with-system-zlib \
		--with-zlib-includes=${BUILDLINK_PREFIX.zlib}/include \
		--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--with-system-libpng \
		--with-libpng-includes=${BUILDLINK_PREFIX.png}/include \
		--with-libpng-libdir=${BUILDLINK_PREFIX.png}/lib
CONFIGURE_ARGS+=	--with-system-freetype2 \
		--with-fontconfig-includes=${BUILDLINK_PREFIX.fontconfig}/include \
		--with-fontconfig-libdir=${BUILDLINK_PREFIX.fontconfig}/lib
CONFIGURE_ARGS+=	--with-paper=${BUILDLINK_PREFIX.libpaper}

# At the moment avoid Max OS X specific and use pkgsrc as fonts source
CONFIGURE_ENV+=	kpse_cv_have_ApplicationServices=no

.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"
.include "../../print/libpaper/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
