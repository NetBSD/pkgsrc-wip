# $NetBSD: Makefile,v 1.9 2005/08/11 10:08:22 absd Exp $
#

DISTNAME=	festival-gaim-0.64
PKGREVISION=	1
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

USE_TOOLS+=	gmake pkg-config
USE_LIBTOOL=	yes

MAKE_ENV+=	FESTIVAL_VOICES_PATH="${PREFIX}/share/festival/lib/voices"
MAKE_ENV+=	PLUGIN_GAIM_PATH="${PREFIX}/lib/gaim"

do-install:
	${INSTALL_DATA} ${WRKSRC}/festival.so ${PREFIX}/lib/gaim

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
