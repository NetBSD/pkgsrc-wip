# $NetBSD: Makefile,v 1.5 2007/01/13 22:18:04 shattered Exp $
#

DISTNAME=		help2man-1.33.1
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_GNU:=help2man/}

MAINTAINER=		arved@arved.at
HOMEPAGE=		http://www.gnu.org/software/help2man/
COMMENT=		Generate simple manual pages from program output

DEPENDS+=		p5-gettext>=1.01:../../devel/p5-gettext

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl

INFO_FILES=		# PLIST

.include "../../mk/bsd.pkg.mk"
