# $NetBSD: Makefile,v 1.4 2013/11/24 10:00:21 thomasklausner Exp $

DISTNAME=	IO-Lambda-1.26
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/K/KA/KARASIK/

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	http://search.cpan.org/dist/IO-Lambda/
COMMENT=	Non-blocking I/O in lambda style
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Net-DNS-[0-9]*:../../net/p5-Net-DNS
DEPENDS+=	p5-Sub-Name-[0-9]*:../../devel/p5-Sub-Name
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	p5-HTTP-Message-[0-9]*:../../www/p5-HTTP-Message

PERL5_PACKLIST=	auto/IO/Lambda/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
