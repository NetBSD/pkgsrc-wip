# $NetBSD: Makefile,v 1.2 2005/07/25 13:13:35 ghen Exp $
#

DISTNAME=	teTeX-3.0
CATEGORIES=	print meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	geert.hendrickx@ua.ac.be
HOMEPAGE=	http://www.tug.org/tetex/
COMMENT=	Thomas Esser's TeX distribution for UNIX compatible systems, version 3

DEPENDS+=	teTeX-texmf>=3:../../print/teTeX3-texmf
DEPENDS+=	teTeX-bin>=3:../../print/teTeX3-bin

CONFLICTS+=	teTeX-[1-2]*

EXTRACT_ONLY=   # empty
NO_CHECKSUM=    yes
NO_CONFIGURE=   yes
NO_BUILD=       yes

do-install:	# do nothing

.include "../../mk/bsd.pkg.mk"
