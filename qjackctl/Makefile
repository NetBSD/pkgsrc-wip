# $NetBSD: Makefile,v 1.2 2006/06/12 16:44:02 thomasklausner Exp $
#

DISTNAME=		qjackctl-0.2.19a
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=qjackctl/}

MAINTAINER=		chriswareham@chriswareham.demon.co.uk
HOMEPAGE=		http://qjackctl.sourceforge.net/
COMMENT=		Qt GUI interface to control the JACK sound server daemon

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		autoconf pkg-config
GNU_CONFIGURE=		yes

.include "../../audio/jack/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
# XXX Please verify whether qt3-tools is really needed at run-time.
# If it is, then remove this comment.  If it is not, then remove
# this comment and the line below, and bump PKGREVISION.
BUILDLINK_DEPMETHOD.qt3-tools=	full
.include "../../mk/bsd.pkg.mk"
