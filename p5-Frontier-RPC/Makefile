# $NetBSD: Makefile,v 1.7 2012/10/04 10:45:28 asau Exp $

DISTNAME=		Frontier-RPC-0.07b4
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Frontier/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Frontier-RPC
COMMENT=		Perl module to handle client/server xmlrpc
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-XML-Parser>=2.19:../../textproc/p5-XML-Parser
DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_PACKLIST=		auto/Frontier/RPC/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
