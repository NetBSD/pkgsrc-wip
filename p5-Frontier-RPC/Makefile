# $NetBSD: Makefile,v 1.1.1.1 2004/01/31 13:30:12 poppnk Exp $

DISTNAME=		Frontier-RPC-0.06
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Frontier/}

MAINTAINER=		cube@cubidou.net
HOMEPAGE=		http://datetime.perl.org/
COMMENT=		Perl module to handle client/server xmlrpc

DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
USE_BUILDLINK2=	YES

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
