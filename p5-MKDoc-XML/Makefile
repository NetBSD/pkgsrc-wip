# $NetBSD: Makefile,v 1.1.1.1 2005/10/04 08:14:13 jgoamakf Exp $

DISTNAME=		MKDoc-XML-0.75
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5mkx
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BP/BPOSTLE/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/dist/MKDoc-XML/
COMMENT=		Suite of low level XML processing modules

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/MKDoc/XML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
