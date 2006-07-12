# $NetBSD: Makefile,v 1.3 2006/07/12 13:11:04 thomasklausner Exp $
#

DISTNAME=		kid3-0.6
PKGREVISION=		1
CATEGORIES=		kde audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kid3/}

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://kid3.sourceforge.net/
COMMENT=		KDE ID3 tagger

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

# Note: put app specific data files into kde dir
CONFIGURE_ARGS+= --datadir=${PREFIX}/share/kde

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/id3lib/buildlink3.mk"
.include "../../audio/libtunepimp0.4/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
