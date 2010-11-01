# $NetBSD: Makefile,v 1.5 2010/11/01 00:08:22 thomasklausner Exp $

DISTNAME=		Frontier-RPC-0.06
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Frontier/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://datetime.perl.org/
COMMENT=		Perl module to handle client/server xmlrpc

DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_PACKLIST=		auto/Frontier/RPC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
