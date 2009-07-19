# $NetBSD: Makefile,v 1.4 2009/07/19 17:42:34 pettai Exp $
#

DISTNAME=	Authen-TacacsPlus-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://search.cpan.org/~mikem/Authen-TacacsPlus/TacacsPlus.pm
COMMENT=	Perl extension for authentication using tacacs+ server

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Authen/TacacsPlus/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
