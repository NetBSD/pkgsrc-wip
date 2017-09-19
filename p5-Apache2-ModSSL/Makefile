# $NetBSD: Makefile,v 1.5 2014/07/19 14:26:33 thomasklausner Exp $

DISTNAME=	Apache2-ModSSL-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Apache2-ModSSL/
COMMENT=	Perl Interface to mod_ssl functions

DEPENDS+=	p5-Net-SSLeay-[0-9]*:../../security/p5-Net-SSLeay


PERL5_PACKLIST=	auto/Apache2/ModSSL/.packlist

.include "../../lang/perl5/module.mk"
.include "../../www/ap2-perl/buildlink3.mk"
.include "../../mk/apache.mk"
.include "../../mk/bsd.pkg.mk"
