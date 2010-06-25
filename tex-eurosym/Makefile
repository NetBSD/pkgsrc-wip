# $NetBSD: Makefile,v 1.1.1.1 2010/06/25 20:00:34 nthauvin Exp $

DISTNAME=	eurosym
PKGNAME=	tex-${DISTNAME}-1.4
TEXLIVE_REV=	17265

MAINTAINER=	nico@orgrim.net
COMMENT=	MetaFont and macros for Euro sign

CONFLICTS+=	teTeX-texmf-[0-9]*
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
