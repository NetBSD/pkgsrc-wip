# $NetBSD: Makefile,v 1.1.1.1 2003/11/28 09:50:25 jeremy-c-reed Exp $
#

DISTNAME=		passepartout-0.3
CATEGORIES=		print
MASTER_SITES=		http://www.stacken.kth.se/project/pptout/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.stacken.kth.se/project/pptout/
COMMENT=		Desktop publishing for X

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../mk/ghostscript.mk"
.include "../../x11/gtkmm/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"
.include "../../wip/libxml++/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
