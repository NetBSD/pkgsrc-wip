# $NetBSD: Makefile,v 1.10 2008/03/21 15:48:54 hoka_adam Exp $
#

DISTNAME=		awesome-2.2-rc4
PKGNAME=		${DISTNAME:S/-rc/rc/}
CATEGORIES=		wm
MASTER_SITES=		http://awesome.naquadah.org/download/

MAINTAINER=		adam.hoka@gmail.com
HOMEPAGE=		http://awesome.naquadah.org/
COMMENT=		Tiling window manager based on dwm

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

USE_LANGUAGES=		c99
USE_TOOLS+=		pkg-config

EGDIR=			${PREFIX}/share/examples/awesome
MESSAGE_SUBST+=		EGDIR=${EGDIR}/awesomerc

BUILD_DEPENDS+= 	asciidoc>=8.2.5:../../textproc/asciidoc
BUILD_DEPENDS+= 	xmlto>=0.0.18:../../textproc/xmlto
BUILD_DEPENDS+= 	docbook-xsl>=1.73.2:../../textproc/docbook-xsl

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/awesomerc ${EGDIR}

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../wip/confuse/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
