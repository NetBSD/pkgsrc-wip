# $NetBSD: Makefile,v 1.1 2015/08/10 21:07:15 yhardy Exp $

DISTNAME=	envlab
PKGNAME=	tex-${DISTNAME}-${TEXLIVE_REV}
TEXLIVE_REV=	15878

TEXLIVE_USE_CTAN=	YES

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Addresses on envelopes or mailing labels

DEPENDS+=	tex-graphics-[0-9]*:../../print/tex-graphics

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
