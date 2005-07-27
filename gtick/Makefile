# $NetBSD: Makefile,v 1.6 2005/07/27 16:25:31 thomasklausner Exp $
#

DISTNAME=		gtick-0.2.13
CATEGORIES=		audio
MASTER_SITES=		http://www.antcom.de/gtick/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.antcom.de/gtick/
COMMENT=		GTK+ metronome

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
