# $NetBSD: Makefile,v 1.1.1.1 2005/12/10 20:17:31 shattered Exp $
#

DISTNAME=		kid3-0.6
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
.include "../../audio/tunepimp/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
