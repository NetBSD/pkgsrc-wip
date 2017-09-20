# $NetBSD: Makefile,v 1.4 2014/10/09 14:06:29 thomasklausner Exp $

DISTNAME=	POSIX-strptime-0.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POSIX/}

MAINTAINER=	tonnerre@thebsh.sygroup.ch
HOMEPAGE=	http://search.cpan.org/dist/POSIX-strptime/
COMMENT=	Perl module for the POSIX strptime function
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XSLoader-[0-9]*:../../devel/p5-XSLoader

USE_LANGUAGES=	c

PERL5_PACKLIST=		auto/POSIX/strptime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
