# $NetBSD: Makefile,v 1.1.1.1 2005/01/09 12:42:52 zul_ Exp $
#

DISTNAME=		eboard-0.9.5
CATEGORIES=		wip games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=eboard/}

MAINTAINER=	 	zul@netbsd-fr.org
HOMEPAGE=		http://eboard.sourceforge.net/
COMMENT=		Chess Inteface for Unix chess engines

USE_BUILDLINK3=		yes
BUILD_DEPENDS+=		perl-5.[0-9\.]*:../../lang/perl58
USE_GNU_TOOLS+=		make

.include "../../mk/ossaudio.buildlink3.mk"

do-configure:
	 cd ${WRKSRC} && ${PREFIX}/bin/perl ${WRKSRC}/configure \
		--prefix=${PREFIX}  --libossaudio=${LIBOSSAUDIO} 

.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
