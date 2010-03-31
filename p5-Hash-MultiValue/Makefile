# $NetBSD: Makefile,v 1.1.1.1 2010/03/31 14:23:05 uccwen Exp $
#

DISTNAME=	Hash-MultiValue-0.08
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Hash/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://search.cpan.org/~miyagawa/Hash-MultiValue/
COMMENT=	Perl extension to store multiple values per key
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Hash/MultiValue/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
