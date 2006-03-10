# $NetBSD: Makefile,v 1.1.1.1 2006/03/10 17:54:50 kuli0020 Exp $

DISTNAME=	Class-Data-Accessor-0.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Class-Data-Accessor/
COMMENT=	Inheritable and overridable class and instance data accessors

PERL5_MODULE_TYPE=	Module::Build

PERL5_REQD+=	5.8.0

PERL5_PACKLIST=	auto/Class/Data/Accessor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
