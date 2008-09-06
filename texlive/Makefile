# $NetBSD: Makefile,v 1.2 2008/09/06 20:52:57 thomasklausner Exp $
#

PKGNAME=	texlive-${TEXLIVE_VERSION}
DISTNAME=	# empty
CATEGORIES=	print meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	TeXLive meta-pkg, using Edd Barret's OpenBSD repository

CONFLICTS+=	teTeX-[0-9]*
CONFLICTS+=	teTeX2-[0-9]*
CONFLICTS+=	teTeX3-[0-9]*

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_BUILD=	yes
PLIST_SRC=	# empty

do-install:	# do nothing

DEPENDS+=	texlive-bin-[0-9]*:../../wip/texlive-bin

.include "Makefile.common"
.include "options.mk"

#.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
