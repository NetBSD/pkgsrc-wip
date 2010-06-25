# $NetBSD: Makefile,v 1.1.1.1 2010/06/25 20:11:14 nthauvin Exp $

DISTNAME=	fancybox
PKGNAME=	tex-${DISTNAME}-1.3
TEXLIVE_REV=	15878

MAINTAINER=	nico@orgrim.net
COMMENT=	Variants of \fbox and other games with boxes

CONFLICTS+=	teTeX-texmf-[0-9]*
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
