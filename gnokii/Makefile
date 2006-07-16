# $NetBSD: Makefile,v 1.2 2006/07/16 12:31:12 shattered Exp $
#

DISTNAME=		gnokii-0.6.13
CATEGORIES=		comms
MASTER_SITES=		http://www.gnokii.org/download/gnokii/ \
			http://www.gnokii.org/download/gnokii/0.6.x/ \
			http://freesoftware.fsf.org/download/gnokii/ \
			ftp://ftp.gnokii.org/pub/gnokii/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://www.gnokii.org/
COMMENT=		Open source tools for your mobile phone

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/common/gnokii.pc.in
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes
USE_X11=		yes
USE_TOOLS+=		gmake

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
