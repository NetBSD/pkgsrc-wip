# $NetBSD: Makefile,v 1.2 2003/08/29 11:49:28 thomasklausner Exp $
#

DISTNAME=	festival-gaim-0.64
CATEGORIES=	audio chat
MASTER_SITES=	http://primates.ximian.com/~sandino/festival/SOURCES/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/softwaremap/projects/festival-gaim/
COMMENT=	Synthesizes incoming messages using voice

DEPENDS+=	festival>=1.4.1nb1:../../audio/festival
DEPENDS+=	festlex-cmu>=1.4.0:../../audio/festlex-cmu
DEPENDS+=	festlex-poslex>=1.4.0:../../audio/festlex-poslex
DEPENDS+=	festvox-el11>=1.4.0:../../audio/festvox-el11
DEPENDS+=	gaim>=0.64:../../chat/gaim

USE_GMAKE=	yes
USE_LIBTOOL=	yes

MAKE_ENV+=	FESTIVAL_VOICES_PATH="${PREFIX}/share/festival/lib/voices"
MAKE_ENV+=	PLUGIN_GAIM_PATH="${PREFIX}/lib/gaim"

do-install:
	${INSTALL_DATA} ${WRKSRC}/festival.so ${PREFIX}/lib/gaim

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
