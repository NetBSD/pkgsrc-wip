# $NetBSD: Makefile,v 1.10 2012/11/13 20:09:31 othyro Exp $
#

DISTNAME=		groku-0.1
PKGREVISION=		7
CATEGORIES=		audio
MASTER_SITES=		http://digitalssg.net/debian/

MAINTAINER=		mwicks@kettering.edu
HOMEPAGE=		http://groku.digitalssg.net/
COMMENT=		Groku is a GTK for controlling your Roku Soundbridge (tm)

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES+=		c c++
CFLAGS+=		-g

pre-configure:
	${RM} -f ${WRKSRC}/install-sh ${WRKSRC}/depcomp ${WRKSRC}/missing ${WRKSRC}/INSTALL
	${CP} files/install-sh ${WRKSRC}/install-sh
	${CP} files/depcomp ${WRKSRC}/depcomp
	${CP} files/missing ${WRKSRC}/missing
	${CP} files/INSTALL ${WRKSRC}/INSTALL

pre-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/groku
	${LN} -s ${DESTDIR}${PREFIX}/share/pixmaps/groku.png ${DESTDIR}${PREFIX}/share/groku/groku-logo.png


.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
