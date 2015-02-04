# $NetBSD: Makefile,v 1.3 2015/02/04 23:49:09 leot1990 Exp $

DISTNAME=	toptesi
PKGNAME=	tex-${DISTNAME}-5.86f
TEXLIVE_REV=	35916

MAINTAINER=	leot1990@users.sourceforge.net
COMMENT=	Bundle of files for typsetting theses

DEPENDS+=	tex-babel-[0-9]*:../../print/tex-babel
DEPENDS+=	tex-etoolbox-[0-9]*:../../devel/tex-etoolbox
DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics
DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
DEPENDS+=	tex-ifxetex-[0-9]*:../../print/tex-ifxetex

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
