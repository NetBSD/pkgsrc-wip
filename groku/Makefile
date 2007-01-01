# $NetBSD: Makefile,v 1.2 2007/01/01 01:19:41 mwicks Exp $
#

DISTNAME=		groku-0.1
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

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../x11/Xfixes/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
