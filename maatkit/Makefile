# $NetBSD: Makefile,v 1.2 2011/03/19 14:42:23 genolopolis Exp $
#

DISTNAME=	maatkit-7332
PKGREVISION=    1
CATEGORIES=	wip
MASTER_SITES=	http://maatkit.googlecode.com/files/

MAINTAINER=	msporleder@gmail.com
HOMEPAGE=	http://code.google.com/p/maatkit/downloads/
COMMENT=	Advanced command-line tools for open-source databases (MySQL)
LICENSE=        gnu-gpl-v2

USE_TOOLS+=     perl
PKG_DESTDIR_SUPPORT=	user-destdir

REPLACE_PERL+=          bin/*

DEPENDS+=       p5-DBD-mysql:../../databases/p5-DBD-mysql
DEPENDS+=       p5-Time-HiRes:../../time/p5-Time-HiRes

do-configure:
	cd ${WRKSRC} && perl Makefile.PL INSTALL_BASE=${PREFIX}

do-post-build:
	find ${WRKSRC} -name "perllocal.pod" -exec rm {} \;

.include "../../mk/bsd.pkg.mk"
.include "../../lang/perl5/buildlink3.mk"
