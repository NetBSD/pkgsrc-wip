# $NetBSD: Makefile,v 1.1.1.1 2007/04/09 13:16:54 yeled Exp $

DISTNAME=	Calendar-Simple-1.17
#PKGREVISION=	1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Calendar/}

MAINTAINER=	charlie@rubberduck.com
HOMEPAGE=	http://search.cpan.org/~davecross/Calendar-Simple-1.17/
COMMENT=	Perl extension to create simple calendars

#DEPENDS+=	p5-YAML>=0.39:../../textproc/p5-YAML

PERL5_PACKLIST= auto/Calendar/Simple/.packlist

PERL5_MODULE_TYPE= Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
