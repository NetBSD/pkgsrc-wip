# $NetBSD: Makefile,v 1.4 2010/11/13 02:43:01 minskim Exp $
#

PKGNAME=	texlive-${TEXLIVE_VERSION}
DISTNAME=	# empty
CATEGORIES=	print meta-pkgs

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tug.org/texlive/
COMMENT=	TeXLive meta-pkg, using Edd Barret's OpenBSD repository

META_PACKAGE=	# empty

DEPENDS+=	texlive-bin-[0-9]*:../../wip/texlive-bin

.include "Makefile.common"
.include "options.mk"
.include "../../mk/bsd.pkg.mk"
