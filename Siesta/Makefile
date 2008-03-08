# $NetBSD: Makefile,v 1.6 2008/03/08 15:32:55 hoka_adam Exp $
#

DISTNAME=	Siesta-0.66
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/R/RC/RCLAMP/}

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://siesta.unixbeard.net/
COMMENT=	Siesta Mailing List Manager

BROKEN=		"Configure script needs special handling."

DEPENDS+=	p5-Module-Build-[0-9]*:../../devel/p5-Module-Build

USE_TOOLS+=	perl:run

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
