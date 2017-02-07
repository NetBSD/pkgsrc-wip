# $NetBSD: Makefile,v 1.9 2014/10/09 13:45:24 thomasklausner Exp $

DISTNAME=		MasonX-Apache2Handler-0.05
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MasonX/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~beau/MasonX-Apache2Handler-0.05/
COMMENT=		Perl-based Apache handler for Apache2 with Mason

DEPENDS+=		p5-libapreq2>=2.4:../../www/p5-libapreq2
DEPENDS+=		p5-HTML-Mason>=1.26:../../www/p5-HTML-Mason
DEPENDS+=		${APACHE_PKG_PREFIX}-perl>=1.99.17:../../www/ap2-perl

PERL5_PACKLIST=		auto/MasonX/Apache2Handler/.packlist

.include "../../mk/apache.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
