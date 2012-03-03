# $NetBSD: Makefile,v 1.1.1.1 2012/03/03 11:09:53 makoto Exp $

DISTNAME=	ja-ptex-2.1
CATEGORIES=	meta-pkgs print

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Meta-package for pTeX et al, supports Japanese language
LICENSE=	2-clause-bsd

META_PACKAGE=	yes

DEPENDS+=	teTeX-texmf>=3.0:../../print/teTeX3-texmf

# Following will depend tex-ptex -> installs bin/platex
DEPENDS+=	tex-jsclasses>=2010:../../print/tex-jsclasses
DEPENDS+=	dvipdfmx>=20100328nb1:../../print/dvipdfmx

# Why this makeindexk dependency necessary ? (Is it right ?)
DEPENDS+=	makeindexk>=2.15:../../textproc/makeindexk
DEPENDS+=	pdvipsk>=5.98pl1.7b:../../print/pdvipsk

.include "../../mk/bsd.pkg.mk"
