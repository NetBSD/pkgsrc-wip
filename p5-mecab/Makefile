# $NetBSD: Makefile,v 1.10 2007/05/09 13:21:10 obache Exp $
#

.include "../../wip/mecab/Makefile.common"

DISTNAME=		mecab-perl-${MECAB_VERSION}
PKGNAME=		p5-mecab-${MECAB_VERSION}
CATEGORIES+=		perl5

COMMENT=		MeCab perl module

PERL5_CONFIGURE=	yes
USE_LANGUAGES=		c++

PERL5_PACKLIST=		auto/MeCab/.packlist
REPLACE_PERL+=		test.pl

.include "../../wip/mecab/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
