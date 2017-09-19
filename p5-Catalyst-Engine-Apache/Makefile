# $NetBSD: Makefile,v 1.7 2012/10/04 09:13:27 asau Exp $

DISTNAME=	Catalyst-Engine-Apache-1.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/F/FL/FLORA/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Engine-Apache/
COMMENT=	Catalyst Apache Engines

BUILD_DEPENDS+=	p5-Catalyst-Runtime>=5.50:../../www/p5-Catalyst-Runtime
BUILD_DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

PERL5_PACKLIST= auto/Catalyst/Engine/Apache/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
