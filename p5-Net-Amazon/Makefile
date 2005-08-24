# $NetBSD: Makefile,v 1.1.1.1 2005/08/24 21:18:37 kuli0020 Exp $

DISTNAME=	Net-Amazon-0.34
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Net-Amazon/
COMMENT=	Framework for accessing amazon.com via SOAP and XML/HTTP

DEPENDS+=	p5-libwww>=0.00:../../www/p5-libwww
DEPENDS+=	p5-URI>=0.00:../../www/p5-URI
DEPENDS+=	p5-XML-Simple>=0.00:../../textproc/p5-XML-Simple
DEPENDS+=	p5-Log-Log4perl>=0.00:../../devel/p5-Log-Log4perl
DEPENDS+=	{perl>=5.007003,p5-Time-HiRes>=0.00}:../../time/p5-Time-HiRes

PERL5_PACKLIST= auto/Net/Amazon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
