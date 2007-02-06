# $NetBSD: Makefile,v 1.1.1.1 2007/02/06 09:36:15 netcap Exp $

DISTNAME=	Config-Any-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://search.cpan.org/dist/Config-Any/
COMMENT=	Perl extension for handling config files

BUILD_DEPENDS+= p5-Module-Build>=0.47}:../../devel/p5-Module-Build

PERL5_REQD+=	5.8.0

PERL5_PACKLIST=	auto/Config/Any/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
