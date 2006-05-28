# $NetBSD: Makefile,v 1.1.1.1 2006/05/28 17:28:23 gizm00 Exp $

DISTNAME=	Spread-3.17.3-1.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/J/JE/JESUS/

MAINTAINER=	gizm0@inbox.lv
COMMENT=	Perl5 module interface to Spread network utilities

PERL5_PACKLIST=		auto/Spread/.packlist

.include "../../net/spread/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
