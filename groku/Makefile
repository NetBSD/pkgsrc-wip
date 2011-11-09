# $NetBSD: Makefile,v 1.8 2011/11/09 11:21:18 noud4 Exp $
#

DISTNAME=		groku-0.1
PKGREVISION=		6
CATEGORIES=		audio
MASTER_SITES=		http://digitalssg.net/debian/

MAINTAINER=		mwicks@kettering.edu
HOMEPAGE=		http://groku.digitalssg.net/
COMMENT=		Groku is a GTK for controlling your Roku Soundbridge (tm)

PKG_DESTDIR_SUPPORT=	user-destdir

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

.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
