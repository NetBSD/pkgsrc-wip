# $NetBSD: Makefile,v 1.5 2012/10/04 09:13:28 asau Exp $

DISTNAME=	Catalyst-Plugin-Cache-FileCache-0.5
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Cache-FileCache/
COMMENT=	Extends base class with a file cache

DEPENDS+=	p5-Cache-Cache>=0:../../devel/p5-Cache-Cache


PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Catalyst/Plugin/Cache/FileCache/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
