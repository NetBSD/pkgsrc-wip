# $NetBSD: Makefile,v 1.3 2014/05/24 09:49:32 obache Exp $
#

.include "../../wip/marisa/Makefile.common"

PKGNAME=	p5-${DISTNAME}
CATEGORIES+=	perl

COMMENT=	MARISA perl module

USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	bindings/perl

PERL5_PACKLIST=		auto/marisa/.packlist

post-extract:
	${RM} ${WRKSRC}/bindings/perl/sample.pl

BUILDLINK_API_DEPENDS.marisa+=	marisa>=${PKGVERSION_NOREV}
.include "../../wip/marisa/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
