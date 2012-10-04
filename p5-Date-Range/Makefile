# $NetBSD: Makefile,v 1.7 2012/10/04 10:45:26 asau Exp $

DISTNAME=	Date-Range-1.40
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	http://search.cpan.org/dist/Date-Range/
COMMENT=	Date::Range - deal with a range of dates

DEPENDS+=	p5-Date-Simple>=0.03:../../devel/p5-Date-Simple
BUILD_DEPENDS+=	{perl>=5.7.3,p5-Test-Simple>=0.4}:../../devel/p5-Test-Simple

PKG_DESTDIR_SUPPORT=	none

USE_LANGUAGES=	# empty

PERL5_PACKLIST=	auto/Date/Range/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
