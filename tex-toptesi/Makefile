# $NetBSD: Makefile,v 1.2 2014/08/04 16:39:57 leot1990 Exp $

DISTNAME=	toptesi
PKGNAME=	tex-${DISTNAME}-5.76
TEXLIVE_REV=	32081

MAINTAINER=	leot1990@users.sourceforge.net
COMMENT=	Bundle of files for typsetting theses

DEPENDS+=	tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
