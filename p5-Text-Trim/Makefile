# $NetBSD: Makefile,v 1.3 2012/10/04 19:12:00 asau Exp $

DISTNAME=	Text-Trim-1.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	tonnerre@bsdprojects.net
HOMEPAGE=	https://metacpan.org/release/Text-Trim
COMMENT=	Extract the structure of a quoted mail message
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Text/Trim/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
