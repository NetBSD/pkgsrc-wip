# $NetBSD: Makefile,v 1.4 2012/11/25 23:32:18 othyro Exp $
#

DISTNAME=		gnormalize-0.35
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gnormalize/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gnormalize.sourceforge.net/
COMMENT=		Gtk2::Perl frontend for audio conversion

DEPENDS+=	p5-CDDB_get>=2.20:../../audio/p5-CDDB_get
DEPENDS+=	p5-gtk2>=1:../../x11/p5-gtk2
DEPENDS+=	p5-MP3-Info>=1:../../audio/p5-MP3-Info

USE_TOOLS+=	perl
NO_BUILD=	YES
REPLACE_PERL=	${WRKSRC}/gnormalize

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gnormalize ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
