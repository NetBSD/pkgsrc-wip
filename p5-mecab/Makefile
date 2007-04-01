# $NetBSD: Makefile,v 1.9 2007/04/01 02:19:13 obache Exp $
#

.include "../../wip/mecab/Makefile.common"

DISTNAME=		mecab-perl-${MECAB_VERSION}
PKGNAME=		p5-mecab-${MECAB_VERSION}
CATEGORIES=		japanese textproc perl5
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mecab/}

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://mecab.sourceforge.net/
COMMENT=		MeCab perl module

PERL5_CONFIGURE=	yes
USE_LANGUAGES=		c++

PERL5_PACKLIST=		auto/MeCab/.packlist
REPLACE_PERL+=		test.pl

.include "../../wip/mecab/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
