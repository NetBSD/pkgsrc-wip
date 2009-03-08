# $NetBSD: Makefile,v 1.2 2009/03/08 12:01:58 pettai Exp $
#

PKGNAME=	p5-Authen-${DISTNAME}
DISTNAME=	TacacsPlus-0.16
CATEGORIES=	perl5 security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://search.cpan.org/~mshoyher/TacacsPlus-0.16/TacacsPlus.pm
COMMENT=	Perl extension for authentication using tacacs+ server

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Authen/TacacsPlus/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
