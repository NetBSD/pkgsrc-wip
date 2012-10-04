# $NetBSD: Makefile,v 1.3 2012/10/04 19:11:57 asau Exp $

DISTNAME=	POSIX-strptime-0.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=POSIX/}

MAINTAINER=	tonnerre@thebsh.sygroup.ch
HOMEPAGE=	http://search.cpan.org/dist/POSIX-strptime/
COMMENT=	Perl module for the POSIX strptime function
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XSLoader-[0-9]*:../../devel/p5-XSLoader

PKG_INSTALLATION_TYPES=	overwrite pkgviews
USE_LANGUAGES=	c

PERL5_PACKLIST=		auto/POSIX/strptime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
