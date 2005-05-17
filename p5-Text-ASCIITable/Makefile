# $NetBSD: Makefile,v 1.1.1.1 2005/05/17 10:48:47 jgoamakf Exp $

DISTNAME=		Text-ASCIITable-0.15
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tat
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/Text-ASCIITable/
COMMENT=		Create a nice formatted table using ASCII characters

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/ASCIITable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
