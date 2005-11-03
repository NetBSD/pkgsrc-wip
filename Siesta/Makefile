# $NetBSD: Makefile,v 1.5 2005/11/03 12:56:10 rillig Exp $
#

DISTNAME=	Siesta-0.65
CATEGORIES=	mail
MASTER_SITES=	http://siesta.unixbeard.net/releases/

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://siesta.unixbeard.net/
COMMENT=	Siesta Mailing List Manager

DEPENDS+=	p5-Module-Build-[0-9]*:../../devel/p5-Module-Build

USE_TOOLS+=	perl:run

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
