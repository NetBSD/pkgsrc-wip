# $NetBSD: Makefile,v 1.4 2006/10/30 22:45:31 shattered Exp $

DISTNAME=		Frontier-RPC-0.06
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Frontier/}

MAINTAINER=		cube@cubidou.net
HOMEPAGE=		http://datetime.perl.org/
COMMENT=		Perl module to handle client/server xmlrpc

DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_PACKLIST=		auto/Frontier/RPC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
