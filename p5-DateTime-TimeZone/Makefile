# $NetBSD: Makefile,v 1.4 2004/05/11 07:05:36 cubidou Exp $

DISTNAME=	DateTime-TimeZone-0.2601
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-TimeZone/
COMMENT=	Perl module to handle time zone manipulation

DEPENDS+=	p5-Class-Singleton-[0-9]*:../../wip/p5-Class-Singleton
DEPENDS+=	p5-Module-Build-[0-9]*:../../devel/p5-Module-Build
DEPENDS+=	p5-Params-Validate-[0-9]*:../../devel/p5-Params-Validate

USE_BUILDLINK3=	YES

.include "../../wip/p5-DateTime/plist.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
