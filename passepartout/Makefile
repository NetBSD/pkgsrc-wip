# $NetBSD: Makefile,v 1.2 2004/05/02 22:41:29 blef Exp $
#

DISTNAME=		passepartout-0.3
CATEGORIES=		print
MASTER_SITES=		http://www.stacken.kth.se/project/pptout/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.stacken.kth.se/project/pptout/
COMMENT=		Desktop publishing for X

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

BUILDLINK_TRANSFORM+=	S:-Wold-style-casts:

.include "../../mk/ghostscript.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../wip/libxml++/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
