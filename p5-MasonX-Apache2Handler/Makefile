# $NetBSD: Makefile,v 1.6 2010/06/01 05:35:30 obache Exp $
# p5-HTML-MasonX-Apache2Handler
# http://search.cpan.org/CPAN/authors/id/B/BE/BEAU/MasonX-Apache2Handler-0.05.tar.gz
# modules/by-category/15_World_Wide_Web_HTML_HTTP_CGI/MasonX

DISTNAME=		MasonX-Apache2Handler-0.05
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ma2
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=MasonX/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~beau/MasonX-Apache2Handler-0.05/
COMMENT=		Perl-based Apache handler for Apache2 with Mason

DEPENDS+=		p5-libapreq2>=2.4:../../www/p5-libapreq2
DEPENDS+=		p5-HTML-Mason>=1.26:../../www/p5-HTML-Mason
DEPENDS+=		${APACHE_PKG_PREFIX}-perl>=1.99.17:../../www/ap2-perl

BUILDLINK_API_DEPENDS.perl=	perl>=5.8.4

PERL5_PACKLIST=		auto/MasonX/Apache2Handler/.packlist

PKG_APACHE_ACCEPTED=	apache2 apache22

.include "../../mk/apache.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
