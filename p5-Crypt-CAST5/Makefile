# $NetBSD: Makefile,v 1.2 2008/02/12 21:23:48 shattered Exp $

DISTNAME=	Crypt-CAST5-0.05
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=	shattered@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/dist/Crypt-CAST5/
COMMENT=	Perl5 CAST5 block cipher implementation

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CRYPTO=		YES
PERL5_PACKLIST=	auto/Crypt/CAST5/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
