# $NetBSD: Makefile,v 1.1 2005/05/31 12:20:02 ianzag Exp $
#

DISTNAME=		SDL-doc-1.0
CATEGORIES=		devel
MASTER_SITES=	# empty
DISTFILES=		# empty

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://www.libsdl.org/docs.php
COMMENT=		Simple DirectMedia Layer documentation

# Note: fix wip to actuall location.
DEPENDS+=		SDL-doc-html-1.0:../../wip/SDL-doc-html
DEPENDS+=		SDL-doc-ps-1.0:../../wip/SDL-doc-ps

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=		YES
NO_MTREE=		YES

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
