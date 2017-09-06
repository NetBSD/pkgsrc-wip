# $NetBSD: Makefile,v 1.1.1.2 2012/03/18 13:25:53 makoto Exp $
# $Id: Makefile,v 1.1.1.2 2012/03/18 13:25:53 makoto Exp $

DISTNAME=	ja-ptex-2.1
CATEGORIES=	meta-pkgs print

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Meta-package for pTeX et al, supports Japanese language
LICENSE=	2-clause-bsd

META_PACKAGE=	yes

#DEPENDS+=	teTeX-texmf>=3.0:../../print/teTeX3-texmf
DEPENDS+=	tex-jsclasses>=2010:../../print/tex-jsclasses
DEPENDS+=	tex-here>=2010:../../print/tex-here
DEPENDS+=	dvipdfmx>=20100328nb1:../../print/dvipdfmx
DEPENDS+=	mendexk>=2.6:../../textproc/mendexk
DEPENDS+=	pdvipsk>=5.98pl1.7b:../../print/pdvipsk
DEPENDS+=	xpdf>=3:../../print/xpdf
DEPENDS+=	xpdf-japanese-[0-9]*:../../print/xpdf-japanese

.include "../../mk/bsd.pkg.mk"
