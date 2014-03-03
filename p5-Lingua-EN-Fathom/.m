# $NetBSD: .m,v 1.1 2014/03/03 00:56:35 othyro Exp $

DISTNAME=	Lingua-EN-Fathom-1.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}
#http://search.cpan.org/CPAN/authors/id/K/KI/KIMRYAN/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~kimryan/Lingua-EN-Fathom-1.15/
COMMENT=	Measure readability of English text
LICENSE=	artistic AND gnu-gpl-v1

# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
