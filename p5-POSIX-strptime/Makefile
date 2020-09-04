# $NetBSD: Makefile,v 1.4 2014/10/09 14:06:29 thomasklausner Exp $

DISTNAME=	POSIX-strptime-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POSIX/}

MAINTAINER=	tonnerre@thebsh.sygroup.ch
HOMEPAGE=	https://metacpan.org/release/POSIX-strptime
COMMENT=	Perl module for the POSIX strptime function
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c

PERL5_PACKLIST=		auto/POSIX/strptime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
