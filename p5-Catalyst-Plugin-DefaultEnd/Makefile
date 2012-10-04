# $NetBSD: Makefile,v 1.4 2012/10/04 09:13:28 asau Exp $

DISTNAME=	Catalyst-Plugin-DefaultEnd-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/MR/MRAMBERG/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-DefaultEnd/
COMMENT=	Sensible default end action
PERL5_REQD+=	5.8.1

DEPENDS+=	p5-Catalyst-Runtime>=5.20:../../www/p5-Catalyst-Runtime

PKG_DESTDIR_SUPPORT=	none

PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=	auto/Catalyst/Plugin/DefaultEnd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
