# $NetBSD: Makefile,v 1.7 2012/11/25 23:32:07 othyro Exp $
#

DISTNAME=	Siesta-0.66
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/R/RC/RCLAMP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://siesta.unixbeard.net/
COMMENT=	Siesta Mailing List Manager

BROKEN=		"Configure script needs special handling."

DEPENDS+=	p5-Module-Build-[0-9]*:../../devel/p5-Module-Build

USE_TOOLS+=	perl:run

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
