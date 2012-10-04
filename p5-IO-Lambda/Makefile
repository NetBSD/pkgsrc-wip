# $NetBSD: Makefile,v 1.2 2012/10/04 10:45:29 asau Exp $
#

DISTNAME=	IO-Lambda-1.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/K/KA/KARASIK/

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://search.cpan.org/dist/IO-Lambda/
COMMENT=	Non-blocking I/O in lambda style
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Net-DNS>=0:../../net/p5-Net-DNS
DEPENDS+=	p5-Storable>=0:../../devel/p5-Storable
DEPENDS+=	p5-Sub-Name>=0:../../devel/p5-Sub-Name
DEPENDS+=	p5-Time-HiRes>=0:../../time/p5-Time-HiRes
DEPENDS+=	p5-URI>=0:../../www/p5-URI
DEPENDS+=	p5-IO-Socket-SSL>=0:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-DBI>=0:../../databases/p5-DBI

PERL5_PACKLIST=	auto/IO/Lambda/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
