# $NetBSD: Makefile,v 1.1.1.1 2007/11/25 03:37:30 philnelson Exp $

DISTNAME=		Net-Z3950-ZOOM-1.20
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MI/MIRK/}

MAINTAINER=		phil@cs.wwu.edu
HOMEPAGE=		http://search.cpan.org/~mirk/Net-Z3950-ZOOM-1.20
COMMENT=		Perl extension for talking to Z39.50 servers

#PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=     p5-Event>=1.06:../../devel/p5-Event
DEPENDS+=     p5-MARC-Record>=2.0.0:../../wip/p5-MARC-Record


PERL5_PACKLIST=	auto/Net/Z3950/ZOOM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../net/yaz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
