# $NetBSD: Makefile,v 1.2 2009/03/08 12:06:01 pettai Exp $
#

DISTNAME=		List-Compare-0.37
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		perl5 textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=List/}

MAINTAINER=		pettai@nordu.net
HOMEPAGE=		http://search.cpan.org/CPAN/authors/id/J/JK/JKEENAN/
COMMENT=		Compare elements of two or more lists

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/List/Compare/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
