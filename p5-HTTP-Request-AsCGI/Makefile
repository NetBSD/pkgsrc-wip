# $NetBSD: Makefile,v 1.2 2006/02/02 21:22:43 absd Exp $

DISTNAME=	HTTP-Request-AsCGI-0.5
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/C/CH/CHANSEN/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Request-AsCGI/
COMMENT=	Setup a CGI enviroment from a HTTP::Request
PERL5_REQD+=    5.8.0

BUILD_DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
BUILD_DEPENDS+=	p5-libwww>=0:../../www/p5-libwww
BUILD_DEPENDS+=	p5-Test-Simple>=0:../../devel/p5-Test-Simple

PERL5_PACKLIST= auto/HTTP/Request/AsCGI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
