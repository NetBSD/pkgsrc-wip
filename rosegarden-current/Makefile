# $NetBSD: Makefile,v 1.20 2012/10/07 14:53:43 asau Exp $
#

DISTNAME=	rosegarden-4-0.9.1
PKGREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rosegarden/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://www.rosegardenmusic.com/
COMMENT=	Development release of rosegarden


GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
USE_LANGUAGES= c c++
USE_LIBTOOL=	yes

post-install:
	${_PKG_SILENT}${_PKG_DEBUG}for fn in \
	RosegardenMidiRecord.mcopclass MidiArts.mcopclass MidiArts.mcoptype ; \
	do ${INSTALL_DATA} ${WRKSRC:Q}/sound/"$$fn" ${PREFIX:Q}/lib/mcop ; done

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../multimedia/kdemultimedia3/buildlink3.mk" # needed for artsmidi
.include "../../mk/bsd.pkg.mk"
