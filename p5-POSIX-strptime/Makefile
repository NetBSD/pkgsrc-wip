# $NetBSD: Makefile,v 1.2 2012/02/17 10:08:42 jgoamakf Exp $

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

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
