# $NetBSD: Makefile,v 1.5 2011/04/07 11:37:06 genolopolis Exp $
#

DISTNAME=	maatkit-7332
PKGREVISION=	2
CATEGORIES=	wip
MASTER_SITES=	http://maatkit.googlecode.com/files/

MAINTAINER=	msporleder@gmail.com
HOMEPAGE=	http://code.google.com/p/maatkit/downloads/
COMMENT=	Advanced command-line tools for open-source databases (MySQL)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl
PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_PERL+=	bin/*

DEPENDS+=	p5-DBD-mysql:../../databases/p5-DBD-mysql
DEPENDS+=	p5-Time-HiRes:../../time/p5-Time-HiRes

PERL5_PACKLIST=	auto/maatkit/.packlist
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
