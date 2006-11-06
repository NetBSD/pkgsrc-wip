# $NetBSD: Makefile,v 1.1.1.1 2006/11/06 20:38:10 uhabel Exp $

DISTNAME=	Geo-Distance-0.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 geography
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/B/BL/BLUEFEET/}
MAINTAINER=	uli@habel.name
HOMEPAGE=	http://search.cpan.org/dist/Geo-Distance/
COMMENT=	Geo::Distance implementation for Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Geo/Distance/.packlist
BUILDLINK_API_DEPENDS.p5-DBI+=  p5-DBI>=1.37

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
