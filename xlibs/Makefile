# $NetBSD: Makefile,v 1.1.1.1 2004/02/10 18:48:12 jeremy-c-reed Exp $

DISTNAME=		xlibs-1.0
CATEGORIES=		x11 meta
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://xlibs.freedesktop.org/
COMMENT=		Meta-package for X Libraries and Protocol Headers Project

EXTRACT_ONLY=	# empty
USE_BUILDLINK3=	yes
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

# This purposely omits xpm, Xrandr, Xrender, and Xft, because
# other packages already include these as needed.

.include "../../wip/libXmu/buildlink3.mk"
.include "../../wip/libXi/buildlink3.mk"
.include "../../wip/libXv/buildlink3.mk"
.include "../../wip/libXfont/buildlink3.mk"
.include "../../wip/libXres/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
