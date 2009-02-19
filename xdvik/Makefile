# $NetBSD: Makefile,v 1.1.1.1 2009/02/19 05:06:00 minskim Exp $

DISTNAME=	xdvik-22.84.14
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xdvi/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://xdvi.sourceforge.net/
COMMENT=	Previewer for DVI files

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/xdvik

CONFIGURE_ARGS+=	--with-system-kpathsea --with-system-t1lib \
			--with-xdvi-x-toolkit=xaw

MAKE_FLAGS+=	LIBTOOL=${LIBTOOL:Q} \
		kpathsea_parent=${BUILDLINK_PREFIX.kpathsea}/include

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf

.include "../../converters/libiconv/buildlink3.mk"
.include "../../fonts/t1lib/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
