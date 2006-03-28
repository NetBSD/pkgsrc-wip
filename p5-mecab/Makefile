# $NetBSD: Makefile,v 1.2 2006/03/28 06:58:05 obache Exp $
#

.include "../../wip/mecab/Makefile.common"

DISTNAME=		mecab-perl-${MECAB_VERSION}
PKGNAME=		p5-mecab-${MECAB_VERSION}
CATEGORIES=		japanese textproc perl5
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE_JP:=mecab/19467/}

MAINTAINER=		obata@lins.jp
HOMEPAGE=		http://mecab.sourceforge.jp/
COMMENT=		MeCab perl module

PERL5_CONFIGURE=	yes
USE_LANGUAGES+=		c++
USE_TOOLS+=		perl:run

PERL5_PACKLIST=		auto/MeCab/.packlist
REPLACE_PERL+=		test.pl

.include "../../wip/mecab/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
