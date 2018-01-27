# $NetBSD: Makefile,v 1.4 2014/11/14 08:07:41 noud4 Exp $

DISTNAME=	Catalyst-Plugin-Compress-Zlib-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/MS/MSTROUT/}

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://search.cpan.org/~mstrout/Catalyst-Plugin-Compress-Zlib/
COMMENT=	Gzip compress response if client supports it.

DEPENDS+=	p5-IO-Compress>=0:../../devel/p5-IO-Compress
DEPENDS+=	p5-ExtUtils-MakeMaker>=0:../../devel/p5-ExtUtils-MakeMaker
DEPENDS+=	p5-Catalyst-Runtime>=2.99:../../www/p5-Catalyst-Runtime


PERL5_PACKLIST=	auto/Catalyst/Plugin/Compress/Zlib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
