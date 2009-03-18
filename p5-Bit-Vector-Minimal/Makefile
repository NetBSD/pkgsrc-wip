# $NetBSD: Makefile,v 1.3 2009/03/18 12:19:12 cheusov Exp $

DISTNAME=	Bit-Vector-Minimal-1.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Bit/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Bit-Vector-Minimal/
COMMENT=	"Object-oriented wrapper around Perl's vec()"

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Bit/Vector/Minimal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
