# $NetBSD: Makefile,v 1.2 2004/08/08 22:51:09 kristerw Exp $

DISTNAME=	DateTime-Locale-0.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://datetime.perl.org/
COMMENT=	Localization data for p5-DateTime

DEPENDS+=	p5-Module-Build-[0-9]*:../../devel/p5-Module-Build

USE_BUILDLINK3=	YES

.include "../../wip/p5-DateTime/plist.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
