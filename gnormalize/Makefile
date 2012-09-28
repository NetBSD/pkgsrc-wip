# $NetBSD: Makefile,v 1.3 2012/09/29 00:26:13 asau Exp $
#

DISTNAME=		gnormalize-0.35
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnormalize/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://gnormalize.sourceforge.net/
COMMENT=		Gtk2::Perl frontend for audio conversion

DEPENDS+=	p5-CDDB_get>=2.20:../../audio/p5-CDDB_get
DEPENDS+=	p5-gtk2>=1:../../x11/p5-gtk2
DEPENDS+=	p5-MP3-Info>=1:../../audio/p5-MP3-Info

USE_TOOLS+=	perl
NO_BUILD=	YES
REPLACE_PERL=${WRKSRC}/gnormalize

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gnormalize ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
