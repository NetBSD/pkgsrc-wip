# $NetBSD: Makefile,v 1.3 2004/01/18 15:11:09 mpasternak Exp $
#

DISTNAME=		gtick-0.2.13
CATEGORIES=		audio
MASTER_SITES=		http://www.antcom.de/gtick/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.antcom.de/gtick/
COMMENT=		GTK+ metronome

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

.include "../../x11/gtk2/buildlink2.mk"
.include "../../devel/libgetopt/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
