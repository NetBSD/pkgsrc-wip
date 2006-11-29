# $NetBSD: Makefile,v 1.3 2006/11/29 14:51:05 cheusov Exp $
#

DISTNAME=		txt2html-2.44
CATEGORIES=		converters www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=txt2html/}

MAINTAINER=		cheusov@tut.by
HOMEPAGE=		http://txt2html.sourceforge.net/
COMMENT=		Plain text to HTML convertor

USE_TOOLS+=		perl:run
PKG_INSTALLATION_TYPES= overwrite pkgviews
REPLACE_PERL=		scripts/txt2html
NO_BUILD=		yes

PERL5_CONFIGURE=	yes
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTML/TextToHTML/.packlist

DEPENDS+=		p5-Getopt-Long-[0-9]*:../../devel/p5-Getopt-Long
DEPENDS+=		p5-AppConfig-Std-[0-9]*:../../wip/p5-AppConfig-Std

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
