# $NetBSD: Makefile,v 1.4 2003/08/29 10:31:24 thomasklausner Exp $
#

DISTNAME=	Unicode-String-2.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Unicode/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.unicode.org/
COMMENT=	Perl5 modules to handle various Unicode issues

DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64

USE_BUILDLINK2=	YES

PERL5_PACKLIST=         ${PERL5_SITEARCH}/auto/Unicode/String/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
