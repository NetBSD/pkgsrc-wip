# $NetBSD: Makefile,v 1.1 2006/11/29 10:20:55 cheusov Exp $
#

DISTNAME=		txt2html-2.44
CATEGORIES=		converters www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=txt2html/}

MAINTAINER=		cheusov@tut.by
HOMEPAGE=		http://txt2html.sourceforge.net/
COMMENT=		Plain text to HTML convertor

USE_TOOLS+=		perl:run
REPLACE_PERL=		scripts/txt2html
PERL5_CONFIGURE=	yes
PERL5_MODULE_TYPE=	Module::Build

DEPENDS+=		p5-Getopt-Long-[0-9]*:../../devel/p5-Getopt-Long

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
