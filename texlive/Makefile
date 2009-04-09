# $NetBSD: Makefile,v 1.3 2009/04/09 01:07:01 jsonn Exp $
#

PKGNAME=	texlive-${TEXLIVE_VERSION}
DISTNAME=	# empty
CATEGORIES=	print meta-pkgs

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	TeXLive meta-pkg, using Edd Barret's OpenBSD repository

META_PACKAGE=	# empty

CONFLICTS+=	teTeX-[0-9]*
CONFLICTS+=	teTeX2-[0-9]*
CONFLICTS+=	teTeX3-[0-9]*

DEPENDS+=	texlive-bin-[0-9]*:../../wip/texlive-bin

.include "Makefile.common"
.include "options.mk"

#.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
